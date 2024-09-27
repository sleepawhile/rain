#pragma once
#include<stdio.h>
#include<graphics.h>
#define MAX_Intensity 1000
typedef COLORREF COLOR;
//点的结构体
struct Pixel
{
	int x;
	int y;
};
struct RainDrop
{
	Pixel begin;
	Pixel velocity;//雨滴的速度向量
	int r, g, b;//雨滴颜色的红，绿，蓝三通道；
	COLOR color;//雨滴颜色；
	RainDrop* next;
};
struct Rain
{
	RainDrop raindrop;
	RainDrop* rear;//存最后一个结点位置；
	int Intensity;
};

void initrain_1(Rain* r, int intensity, int x1, int y1, int x2, int y2,int wind);
void initrain(Rain* r);
void randerrain(Rain* r, int intensity, int x1, int y1, int x2, int y2, int wind, Rain* q, int watery1, int watery2);