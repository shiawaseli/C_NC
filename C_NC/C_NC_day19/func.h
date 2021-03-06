#pragma once

#ifndef _INC_FUNC

#define _CRT_SECURE_NO_WARNINGS 1
#include"func.h"
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct Mail
{
	char sex[10];
	char tele[12];
	char addr[50];
	char name[50];
	int age;
}MailMSG;

#define MANNUM 3
#define TRUE 1
#define ERROR 0

typedef struct MailList
{
	MailMSG *man;
	int num;
}MailList;

MailList g_mail;

enum OPTION
{
	EXIT_SYS,
	ADD_MSG,
	DELETE_MSG,
	SEARCH_MSG,
	CHANGE_MSG,
	OUTPUT_MSG,
};

int Menu();
void LoadMail();
void SaveMail();
void InsertMail();
int DeleteMail(int id);
int SearchMail(char *p);
int ChangeMail(int id);
void OutputMail();

#endif