#pragma comment(lib,"Winmm.lib")
#include <stdio.h>
#include <graphics.h>
#include <time.h>
#include <math.h>
#include <windows.h>
#include "shandian.h"
void poi(int t,int lei)
{

	//PlaySound("E:\\0\\闪电\\闪电\\music.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	//srand((unsigned)time(NULL));													// 设置随机种子
	//setorigin(0, 480);																// 设置坐标原点在左下角
	//setaspectratio(1, -1);															// 设置坐标y轴反向
												   // 重置背景色
	int seedtime, Xpoint;//time, 																// 鼠标右键退出程序
	/*do {
		seedtime = rand() % 500;
	} while (seedtime <= 150);*/
	//char d[255] = { '\0' };

	//time = rand() % 3000 + seedtime;
	
		Xpoint = rand() % 500 + 50;													// 随机闪电出现的横坐标
		//Sleep(time);																// 等待一段随机时间，出现闪电
		Light(Xpoint);																// 画闪电
	
}
void Light(int x)
{
	int RanTimes = rand() % 2 + 1;//CirJudgeZero(3, 0);												// 随机是否出现双重闪电
	int EndPoi;																		// 用于记录闪电的终点
	for (int i = 0; i < RanTimes; i++)
	{
		int Xpoint = x, Ypoint = 0;
		EndPoi = rand() % 120 + 120;	// 随机闪电的终点
		//setlinestyle(PS_ENDCAP_ROUND | PS_SOLID, 2);						// 设置闪电样式(线段断点为平、实线、宽度)		
		setlinecolor(RGB(125, 250, 255));// 设置闪电颜色
		while (Ypoint <= EndPoi)													// 判断是否到达终点 && 绘制每个小线段
		{
			int Dis = rand() % 20;													// 随机闪电每段的长度
			int Ang1 = rand() % 120 - 60;											// 随机闪电的角度(x轴)
			int Ang2 = rand() % 120 - 60;											// 随机闪电的角度(y轴)
			int NextX = Xpoint + (int)(Dis * sin(Ang1 * PI / 180));					// 计算闪电短点的下一点(x轴)
			int NextY = Ypoint + (int)(Dis * cos(Ang2 * PI / 180));					// 计算闪电短点的下一点(y轴)			
			line(Xpoint, Ypoint, NextX, NextY);										// 绘制闪电
			Xpoint = NextX;															// 将端点赋值给初始点(x轴)
			Ypoint = NextY;															// 将端点赋值给初始点(y轴)
			//Sleep((rand() % 100) > 66 ? 1 : 0);										// 设置停滞时间
		}
	}
	//cleardevice();
}
//int CirJudgeZero(int index1, int index2)												// 循环随机数，得到一个非零的随机数，index1、index2表示随机范围的指数
//{
//	int rec = 0;																	// 用于传递的非零参数，初始化为0
//	while (rec == 0)
//	{
//		rec = rand() % index1 + index2;
//	}
//	return rec;
//}