/*
姓名：任精普
班级：21综合
学号：5903121107
算法效果：经过输入输出验证之后，成功将该线性表中所有值为5(自己设定的值)的数据元素删除
时间复杂度分析：本算法(即DeleteSameElem()函数)只对线性表扫描一遍，为线性复杂度o(n)，符合题意要求
空间复杂度分析：本代码中初始化线性表申请了一定的空间，但这只是为了能够在之后有运行效果方便老师查验。而本题的题意是线性表已经是
给定的了，所以初始化线性表中的申请空间不计算在内，则除此之外没有申请任何的额外空间，完全是在原顺序表上操作，空间复杂度为o(1)
*/

#include <iostream>
#include <malloc.h>

using namespace std;

typedef struct
{
	int* elem; // 数组指针
	int length; // 当前顺序表中的元素个数
	int listSize; // 当前顺序表所能容纳的最大元素个数
}SqList;

void InitList_Sq(SqList& L)
{
	L.elem = (int*)malloc(sizeof(int) * 100);
	L.length = 0; // 初始容纳元素个数为0
	L.listSize = 100; // 初始最大容纳元素量为100
}

 // 设计算法:删除线性表中所有值为deleteNum的元素
void DeleteSameElem(SqList& L, int deleteNum)
{
	int deleteCnt = 0; // 表示删除了的重复元素的个数
	int k = 0; // 表示当前遇到的值该是第几个位置

	for (int* p = &L.elem[0]; p <= &L.elem[L.length - 1]; p++) {
		if (*p != deleteNum) {
			L.elem[k] = *p; // 如果不是要删除的元素，那么放到它该放的位置
			k++;
		}
		else {
			deleteCnt++; // 是要删除的元素，则deleteCnt++
		}
	}
	L.length -= deleteCnt; // 表长减去删除的重复元素的个数
}

int main(void)
{
	SqList L; // 创建顺序表
	InitList_Sq(L); // 初始化线性表

	for (int i = 0; i < 20; i++) {
		L.elem[i] = i;
		L.length++; 
	}  // 向线性表中添加元素

	// 赋重复值，为之后的算法示例做准备
	L.elem[3] = 5;
	L.elem[6] = 5;
	L.elem[11] = 5;
	L.elem[15] = 5;

	cout << "初始线性表：";
	for (int* p = &L.elem[0]; p <= &L.elem[L.length - 1]; p++) {
		cout << *p << " ";
	} // 输出:0 1 2 5 4 5 5 7 8 9 10 5 12 13 14 5 16 17 18 19
	cout << endl;

	// 算法应用示例：删除该线性表中所有值为5的数据元素
	DeleteSameElem(L, 5);

	cout << "删除之后的线性表：";
	for (int* p = &L.elem[0]; p <= &L.elem[L.length - 1]; p++) {
		cout << *p << " ";
	} // 输出结果：0 1 2 4 7 8 9 10 12 13 14 16 17 18 19 ，删除成功
	
	return 0;
}
