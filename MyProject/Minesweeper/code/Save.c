﻿#include"Save.h"

extern int lastFlag;
extern int g_coveredBlank;
extern int g_nowGameLevel;
extern char g_map[MAXROW + BOUNDARY_NUM][MAXCOL + BOUNDARY_NUM];
extern char g_tag[MAXROW + BOUNDARY_NUM][MAXCOL + BOUNDARY_NUM];

char g_nullList[LISTLINES][SAVECOLS - BOUNDARY_SIZE_CHAR + 1];
char g_saveList[MAXSAVENUM][SAVECOLS - BOUNDARY_SIZE_CHAR + 1];

void InitNullList()
{
	int num = 0;

	while (num < LISTLINES / 2 - 1)
	{
		strcat(g_nullList[num++], "                                    ");
	}
	strcat(g_nullList[num++], "           存档页面不存在           ");
	strcat(g_nullList[num++], "         请检查 Save 文件夹         ");
	while (num != LISTLINES)
	{
		strcat(g_nullList[num++], "                                    ");
	}
}

void SaveList(int flag)
{
	time_t saveTime;
	char tmp[SAVECOLS] = "    ";
	char level[4][10] = { " 初级  ", " 中级  ", " 高级  ", "自定义 " };
	FILE *pf = fopen("..\\Save\\saveList.txt", "w");

	if (!pf)
	{
		return;
	}
	time(&saveTime); // 获取当前时间
	strcat(tmp, level[g_nowGameLevel]);
	// ctime 返回的字符串自带换行符，使用 strncat 去除换行符
	strncat(tmp, ctime(&saveTime), 24); // ctime(&saveTime); 转换为当地时间
	strcat(tmp, " ");
	strcpy(g_saveList[flag], tmp);
	for (int i = 0; i <= LASTSAVE; i++)
	{
		fputs(g_saveList[i], pf);
		fputc('\n', pf);
	}
	fclose(pf);
}

int LoadList()
{
	int num = FIRSTSAVE;
	FILE *pf = fopen("..\\Save\\saveList.txt", "r");

	if (!pf)
	{
		while (num < LASTSAVE)
		{
			strcat(g_saveList[num], g_nullList[num % LISTLINES]);
			num++;
		}
		return ERROR;
	}
	while (!feof(pf))
	{
		fgets(g_saveList[num++], SAVECOLS - BOUNDARY_SIZE_CHAR + 1, pf);
		fgetc(pf);
	}
	fclose(pf);

	return SUCCESS;
}

void SaveData(int row, int col, int mineLeast, int flag)
{
	char filename[100] = "..\\Save\\save";
	char num[5];
	FILE *pf;

	_itoa(flag + 1, num, 10);
	if (flag == TMP)
	{
		pf = fopen("..\\Save\\tmp.data", "wb");
	}
	else
	{
		strcat(filename, num);
		strcat(filename, ".data");
		pf = fopen(filename, "wb");
	}
	if (!pf)
	{
		return;
	}

	fwrite(&row, sizeof(int), 1, pf);
	fwrite(&col, sizeof(int), 1, pf);
	fwrite(&mineLeast, sizeof(int), 1, pf);
	fwrite(&g_nowGameLevel, sizeof(int), 1, pf);
	fwrite(&g_coveredBlank, sizeof(int), 1, pf);
	for (int i = 1; i <= row; i++)
	{
		fwrite(&g_map[i][1], sizeof(char), col, pf);
		fwrite(&g_tag[i][1], sizeof(char), col, pf);
	}
	fclose(pf);
}

int LoadData(int *row, int *col, int *mineLeast, int flag)
{
	char filename[100] = "..\\Save\\save";
	char num[5];
	FILE *pf;

	_itoa(flag + 1, num, 10);
	if (flag == TMP)
	{
		pf = fopen("..\\Save\\tmp.data", "rb");
	}
	else
	{
		strcat(filename, num);
		strcat(filename, ".data");
		pf = fopen(filename, "rb");
	}

	if (!pf)
	{
		Gotoxy(0, 13);
		printf("　　　　　      读档失败");
		int tmp1, tmp2;
		GetMouse(&tmp1, &tmp2);
		return ERROR;
	}
	fread(row, sizeof(int), 1, pf);
	fread(col, sizeof(int), 1, pf);
	fread(mineLeast, sizeof(int), 1, pf);
	fread(&g_nowGameLevel, sizeof(int), 1, pf);
	fread(&g_coveredBlank, sizeof(int), 1, pf);
	for (int i = 1; i <= *row; i++)
	{
		fread(&g_map[i][1], sizeof(char), (unsigned)*col, pf);
		fread(&g_tag[i][1], sizeof(char), (unsigned)*col, pf);
	}
	fclose(pf);
	Gotoxy(0, 13);
	printf("　　　　　      读档成功");
	return SUCCESS;
}

void SaveOrLoad(int *row, int *col, int *mineLeast, int isSave)
{
	int jump, input;
	int flag = FIRSTSAVE;
	int state = CONTINUE;
	int lines = 0, tmp = 0;

	SavePage(flag);
	while (!state)
	{
		input = GetMouse(&lines, &tmp);
		Gotoxy(3, 1 + flag % LISTLINES);
		printf("  ");
		if ((input == LEFTCLICK || input == RIGHTCLICK) && lines >= 1 && lines <= LISTLINES)
		{
			flag = lines - 1;
		}
		Gotoxy(0, 12);
		switch (input)
		{
		case UP:
		case ARROW_UP:
			flag--;
			if (flag < FIRSTSAVE)
			{
				flag = LASTSAVE;
			}
			break;
		case DOWN:
		case ARROW_DOWN:
			flag++;
			if (flag > LASTSAVE)
			{
				flag = FIRSTSAVE;
			}
			break;
		case LEFT:
		case ARROW_LEFT:
			flag -= LISTLINES;
			break;
		case RIGHT:
		case ARROW_RIGHT:
			flag += LISTLINES;
			break;
		case JUMP:
			printf("跳转页码：> ");
			lastFlag = -99;
			while (!scanf("%d", &jump));
			if (jump > 0)
			{
				flag = (jump - 1) * LISTLINES + flag % LISTLINES;
			}
			else
			{
				flag = jump * LISTLINES - flag % LISTLINES;
			}
			break;
		case 'C':
			if (isSave)
			{
				break;
			}
			flag = TMP; // 临时存档
		case LEFTCLICK:
		case ENTER:
			state = OVER;
			break;
		case ESC:
			lastFlag = 0;
			return;
		default:
			break;
		}
		if (flag > LASTSAVE)
		{
			flag = flag % LISTLINES;
		}
		else if (flag < FIRSTSAVE && (!isSave && flag != TMP))
		{
			while (flag < LASTSAVE)
			{
				flag += LISTLINES;
			}
			flag -= LISTLINES;
		}
		if (flag != TMP)
		{
			SavePage(flag);
		}
	}
	lastFlag = -100;
	if (isSave)
	{
		SaveList(flag);
		SaveData(*row, *col, *mineLeast, flag);
		Gotoxy(0, 13);
		printf("　　　　　      保存成功");
		getchar();
	}
	else if (LoadData(row, col, mineLeast, flag))
	{
		Game(*row, *col, *mineLeast, FALSE);
	}
}