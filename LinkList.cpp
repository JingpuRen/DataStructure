/*
姓名：任精普
班级：21综合
学号：5903121107
实现单链表结构和基本算法(创建，定位，遍历，插入，删除)的操作
*/

#include <iostream>
#include <malloc.h>

using namespace std;

typedef int ElemType;

 // 单链表的基本结构定义
typedef struct LNode
{
	struct LNode* next; // 指针域，指向下一个结点的指针
	ElemType data; // 数据域，表示当前结点存储元素的数值
}LNode,*LinkList;

 // 头插法创建单链表
void CreateList_L(LinkList& L, int n)
{
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL; // 创建头结点
	for (int i = 0; i < n; i++) {
		LinkList p = (LinkList)malloc(sizeof(LNode)); // 创建新的结点
		scanf_s("%d", & (p->data)); // 输入值，将其存储到新创建结点的数据域中，vs中已经弃用scanf
		p->next = L->next;
		L->next = p;
	}
}

 // 定位单链表中的第i个元素，并返回元素的值
int GetElem_L(LinkList L, int i, int& e)
{
	LinkList p = L->next; // p指向第一个结点
	int cnt = 1; // 表示当前是第几个元素
	while (p && cnt < i) {
		p = p->next;
		cnt++;
	}
	if (!p || cnt > i) return -1; // 表示定位失败
	else {
		e = p->data;
		return 1; // 表示定位成功
	}
}

 // 遍历单链表中的元素
void BianliList_L(LinkList L)
{
	LinkList p = L->next;
	for (p; p; p = p->next) {
		cout << p->data << " ";
	}
}

 // 在第i个位置之前插入元素
int InsertElem_L(LinkList &L, int i, int e)
{
	LinkList p = L;
	int j = 0;
	while (p && j < i - 1) {
		p = p->next;
		j++;
	}
	if (!p || j > i - 1) return -1; // 表示当前单链表中没有这个位置
	LinkList q = (LinkList)malloc(sizeof(LNode));
	q->data = e;
	q->next = p->next;
	p->next = q;
	return 1; // 表示插入成功
}

 // 删除第i个元素并返回删除的值
int DeleteElem_L(LinkList& L, int i, int &e)
{
	LinkList p = L;
	int j = 0;
	while (p && j < i - 1) {
		p = p->next;
		j++;
	}
	if (!p || j > i - 1) return -1; // 表示删除失败
	LinkList q = p->next; // 先将要删除结点取出来，方便之后取值
	e = q->data;
	p->next = q->next;
	free(q); // 将临时的内存释放掉
	return 1; // 表示删除成功
}

int main(void)
{
	LinkList L;
	CreateList_L(L, 10); // 创建10个元素的单链表，元素值为1 2 3 4 5 6 7 8 9 10
	BianliList_L(L); // 由于采用头插法，所以遍历结果为:10 9 8 7 6 5 4 3 2 1
	printf("\n");
	int e;
	int flag = GetElem_L(L, 3, e); // 定位单链表中第三个元素并返回其值
	printf("%d\n", e); // 输出：8
	flag = InsertElem_L(L, 3, 11); // 在第三个元素前插入元素值为11
	BianliList_L(L); // 插入后的单链表遍历为:10 9 11 8 7 6 5 4 3 2 1
	printf("\n");
	flag = DeleteElem_L(L, 5, e); // 删除当前单链表中第五个元素并返回其值
	BianliList_L(L); // 删除之后的单链表遍历为：10 9 11 8 6 5 4 3 2 1
	return 0;
}
