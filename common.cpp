#include "common.h"

void initBar(Bar* bar)
{
	bar->x = 780;
	bar->y = 50;
	bar->x1 = 800;
	bar->y1 = 70;
	bar->fg = true;
}

void putBar(Bar* bar)
{
	RECT ct = { bar->x, bar->y, bar->x1, bar->y1};
	if (bar->fg) {
		bar->c = '<';
	}
	else {
		bar->c = '>';
	}
	drawtext(bar->c,&ct, DT_CENTER);
}


void initrets(rects* ret){
	int count = 2;
	for (int i = 0; i <= 4; i++) {
		ret[i].x = 730;
		ret[i].x1 = 780;
		ret[i].y = 20 * count - 20;
		ret[i].y1 = ret[i].y + 20;
		count += 2;	
	}
}

void putWENZI(rects* ret, int* rains, int* wind, int* lei, int* randm, int* cloud)
{
	TCHAR str0[] = _T("Óê");
	RECT ct00 = { 705,ret[0].y,730,ret[0].y1 };
	drawtext(str0, &ct00, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	char s[5];
	sprintf(s, "%d", *rains);
	RECT ct0 = { ret[0].x,ret[0].y,ret[0].x1,ret[0].y1};
	drawtext(s, &ct0, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	TCHAR str1[] = _T("·ç");
	RECT ct01 = { 705,ret[1].y,730,ret[1].y1 };
	drawtext(str1, &ct01, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	sprintf(s, "%d", *wind);
	RECT ct1 = { ret[1].x,ret[1].y,ret[1].x1,ret[1].y1 };
	drawtext(s, &ct1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	TCHAR str2[] = _T("À×");
	RECT ct02 = { 705,ret[2].y,730,ret[2].y1 };
	drawtext(str2, &ct02, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	sprintf(s, "%d", *lei);
	RECT ct2 = { ret[2].x,ret[2].y,ret[2].x1,ret[2].y1 };
	drawtext(s, &ct2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	TCHAR str3[] = _T("Ëæ»ú");
	RECT ct03 = { 695,ret[3].y,730,ret[3].y1 };
	drawtext(str3, &ct03, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	sprintf(s, "%d", *randm);
	RECT ct3 = { ret[3].x,ret[3].y,ret[3].x1,ret[3].y1 };
	drawtext(s, &ct3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	TCHAR str4[] = _T("ÔÆ");
	RECT ct04 = { 705,ret[4].y,730,ret[4].y1 };
	drawtext(str4, &ct04, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	sprintf(s, "%d", *cloud);
	RECT ct4 = { ret[4].x,ret[4].y,ret[4].x1,ret[4].y1 };
	drawtext(s, &ct4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}




void controlBar(Bar* bar, rects* ret, ExMessage msg,bool flag,int *rains,int*wind,int*lei,int*randm,int *cloud)
{
	//IMAGE img1;
	//loadimage(&img1, "³ØÌÁ.jpg", PIC_WIDTH, PIC_HEIGHT);
	if (flag  || bar->c == '<') {
		if (msg.x > 780 && msg.x < 800 && msg.y>50 && msg.y < 70&& msg.message == WM_LBUTTONDOWN) {
			bar->fg = false;
		}
		putBar(bar);
	}
	
	if (bar->c == '>')
	{
		if (flag && msg.message == WM_RBUTTONDOWN) {
			if (msg.x > 780 && msg.x < 800 && msg.y>50 && msg.y < 70) {
				bar->fg = true;
				//cleardevice();
				putBar(bar);

			}
		}
		if (flag && msg.vkcode == 0x57) {//W 
			if ( *rains <1000) {
				*rains += 100;
			}
		}
		if (flag && msg.vkcode == 0x45) {//E
			if (*rains > 100) {
				*rains -= 100;
			}
		}
		if (flag && msg.vkcode == 0x52) {//R
			if (*wind < 20) {
				*wind += 10;
			}

		}
		if (flag && msg.vkcode == 0x54) {//T
			if (*wind > -20 ) {
				*wind -= 10;
			}
		}
		if (flag && msg.vkcode == 0x53) {//S
			if ( *lei < 4) {
				*lei += 1;
			}
		}
		if (flag && msg.vkcode == 0x44) {//D
			if (*lei > 1 ) {
				*lei -= 1;
			}
		}
		if (flag && msg.vkcode == 0x46) {//F
			*randm = 1;
		}
		if (flag && msg.vkcode == 0x47) {//G
			*randm = 0;
		}
		if (flag && msg.vkcode == 0x58) {//X
			if (*cloud < 60) {
				*cloud += 5;
			}
		}
		if (flag && msg.vkcode == 0x43) {//C
			if (*cloud > 15 ) {
				*cloud -= 5;
			}
		}
		putBar(bar);
		for (int i = 0; i <= 4; i++) {
			roundrect(ret[i].x, ret[i].y, ret[i].x1, ret[i].y1, 16, 16);
		}
		putWENZI(ret, rains, wind, lei,  randm,  cloud);
	}
}