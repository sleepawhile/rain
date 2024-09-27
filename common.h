#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<stdio.h>
#include<easyx.h>
#include <time.h>
#include <conio.h>
#include<stdio.h>
#define PIC_HEIGHT 600
#define PIC_WIDTH 800
//int RAINS=100;
//int WIND=-20;
//int LEI=1;
//int RANDM=0;
//int CLOUD=15;
struct Bar {
	int x;
	int y;
	int x1;
	int y1;
	char c;
	bool fg;
};
struct rects {
	int x;
	int y;
	int x1;
	int y1;
};
struct slip {
	int x;
	int y;
	int x1;
	int y1;
};
void initBar(Bar* bar);

void putBar(Bar* bar);

void controlBar(Bar* bar, rects* ret, ExMessage msg, bool flag, int* rains, int* wind, int* lei, int* randm, int* cloud);

void initrets(rects* ret);

void putWENZI(rects* ret, int* rains, int* wind, int* lei, int* randm, int* cloud);



