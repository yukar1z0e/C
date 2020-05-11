#include<iostream>
extern "C"
{
#include"seqstack.h"
}

using namespace std;

int main()
{
	int a[10];
	SeqStack* stack = NULL;
	stack = SeqStack_Create(10);
	if (stack == NULL)
	{
		return 0;
	}

	for (int i = 0; i < 5; i++)
	{
		a[i] = i + 1;
		SeqStack_Push(stack, &a[i]);
	}

	cout << "Capacity : " << SeqStack_Capacity(stack) << endl;
	cout << "Length : " << SeqStack_Size(stack) << endl;
	cout << "Top : " << *((int*)SeqStack_Top(stack) )<< endl;

	while (SeqStack_Size(stack) > 0)
	{
		int tmp=*((int*)SeqStack_Pop(stack));
		cout << "tmp : " << tmp << endl;
	}

	system("pause");
	return 0;
}