#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define N 4//ʤ����������������������ʱʤ��
#define ROW 10//����
#define COL 10//����
#define PLAYER '*'//��ҵ�����
#define COMPUTER '#'//���Ե�����
#define CONTINUE 'C'//���ں������أ���ʾ����
#define END 'Q'//��ʾ��Ϸ����

void Menu();//��ӡ�˵�
void Play();//��Ϸ��������Ҫ���ڵ��ö���ĸ��ֺ���
void Display(char board[ROW][COL], int row, int col);//��ӡ����
void PlayerMove(char board[ROW][COL], int row, int col);//�������
void ComputerMove(char board[ROW][COL], int row, int col);//��������
char CheckWin(char board[ROW][COL], int row, int col);//�ж�ʤ�������Ƿ�����

