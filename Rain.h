#pragma once
#include<stdio.h>
#include<graphics.h>
#define MAX_Intensity 1000
typedef COLORREF COLOR;
//��Ľṹ��
struct Pixel
{
	int x;
	int y;
};
struct RainDrop
{
	Pixel begin;
	Pixel velocity;//��ε��ٶ�����
	int r, g, b;//�����ɫ�ĺ죬�̣�����ͨ����
	COLOR color;//�����ɫ��
	RainDrop* next;
};
struct Rain
{
	RainDrop raindrop;
	RainDrop* rear;//�����һ�����λ�ã�
	int Intensity;
};

void initrain_1(Rain* r, int intensity, int x1, int y1, int x2, int y2,int wind);
void initrain(Rain* r);
void randerrain(Rain* r, int intensity, int x1, int y1, int x2, int y2, int wind, Rain* q, int watery1, int watery2);