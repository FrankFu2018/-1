// 阶乘.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
template<class T>
class Link;
template<class T>
class ChainNode
{
	friend Link<T>;
private:
	T data;
	ChainNode<T> *link;
};
template<class T>
class Link
{
public:
	Link() { first = 0; };
	~Link();
	bool IsEmpty()const { return first == 0; }
	int Length()const;
	bool Find(int k, T&x);
	Link<T>&Insert(int k, const T&x);
	Link<T>& Change(int k, T x);
	Link<T>& Delete(int k, T &x);
	Link<T>& Search(const T&x)const;
	int OutPut();
private:
	ChainNode<T>*first;
};
/**************析构函数（删除链表的所有节点）********************/
template<class T>
Link<T>::~Link()
{
	ChainNode<T>*next;
	while (first)
	{
		next = first->link;
		delete first;
		first = next;
	}
}
/**********************确定链表的长度*****************************/
template<class T>
int Link<T>::Length()const
{
	ChainNode<T>*current = first;
	int len = 0;
	while (current)
	{
		len++;
		current = current->link;
	}
	return len;
}
/*********************在链表中查找第K个元素*************************/
template<class T>
bool Link<T>::Find(int k, T &x)
{
	ChainNode<T>*current = first;
	int index = 0;
	while (index<k&&current)
	{
		current = current->link;
		index++;
	}
	if (current) { x = current->data; return true; }
	return false;
}
/*********************向链表中插入元素*************************/
template<class T>
Link<T>& Link<T>::Insert(int k, const T&x)
{
	ChainNode<T>*p = first;
	for (int index = 1; index<k&&p; index++)
		p = p->link;
	ChainNode<T>*y = new ChainNode<T>;
	y->data = x;
	if (k) {
		y->link = p->link;
		p->link = y;
	}
	else {
		y->link = first;
		first = y;
	}
	return *this;
}
/********************改变链表第k个元素的值***********************/
template<class T>
Link<T>& Link<T>::Change(int k, T x)
{
	ChainNode<T> *p = first;
	for (int index = 0; p&&index<k; index++)
	{
		p = p->link;
	}
	if (p)
		p->data = x;
	return *this;
}
/********************删除链表第k个元素***********************/
template<class T>
Link<T>&Link<T>::Delete(int k, T &x)
{
	if (k = 0)
	{
		first = first->link;
	}
	else
		ChainNode<T>* p = first;
	ChainNode<T>* q = first;
	for (int index = 1; index<k - 1 && q; index++)
	{
		q = q->link;
		p = q->link;
		q - link = p->link;
		x = P->data;
		delete p;
		return *this;
	}
}
/************************搜索第k个元素***************************/
template<class T>
Link<T>&Link<T>::Search(const T&x)const
{
	ChainNode<T> *current = first;
	int index = 1;
	while (current && current->data != x)
	{
		current = current->link;
		index++;
	}
	if (current)return index;
	return 0;
}
/***********************倒序输出链表************************/
template<class T>
int Link<T>::OutPut()
{
	ChainNode<T>*current = first;
	int index = 0;
	int len = 0;
	while (current)
	{
		len++;
		current = current->link;
	}
	int *arry = new int[len];
	current = first;
	while (current)
	{
		arry[index] = current->data;
		current = current->link;
		index++;
	}
	index = index - 1;
	cout << arry[index];
	index = index - 1;
	for (index; index >= 0; index--)
	{
		cout.fill('0');
		cout.width(3);
		cout << arry[index];
	}


	cout << endl;
	return 0;
}
int main()
{
	Link<int> A;
	int n, i, j, k;
	int l = 0;
	A.Insert(0, 1);
	cout << "please enter a number :" << endl;
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		int m = A.Length();
		for (j = 0; j<m; j++)
		{
			A.Find(j, k);
			k = i * k;
			A.Change(j, k);
		}
		for (j = 0; j<m; j++)
		{
			A.Find(j, k);
			if (k >= 1000)
			{
				if (j<m - 1)
					A.Find(j + 1, l);
				else {
					A.Insert(j + 1, 0);
					l = 0;
				}
				l += k / 1000;
				A.Change(j + 1, l);
				k = k % 1000;
				A.Change(j, k);
			}
		}
	}
	cout << "Length = " << A.Length() << endl;
	cout << "阶乘为：";
	A.OutPut();
	return 0;
}


