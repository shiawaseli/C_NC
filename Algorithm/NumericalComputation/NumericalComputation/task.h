#pragma once

#include <iostream>
#include <valarray>

using namespace std;

enum
{
	SETGAUSS, MAGAUSS, MANETON,
};

extern void menu();
extern void magauss();
extern void manewton();
