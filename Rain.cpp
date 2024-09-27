#include"Rain.h"
#include<stdlib.h>
#include<time.h>
#include<math.h>

void insertraindrop(Rain* r, RainDrop* p)
{
	r->rear->next = p;
	r->rear = p;
	r->Intensity++;
}

void addraindrop(Rain* r, int x1, int y1, int x2, int y2,int wind)
{
	RainDrop* rd = (RainDrop*)malloc(sizeof(RainDrop));
	rd->next = NULL;
	rd->begin.x = rand() % (x2 - x1) + x1;
	rd->begin.y = rand() % 20 + y1;
	rd->velocity.x = wind / 10 + rand() % 10;
	rd->r = rand() % 255;
	rd->g = rand() % 255;
	rd->b = rand() % 255;
	rd->color = RGB(rd->r, rd->g, rd->b);
	int light = (rd->r * 299 + rd->g * 587 + rd->b * 114) / 1000;
	if (light > 150)light = 150;
	rd->velocity.y = light % 150/15+5;
	insertraindrop(r, rd);
}

void initrain_1(Rain* r,int intensity, int x1, int y1, int x2, int y2,int wind)
{
	r->raindrop.next = NULL;
	r->rear = &r->raindrop;
	r->Intensity = 0;

	for (int i = 0; i < intensity; i++)
	{
		RainDrop* rd = (RainDrop*)malloc(sizeof(RainDrop));
		rd->next = NULL;

		rd->begin.x = rand() % (x2 - x1) + x1;
		rd->begin.y = rand() % (y2 - y1) + y1;
		rd->velocity.x = rd->velocity.x = wind / 10 + rand() % 10;
		rd->r = rand() % 255;
		rd->g = rand() % 255;
		rd->b = rand() % 255;
		rd->color = RGB(rd->r, rd->g, rd->b);
		//RGB¼ÆËãÁÁ¶È¹«Ê½£ºY = ((R*299)+(G*587)+(B*114))/1000
		int light = (rd->r * 299 + rd->g * 587 + rd->b * 114) / 1000;
		if (light > 150)light = 150;
		rd->velocity.y = light % 150 / 15 + 5;

		insertraindrop(r, rd);
	}
}

void initrain(Rain* r)
{
	r->rear = &r->raindrop;
	r->raindrop.next = NULL;
	r->Intensity = 0;
}
//É¾³ýÂäË®ÓêµÎ
void delraindrop(Rain* r, RainDrop* p)
{
	RainDrop* q = &r->raindrop;
	while (q&&q->next != p)
		q = q->next;
	if (q)
	{
		q->next = p->next;
		p->next = NULL;
	}
	if (p == r->rear)
		r->rear = q;
	r->Intensity--;
}
//¸üÐÂÓêµÎ×ø±ê
void updata(RainDrop* r)
{
	r->begin.x += r->velocity.x;
	r->begin.y += r->velocity.y;
}
//ÅÐ¶ÏÓêµÎÊÇ·ñÂäË®
int istouchwater(RainDrop t,int y1,int y2)
{
	int light = (t.r * 299 + t.g * 587 + t.b * 114) / 1000;
	int position = light % (y2 - y1) + y1;
	if (t.begin.y+t.velocity.y >= position)
		return 1;
	return 0;
}
//»­ÓêµÎ
void randerrain(Rain* r,int intensity,int x1,int y1,int x2,int y2,int wind,Rain *q,int watery1,int watery2)
{
	if (r->Intensity < intensity)
	{
		if (intensity > MAX_Intensity)
			intensity = MAX_Intensity;
		for (int i = r->Intensity; i < intensity; i++)
			addraindrop(r, x1, y1, x2, y2, wind);
	}

	RainDrop* rd = r->raindrop.next;
	while(rd)
	{
		if (rd->begin.x < 0)
			rd->begin.x = x2;
		if (rd->begin.x > x2)
			rd->begin.x = 0;
		int endx = rd->begin.x + rd->velocity.x;
		int endy = rd->begin.y + rd->velocity.y;
		setlinecolor(rd->color);
		line(rd->begin.x, rd->begin.y, endx,endy);
		updata(rd);
		if (istouchwater(*rd, watery1, watery2))
		{
			RainDrop* t = rd;
			rd = rd->next;
			delraindrop(r, t);
			insertraindrop(q, t);
		}
		else rd = rd->next;
	}
}
