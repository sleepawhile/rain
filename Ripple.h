#pragma once
#include<easyx.h>
#include"Rain.h"
struct Ripple {
	DWORD* img_ptr1;//��ԭͼ���ڴ�ָ��
	DWORD* img_ptr2;//�洦����ͼ���ڴ�ָ��
	int* buf1;//ǰһ֡ÿ�㲨����ָ��
	int* buf2;//��һ֡ÿ�㲨����ָ��
};
/*��ʼ��ripple��src_imgΪԭͼƬ��dest_imgΪ�洢ripple���ͼƬ*/
void initripple(Ripple* r,IMAGE* src_img, IMAGE* dest_img);
void formripple(Ripple* r, IMAGE* src_img,Rain *q);
void randerripple(Ripple* r, IMAGE* src_img, IMAGE* dest_img);
