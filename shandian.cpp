#pragma comment(lib,"Winmm.lib")
#include <stdio.h>
#include <graphics.h>
#include <time.h>
#include <math.h>
#include <windows.h>
#include "shandian.h"
void poi(int t,int lei)
{

	//PlaySound("E:\\0\\����\\����\\music.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	//srand((unsigned)time(NULL));													// �����������
	//setorigin(0, 480);																// ��������ԭ�������½�
	//setaspectratio(1, -1);															// ��������y�ᷴ��
												   // ���ñ���ɫ
	int seedtime, Xpoint;//time, 																// ����Ҽ��˳�����
	/*do {
		seedtime = rand() % 500;
	} while (seedtime <= 150);*/
	//char d[255] = { '\0' };

	//time = rand() % 3000 + seedtime;
	
		Xpoint = rand() % 500 + 50;													// ���������ֵĺ�����
		//Sleep(time);																// �ȴ�һ�����ʱ�䣬��������
		Light(Xpoint);																// ������
	
}
void Light(int x)
{
	int RanTimes = rand() % 2 + 1;//CirJudgeZero(3, 0);												// ����Ƿ����˫������
	int EndPoi;																		// ���ڼ�¼������յ�
	for (int i = 0; i < RanTimes; i++)
	{
		int Xpoint = x, Ypoint = 0;
		EndPoi = rand() % 120 + 120;	// ���������յ�
		//setlinestyle(PS_ENDCAP_ROUND | PS_SOLID, 2);						// ����������ʽ(�߶ζϵ�Ϊƽ��ʵ�ߡ����)		
		setlinecolor(RGB(125, 250, 255));// ����������ɫ
		while (Ypoint <= EndPoi)													// �ж��Ƿ񵽴��յ� && ����ÿ��С�߶�
		{
			int Dis = rand() % 20;													// �������ÿ�εĳ���
			int Ang1 = rand() % 120 - 60;											// �������ĽǶ�(x��)
			int Ang2 = rand() % 120 - 60;											// �������ĽǶ�(y��)
			int NextX = Xpoint + (int)(Dis * sin(Ang1 * PI / 180));					// ��������̵����һ��(x��)
			int NextY = Ypoint + (int)(Dis * cos(Ang2 * PI / 180));					// ��������̵����һ��(y��)			
			line(Xpoint, Ypoint, NextX, NextY);										// ��������
			Xpoint = NextX;															// ���˵㸳ֵ����ʼ��(x��)
			Ypoint = NextY;															// ���˵㸳ֵ����ʼ��(y��)
			//Sleep((rand() % 100) > 66 ? 1 : 0);										// ����ͣ��ʱ��
		}
	}
	//cleardevice();
}
//int CirJudgeZero(int index1, int index2)												// ѭ����������õ�һ��������������index1��index2��ʾ�����Χ��ָ��
//{
//	int rec = 0;																	// ���ڴ��ݵķ����������ʼ��Ϊ0
//	while (rec == 0)
//	{
//		rec = rand() % index1 + index2;
//	}
//	return rec;
//}