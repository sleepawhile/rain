#include"Ripple.h"
#include"Rain.h"
#include<stdlib.h>


void initripple(Ripple *r, IMAGE *src_img, IMAGE* dest_img)
{
	r->img_ptr1 = GetImageBuffer(src_img);
	r->img_ptr2 = GetImageBuffer(dest_img);
	r->buf1 = (int*)calloc(src_img->getwidth() * (src_img->getheight() + 1),sizeof(int));
	r->buf2 = (int*)calloc(src_img->getwidth() * (src_img->getheight() + 1),sizeof(int));
}

void disturb(Ripple* r, RainDrop p, IMAGE* src_img, int rainsize, int weight)
{
	int width = src_img->getwidth(), height = src_img->getheight();
	int moux = p.begin.x, mouy = p.begin.y;
	if ((mouy - rainsize<height * 0.589) || (moux - rainsize<0)
		|| (moux + rainsize>width )|| (mouy + rainsize>height-1))
		return;
	for (int y = mouy - rainsize; y < mouy + rainsize; y++)
		for (int x = moux - rainsize; x < moux + rainsize; x++)
			if ((x-moux) * (x-moux) + (y-mouy) * (y-mouy) < rainsize * rainsize)
				r->buf1[y * width + x] += weight;
}

void spreadripple(Ripple* r, IMAGE* src_img)
{
	int width = src_img->getwidth();
	int heigth = src_img->getheight();
	for (int i = width * heigth * 0.589 + width; i < width * (heigth - 1); i++)
	{
		//²¨·ù x0'=(x1+x2+x3+x4)/2-x0
		if (i % width >=width-3)//ÓÒ±ß½ç
			r->buf2[i] = ((r->buf1[i - width] + r->buf1[i + width]+ r->buf1[i - 4]) >> 1) - r->buf2[i];
		else if (i % width <=3)//×ó±ß½ç
			r->buf2[i] = ((r->buf1[i - width] + r->buf1[i + width] + r->buf1[i + 4]) >> 1) - r->buf2[i];
		else 
			r->buf2[i] = ((r->buf1[i - width] + r->buf1[i + width] + r->buf1[i + 4] + r->buf1[i - 4]) >> 1) - r->buf2[i];
		//²¨·ù¼õÈõ
		int m = (heigth-i / width)/60;
		r->buf2[i] -= r->buf2[i] >> (5-m);
	}
	//½»»»Ç°ºóÕñ·ù
	int* temp = r->buf1;
	r->buf1 = r->buf2;
	r->buf2 = temp;
}

void randerripple(Ripple* r,IMAGE*src_img,IMAGE*dest_img)
{
	int i = 0;
	for (int y = 0; y < src_img->getheight(); y++)
	{
		for (int x = 0; x < src_img->getwidth(); x++)
		{
			// Æ«ÒÆ
			int a = x - r->buf1[i];
			int b = y - r->buf1[i];
			// ±ß½ç´¦Àí
			if (a >= src_img->getwidth())
				a = src_img->getwidth() - 1;
			if (a < 0)a = 0;
			if (b >= src_img->getheight())
				b = src_img->getheight() - 1;
			if (b < 0)b = 0;
			// ´¦ÀíÆ«ÒÆ
			r->img_ptr2[i] = r->img_ptr1[a + (b * src_img->getwidth())];
			i++;
		}
	}
	putimage(0, 0, dest_img);
}

void formripple(Ripple*r,IMAGE*src_img,Rain*q)
{
	RainDrop* p = q->raindrop.next, * t;
	while (p)
	{
		t = p;
		int weight = p->velocity.x * p->velocity.x + p->velocity.y * p->velocity.y;
		disturb(r, *p, src_img, 3, weight);
		q->raindrop.next = p->next;
		p = p->next;
		free(t);
	}
	q->rear = &q->raindrop;
	spreadripple(r, src_img);
}