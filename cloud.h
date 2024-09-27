#pragma once
#include<graphics.h>
#include<stdlib.h>


struct Cloud {
	int left_top_x;
	int left_top_y;
	int right_bottom_x;
	int right_bottom_y;
	int speed;
	Cloud* next;
};
struct Clouds {
	Cloud cloud;
	Cloud* rear;
	int num;
};

void add_cloud(Clouds* c, int x1, int y1, int x2, int y2,int wind) {
	Cloud* cloud = (Cloud*)malloc(sizeof(Cloud));
	cloud->next = NULL;
	if (wind <= 0)
	{
		cloud->left_top_x = (unsigned)rand() % (x2 - x1)+ x2;
		cloud->right_bottom_x = cloud->left_top_x + (unsigned)rand() % 30 + 70;
	}
	if (wind > 0) {
		cloud->right_bottom_x = rand() % (x2 - x1)-x2;
		cloud->left_top_x=cloud->right_bottom_x- (unsigned)rand() % 30 + 70;
	}
	cloud->left_top_y = (unsigned)rand() % (y2 - y1) + y1;
	cloud->right_bottom_y = cloud->left_top_y + (unsigned)rand() % 30 + 10;
	cloud->speed = wind / 10;
	c->rear->next = cloud;
	c->rear = cloud;
	c->num++;
}

void init_clouds(Clouds* clouds)
{
	clouds->cloud.next = NULL;
	clouds->rear = &clouds->cloud;
	clouds->num = 0;
}

void drawcloud(Cloud* cloud) {
	fillellipse(cloud->left_top_x, cloud->left_top_y, cloud->right_bottom_x, cloud->right_bottom_y);
}

void delcloud(Clouds* cls, Cloud* c)
{
	Cloud* p = &cls->cloud;
	while (p->next != c)
		p = p->next;
	p->next = c->next;
	if (cls->rear == c)
		cls->rear = p;
	free(c);
	cls->num--;
}

void updata(Cloud* c,int wind)
{
	//int t = c->right_bottom_x - c->left_top_x;
	c->left_top_x += wind /3;
	c->right_bottom_x += wind /3;
}


void draw_clouds(Clouds* clouds, int num, int x1, int y1, int x2, int y2,int wind) {
	while (clouds->num < num)
		add_cloud(clouds, x1, y1, x2, y2, wind);
	setcolor(LIGHTGRAY);
	setfillcolor(LIGHTGRAY);
	Cloud* c = clouds->cloud.next;
	while (c)
	{
		updata(c, wind);
		drawcloud(c);
		if (c->right_bottom_x <= x1 && wind <= 0)
		{
			Cloud* t = c;
			c = c->next;
			delcloud(clouds, t);
		}
		else if (wind > 0 && c->left_top_x >= x2)
		{
			Cloud* t = c;
			c = c->next;
			delcloud(clouds, t);
		}
		else c = c->next;
	}
	setcolor(WHITE);
}