#include <iostream>
#include <malloc.h>
#include <cstdio>
#define ListInitSize 100 // 线性表初始所能容纳的最多的元素个数


using namespace std;

typedef int ElemType;

// 顺序表的结构定义
typedef struct {
	ElemType * elem; // 数组指针
	int length; // 当前线性表的长度，即线性表中的元素的个数
	int listSize; // 当前线性表分配的存储容量，即当前线性表所能容纳的最多的元素个数
}SqList;

 // 初始化线性表
int InitSqList(SqList& l)
{
	l.elem = (ElemType*)malloc(sizeof(ElemType) * ListInitSize); // 分配空间
	if (!l.elem) exit(OVERFLOW); // 如果指针指向空，则内存分配失败，退出程序
	l.length = 0; // 初始化时为空表，长度为0
	l.listSize = ListInitSize; // 初始可容纳的元素数量
	return 1; // 表示初始化成功
}

// 销毁线性表
void DestoryList_Sq(SqList& l)
{
	free(l.elem); // 释放分配的内存
	l.elem = NULL;
	l.length = 0;
	l.listSize = 0;
}
 
int cmp(ElemType e1, ElemType e2)
{
	if (e1 == e2) return 1;
	else return 0;
}
 // 线性表查找元素
int LocateElem_Sq(SqList l, ElemType e, int (*cmp) (int,int))
{
	int i = 1; // 当前查找到第i个元素
	int* p = l.elem; // 定义指向数组首地址的指针
	while (i <= l.length) {
		if ((*cmp)(e, (*p))) return i; // 返回该元素的位序
		i++;
	}
	return -1; // 返回-1表示没有符合条件的元素
}

 // 线性表插入元素
int InsertElem_Sq(SqList& l, ElemType e, int i)
{
	// 在l线性表中的第i个元素前插入元素e
	if (i < 1 || i > l.length + 1) return 0; // 输入非法
	else {
		if (l.length >= l.listSize) {
			ElemType* newp = (ElemType*)realloc(l.elem,sizeof(ElemType)*(l.listSize + 10));
			if (!newp) exit(OVERFLOW); // 分配失败则退出
			else {
				l.elem = newp; // 变更基址
				l.listSize += 10; // 容量变更
			}
		}
		
		int* q = &(l.elem[i - 1]); // 找到要插入的位置
		for (int* p1 = &(l.elem[l.length - 1]); p1 >= q; p1--) {
			*(p1 + 1) = *p1; // 将元素往后移一位
		}

		*q = e;
		l.length += 1;
		return 1; // 插入成功
	}
}

 // 线性表删除元素
int DeleteElem_Sq(SqList& l, int i, ElemType& e)
{
	if (i < 1 || i > l.length) return 0; // 输入非法
	else {
		e = l.elem[i - 1]; // 把要删除的数据记录下来
		for (int* p = &l.elem[i - 1]; p <= &l.elem[l.length-2]; p++) {
			(*p) = *(p + 1); // 元素前移
		}
		l.length -= 1;
		return 1; // 删除成功
	}
}

int main(void)
{
	SqList L; // 创建线性表
	InitSqList(L); // 调用初始化函数
	//printf("%d %d", L.length,L.listSize); // 0 100
	for (int i = 0; i <= 9; i++) {
		L.elem[i] = i;
		L.length++;
	}
	int flag = InsertElem_Sq(L, 3, 1); // 第一个元素位置插入数值3
	/*for (int i = 0; i < L.length; i++) {
		cout << L.elem[i] << " ";
	}3 0 1 2 3 4 5 6 7 8 9*/
	int deleteElem; // 存储删除的元素
	flag = DeleteElem_Sq(L, 4, deleteElem);
	/*for (int i = 0; i < L.length; i++) {
		cout << L.elem[i] << " ";
	} 删除第四个元素，得到数组为3 0 1 3 4 5 6 7 8 9*/
	int index = LocateElem_Sq(L, 3, cmp);
	// cout << index; 1,即3为数组中的第一个元素
	// cout << L.length << endl; 10
	DestoryList_Sq(L);
	// cout << L.length; 0，线性表元素由10变为0，成功销毁线性表
	return 0;
}
