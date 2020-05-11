#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

extern "C"
{
#include"linkstack.h"
}

using namespace std;

int main()
{
	int i = 0;
	int a[10];

	LinkStack * stack = LinkStack_Create();
	if (stack == NULL)
	{
		return 0;
	}

	for (int i = 0; i < 5; i++)
	{
		a[i] = i + 1;
		LinkStack_Push(stack, &a[i]);
	}

	cout << "Length : " << LinkStack_Size(stack) << endl;
	//cout << "Top : " << *((int*)LinkStack_Top(stack)) << endl;

	while (LinkStack_Size(stack) > 0)
	{
		int tmp = *((int*)LinkStack_Pop(stack));
		cout << "tmp : " << tmp << endl;
	}

	//LinkStack_Destory(stack); 

	system("pause");
	return 0;
}