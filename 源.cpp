#include<easyx.h>
#include<stdio.h>
#include"Ripple.h"
#include"shandian.h"
#include"common.h"
#include"cloud.h"
#include<time.h>
TCHAR cmd[256];//ÃüÁîÐÐ

int main()
{
	IMAGE img;
	IMAGE dest_img(PIC_WIDTH, PIC_HEIGHT);
	Ripple ripple;
	Rain rain, q;
	rects ret[5];
	Bar bar;
	Clouds clouds;
	init_clouds(&clouds);
	int intensity = 100;
	int wind = -20;
	int lei = 1;
	int cloude = 15;
	int flag = 1;
	int arrivemaxwind = 0;
	int arriveminwind = 1;
	int arrivemaxintensity = 0;
	int arriveminintensity = 1;
	initgraph(PIC_WIDTH, PIC_HEIGHT);
	initrets(ret);
	initBar(&bar);
	putBar(&bar);
	ExMessage msg;
	loadimage(&img, "scenery-horse-silhouette-walking-lake-during-nighttime.jpg", 800, 600, true);
	initripple(&ripple, &img, &dest_img);
	initrain_1(&rain, 1000, 0, 0, 800, 600, -100);
	initrain(&q);
	setbkmode(TRANSPARENT);
	settextcolor(RED);

	mciSendString("open ÒôÆµ×ªÂë_°®¸øÍø_aigei_com-¼ô¼­-20221219112054.mp3", 0, 0, 0);
	mciSendString("play ÒôÆµ×ªÂë_°®¸øÍø_aigei_com-¼ô¼­-20221219112054.mp3 repeat", 0, 0, 0);
	mciSendString("open music1.mp3 alias m", NULL, 0, NULL);
	mciSendString("play m repeat", NULL, 0, NULL);
	time_t t1= time(NULL);
	BeginBatchDraw();
	while (1)
	{
		wsprintf(cmd, "setaudio %s volume to %d", "ÒôÆµ×ªÂë_°®¸øÍø_aigei_com-¼ô¼­-20221219112054.mp3", rain.Intensity);
		mciSendString(cmd, NULL, 0, NULL);

		
		formripple(&ripple, &img, &q);
		randerripple(&ripple, &img, &dest_img);
		time_t t2 = time(NULL);
		int t = difftime(t2, t1);
		if (!flag)
		{
			randerrain(&rain, intensity, 0, 0, 800, 600, wind * 10, &q, (int)600 * 0.589, 600);
			if (t > 4 - lei)
			{
				poi(t, lei);
				t1 = time(NULL);
			}
			draw_clouds(&clouds, cloude, 0, 0, PIC_WIDTH, 40,wind);
			if (arriveminintensity)
			{
				intensity++;
				if (intensity >= 1000)
				{
					arrivemaxintensity = 1;
					arriveminintensity = 0;
				}
			}
			if (arrivemaxintensity)
			{
				intensity--;
				if (intensity<= 100)
				{
					arrivemaxintensity = 0;
					arriveminintensity = 1;
				}
			}
			if (arriveminwind&&(intensity-100)%5==0)
			{
				wind++;
				if (wind >= 10)
				{
					arrivemaxwind = 1;
					arriveminwind = 0;
				}
			}
			if (arrivemaxwind&&(intensity - 100) % 5 == 0)
			{
				wind--;
				if (wind <= -10)
				{
					arrivemaxwind = 0;
					arriveminwind = 1;
				}
			}
		}
		else {
			randerrain(&rain,intensity, 0, 0, 800, 600, wind * 10, &q, (int)600 * 0.589, 600);
			if (t > 4 - lei)
			{
				poi(t, lei);
				t1 = time(NULL);
			}
			draw_clouds(&clouds,cloude, 0, 0, PIC_WIDTH, 40, wind);
		}
		bool flag1 = peekmessage(&msg);
		controlBar(&bar, ret, msg, flag1, &intensity, &wind, &lei, &flag, &cloude);
		FlushBatchDraw();
		cleardevice();
		setbkcolor(RGB(255, 255, 255));
		Sleep(20);
	}
	EndBatchDraw();
	closegraph();
}