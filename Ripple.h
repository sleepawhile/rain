#pragma once
#include<easyx.h>
#include"Rain.h"
struct Ripple {
	DWORD* img_ptr1;//存原图的内存指针
	DWORD* img_ptr2;//存处理后的图的内存指针
	int* buf1;//前一帧每点波幅的指针
	int* buf2;//后一帧每点波幅的指针
};
/*初始化ripple，src_img为原图片，dest_img为存储ripple后的图片*/
void initripple(Ripple* r,IMAGE* src_img, IMAGE* dest_img);
void formripple(Ripple* r, IMAGE* src_img,Rain *q);
void randerripple(Ripple* r, IMAGE* src_img, IMAGE* dest_img);
