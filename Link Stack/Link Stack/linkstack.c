#include"linkstack.h"
#include"linklist.h"

typedef struct Service //for List
{
	LinkListNode node;
	void* item; //for Stack
}Service;

typedef struct _tag_LinkStackNode
{
	LinkListNode node;
	void* item; //for Stack
}TLinkStackNode;

LinkStack* LinkStack_Create()
{
	return LinkList_Create();
}

void LinkStack_Destory(LinkStack *stack)
{
	LinkStack_Clear(stack);
	LinkList_Destory(stack);
	return ;
}

//considering the life time of Stack
//free memory of each item
void LinkStack_Clear(LinkStack *stack)
{
	if (stack == NULL)
	{
		return;
	}

	while (LinkList_Length(stack) > 0)
	{
		//free memory
		LinkStack_Pop(stack);
	}
	return;
}

//void*item ---> LinkListNode* node
int LinkStack_Push(LinkStack *stack, void* item)
{
	int ret = 0;
	TLinkStackNode* tmp = NULL;
	tmp = (TLinkStackNode*)malloc(sizeof(TLinkStackNode));
	if (tmp == NULL)
	{
		printf("the item is empty");
		return -1;
	}
	memset(tmp, 0, sizeof(TLinkStackNode));
	tmp->item = item;
	//int LinkList_Insert(LinkList* list,LinkListNode* node,int pos);
	ret=LinkList_Insert(stack, (LinkListNode*)item, 0);
	if (ret != 0)
	{
		printf("func LinkList_Insert() error %d\n", ret);
		if (tmp != NULL)
		{
			free(tmp);
		}
		return ret;
	}
	return ret;
}

void* LinkStack_Pop(LinkStack* stack)
{
	void* item = NULL;
	TLinkStackNode*tmp = NULL;
	tmp=(TLinkStackNode*)LinkList_Delete(stack, 0);
	if (tmp == NULL)
	{
		return NULL;
	}
	item = tmp->item;

	//release memory
	free(tmp);
	return item;
}

void* LinkStack_Top(LinkStack* stack)
{
	TLinkStackNode*tmp = NULL;
	tmp = (TLinkStackNode*)LinkList_Get(stack, 0);
	if (tmp == NULL)
	{
		return NULL;
	}
	return tmp->item;
}

int LinkStack_Size(LinkStack* stack)
{
	return LinkList_Length(stack);
}
