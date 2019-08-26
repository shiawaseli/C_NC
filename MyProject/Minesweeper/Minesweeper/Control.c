#include"Control.h"

extern int g_coveredBlank;
extern char g_map[MAXROW + BOUNDARY_NUM][MAXCOL + BOUNDARY_NUM];
extern char g_tag[MAXROW + BOUNDARY_NUM][MAXCOL + BOUNDARY_NUM];

int g_gameLevel = LEVEL2;
int g_nowGameLevel = 0;

int GetKeyBoard()
{
	int flag = _getch();

	if ((signed char)flag < 0)
	{
		flag = (flag << 8) | _getch();
	}

	return flag;
}

void HideCursor()
{
	CONSOLE_CURSOR_INFO cursorInfo = { 1, 0 };

	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void Gotoxy(int x, int y)
{
	COORD pos = { x, y };
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleCursorPosition(hOut, pos);
}
void SetConsoleSize(int cols, int lines)
{
	HWND hWnd = GetConsoleWindow();
	char consoleSize[32];

	sprintf(consoleSize, "mode con cols=%d lines=%d", cols, lines);
	system(consoleSize);
	SetWindowLongPtr(hWnd, GWL_STYLE, GetWindowLong(hWnd, GWL_STYLE) & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX);
}

int GetMouse(int *row, int *col)
{
	HWND hwn;
	POINT cursor;
	RECT rectWindow;

	hwn = GetConsoleWindow();
	while (1)
	{
		GetCursorPos(&cursor);
		GetWindowRect(hwn, &rectWindow);
		if(KEY_DOWN(VK_LBUTTON) && 
			cursor.x >= rectWindow.left && cursor.x <= rectWindow.right && 
			cursor.y >= rectWindow.top && cursor.y <= rectWindow.bottom)
		{
			*row = (cursor.y - rectWindow.top - 30) / 20;
			*col = (cursor.x - rectWindow.left - 8) / 20;
			return ENTER;
		}
		else if(KEY_DOWN(VK_RBUTTON) &&
			cursor.x >= rectWindow.left && cursor.x <= rectWindow.right &&
			cursor.y >= rectWindow.top && cursor.y <= rectWindow.bottom)
		{
			*row = (cursor.y - rectWindow.top - 30) / 20;
			*col = (cursor.x - rectWindow.left - 8) / 20;
			return MINEMARK;
		}
		Sleep(100);
	}
}

void Game(int row, int col, int mine, int isFirst)
{
	Point point = { (row + 1) / 2, (col + 1) / 2 };
	char mode = MODE_KEYBOARD;
	int showPoint = TRUE, state = CONTINUE, input;
	int mineLeast = mine;
	
	MapPrint(row, col, mine, point, showPoint, isFirst);
	while (!state)
	{
		if (mode == MODE_KEYBOARD)
		{
			input = GetKeyBoard();
		}
		else if(mode == MODE_MOUSE)
		{
			input = GetMouse(&point.row, &point.col);
		}
		switch (input)
		{
		case UP:
		case ARROW_UP:
			point.row--;
			showPoint = TRUE;
			break;
		case DOWN:
		case ARROW_DOWN:
			point.row++;
			showPoint = TRUE;
			break;
		case LEFT:
		case ARROW_LEFT:
			point.col--;
			showPoint = TRUE;
			break;
		case RIGHT:
		case ARROW_RIGHT:
			point.col++;
			showPoint = TRUE;
			break;
		case MINECHECK:
			if (!isFirst)
			{
				GameState(row, col, mineLeast, MINECHECK);
				while (GetKeyBoard() != ESC);
			}
			break;
		case JUMP:
			MapJump(row, col, mineLeast, point, showPoint, isFirst);
			printf("������ת(row, col)��> ");
			while (!scanf("%d%d", &point.row, &point.col));
			showPoint = TRUE;
			break;
		case ENTER:
			if (isFirst == TRUE)
			{
				MapInit(row, col, mine, point);
				isFirst = FALSE;
			}
			if (g_map[point.row][point.col] == MINE && g_tag[point.row][point.col] != MARKED)
			{
				state = OVER;
			}
			else if (g_tag[point.row][point.col] == COVERED)
			{
				MapOpen(row, col, point.row, point.col);
			}
			else
			{
				if (OpenAround(row, col, point, mineLeast))
				{
					state = OVER;
				}
			}
			break;
		case HIDEPOINT:
			showPoint = FALSE;
			break;
		case MODE_MOUSE:
			mode = MODE_MOUSE;
			break;
		case MINEMARK:
			if (g_tag[point.row][point.col] != OPENED)
			{
				if (g_tag[point.row][point.col] == COVERED)
				{
					g_tag[point.row][point.col] = MARKED;
					mineLeast--;
				}
				else
				{
					g_tag[point.row][point.col] = COVERED;
					mineLeast++;
				}
			}
			break;
		case SAVE:
			Save(row, col, mineLeast);
			break;
		case ESC:
			SaveData(row, col, mineLeast, TMP);
			return;
		default:
			break;
		}
		if (!g_coveredBlank && !isFirst)
		{
			state = WIN;
		}
		point.row = BOUNDJUDGE(point.row, 1, row);
		point.col = BOUNDJUDGE(point.col, 1, col);
		MapPrint(row, col, mineLeast, point, showPoint, isFirst);
		showPoint = !showPoint;
	}
	GameState(row, col, mineLeast, state);

	getchar();
}

int SetLevel()
{
	int input;
	
	SetPage(g_gameLevel);
	Gotoxy(6, 13);
	printf(" �����ѡ�񡡻س���ȷ��");
	while (1)
	{
		Gotoxy(10, 6 + g_gameLevel);
		printf("��");
		input = GetKeyBoard();
		Gotoxy(10, 6 + g_gameLevel);
		printf("  ");
		switch (input)
		{
		case UP:
		case ARROW_UP:
			g_gameLevel--;
			if (g_gameLevel < LEVEL1)
			{
				g_gameLevel = FREE;
			}
			break;
		case DOWN:
		case ARROW_DOWN:
			g_gameLevel++;
			if (g_gameLevel > FREE)
			{
				g_gameLevel = LEVEL1;
			}
			break;
		case ENTER:
			return g_gameLevel;
		case ESC:
			return ESC;
		default:
			break;
		}
	}
}

void Set(int *row, int *col, int *mine)
{
	switch (SetLevel())
	{
	case LEVEL1:
		*row = 9;
		*col = 9;
		*mine = 10;
		break;
	case LEVEL2:
		*row = 16;
		*col = 16;
		*mine = 40;
		break;
	case LEVEL3:
		*row = 16;
		*col = 30;
		*mine = 99;
		break;
	case FREE:
		FreeDefine(row, col, mine);
		break;
	case ESC:
		return;
	default:
		break;
	}
}

void FreeDefine(int *row, int *col, int *mine)
{
	static int flag = DEFINEHEIGHT;
	int input, *(p[3]) = { row, col, mine }, maxMine = MAXMINE(*row, *col);

	DefinePage(*row, *col, *mine, flag);
	while (1)
	{
		Gotoxy(8, 7 + flag);
		printf("��");
		input = GetKeyBoard();
		Gotoxy(8, 7 + flag);
		printf("  ");
		switch (input)
		{
		case UP:
		case ARROW_UP:
			flag--;
			if (flag < DEFINEHEIGHT)
			{
				flag = DEFINEMINE;
			}
			break;
		case DOWN:
		case ARROW_DOWN:
			flag++;
			if (flag > DEFINEMINE)
			{
				flag = DEFINEHEIGHT;
			}
			break;
		case LEFT:
		case ARROW_LEFT:
			if (flag == DEFINEMINE)
			{
				(*mine)--;
				break;
			}
			flag ? (*col)-- : (*row)--;
			break;
		case RIGHT:
		case ARROW_RIGHT:
			if (flag == DEFINEMINE)
			{
				(*mine)++;
				break;
			}
			flag ? (*col)++ : (*row)++;
			break;
		case ENTER:
			return;
		default:
			break;
		}
		*row = BOUNDJUDGE(*row, MINROW, MAXROW);
		*col = BOUNDJUDGE(*col, MINCOL, MAXCOL);
		maxMine = MAXMINE(*row, *col);
		*mine = BOUNDJUDGE(*mine, MINMINE, maxMine);
		
		Gotoxy(20, 7 + flag);
		printf("%3d", *(p[flag]));
		Gotoxy(7, 12);
		switch (flag)
		{
		case DEFINEHEIGHT:
			printf(" ���ø߶� (��Χ9-24)  ");
			break;
		case DEFINEWIDTH:
			printf(" ���ÿ�� (��Χ9-30)  ");
			break;
		case DEFINEMINE:
			printf(" �������� (��Χ10-%d) ", maxMine);
			break;
		default:
			break;
		}
	}
}

int Welcome()
{
	static int flag = WELCOMENEWGAME;
	int input;
	char help[][15] = { "     ����   ", "    ����Ϸ  ", " ������Ϸ�Ѷ� ", "   �˳���Ϸ " };

	WelcomePage(flag);
	Gotoxy(13, 13);
	printf("%s", help[flag]);
	while (1)
	{
		Gotoxy(12, 6 + flag);
		printf("��");
		input = GetKeyBoard();
		Gotoxy(12, 6 + flag);
		printf("  ");
		switch (input)
		{
		case UP:
		case ARROW_UP:
			flag--;
			if (flag < WELCOMECONTINUE)
			{
				flag = WELCOMEEXIT;
			}
			break;
		case DOWN:
		case ARROW_DOWN:
			flag++;
			if (flag > WELCOMEEXIT)
			{
				flag = WELCOMECONTINUE;
			}
			break;
		case ENTER:
			return flag;
		default:
			break;
		}
		Gotoxy(13, 13);
		printf("%s", help[flag]);
	}
}

void GameControl()
{
	int row = INITIALROWS, col = INITIALCOLS, mine = INITIALMINES;
	int o_row, o_col, o_mine;

	HideCursor();
	SetConsoleTitle("ɨ��");
	InitNullList();
	LoadList();
	while (1)
	{
		switch (Welcome())
		{
		case GAMECONTINUE:
			Load(&o_row, &o_col, &o_mine);
			break;
		case NEWGAME:
			if (g_nowGameLevel != g_gameLevel)
			{
				g_nowGameLevel = g_gameLevel;
			}
			Game(row, col, mine, TRUE);
			break;
		case GAMESET:
			Set(&row, &col, &mine);
			break;
		case EXIT:
			return;
		default:
			break;
		}
	}
}
