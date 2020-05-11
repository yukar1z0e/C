#include"seqstack.h"
#include"seqlist.h"

// creating stack is the same as creating sequence list
SeqStack* SeqStack_Create(int capacity)
{
	/*SeqStack* ret = SeqList_Create(capacity);

	return ret;*/

	return SeqList_Create(capacity);
}

void SeqStack_Destory(SeqStack *stack)
{
	SeqList_Destroy(stack);
}

void SeqStack_Clear(SeqStack *stack)
{
	SeqList_Clear(stack);
}

//pushing item in stack is the same as inserting node in the back of list
int SeqStack_Push(SeqStack *stack, void* item)
{
	return SeqList_Insert(stack, item,SeqList_Length(stack));
}

void* SeqStack_Pop(SeqStack* stack)
{
	return SeqList_Delete(stack, SeqList_Length(stack) - 1);
}

void* SeqStack_Top(SeqStack* stack)
{
	return SeqList_Get(stack, SeqList_Length(stack) - 1);
}

int SeqStack_Capacity(SeqStack* stack)
{
	return SeqList_Capacity(stack);
}

int SeqStack_Size(SeqStack* stack)
{
	return SeqList_Length(stack);
}