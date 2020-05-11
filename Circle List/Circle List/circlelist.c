#include<malloc.h>
#include"circlelist.h"

typedef struct _tag_CircleList
{
	CircleListNode header;
	CircleListNode* slider;
	int length; 
}TCircleList;

CircleList* CircleList_Create()
{
	TCircleList* ret = (TCircleList*)malloc(sizeof(TCircleList));
	if (ret == NULL)
	{
		return NULL;
	}

	ret->length = 0;
	ret->header.next = NULL;
	//ret->slider = &(ret->header);
	ret->slider = NULL;

	return ret;
}

void CircleList_Destory(CircleList* list)
{
	if (list != NULL)
	{
		free(list);
		list = NULL;
	}
	return;
}

void CircleList_Clear(CircleList* list)
{
	TCircleList *clist = (TCircleList*)list;
	if (list == NULL)
	{
		return;
	}

	clist->length = 0;
	clist->header.next = NULL;
	clist->slider = NULL;
}

int CircleList_Length(CircleList* list)
{
	TCircleList *clist = NULL;
	if (list==NULL)
	{
		return 0;
	}
	clist = (TCircleList*)list;

	return clist->length;
}

int CircleList_Insert(CircleList* list, CircleListNode* node, int pos)
{
	int i = 0;
	TCircleList *clist = (TCircleList*)list;
	//CircleListNode* current = (CircleListNode*)clist;
	clist->slider = (CircleListNode* )clist;

	if (list == NULL || node == NULL || pos < 0)
	{
		printf("func insert() error \n");
		return 0;
	}

	for (i = 0; i < pos && (clist->slider->next != NULL); i++)
	{
		clist->slider = clist->slider->next;
	}

	node->next = clist->slider->next;
	clist->slider->next = node;

	
	clist->length++;

	return 0;
}

CircleListNode* CircleList_Get(CircleList* list, int pos)
{
	int i = 0, tmppos = 0;
	TCircleList *clist = (TCircleList*)list;
	clist->slider = (CircleListNode*)clist;
	CircleListNode* ret = NULL;

	if (list == NULL || pos < 0 )
	{
		printf(" func get() error \n");
		return NULL;
	}
	tmppos = pos % (clist->length);

	for (i = 0; i < tmppos && (clist->slider->next != NULL); i++)
	{
		clist->slider = clist->slider->next;
	}

	ret = clist->slider->next;

	return ret;
}

CircleListNode* CircleList_Delete(CircleList* list, int pos)
{
	int i = 0, tmppos = 0;
	TCircleList *clist = (TCircleList*)list;
	clist->slider = (CircleListNode*)clist;
	CircleListNode* ret = NULL;

	if (list == NULL || pos < 0)
	{
		printf(" func get() error \n");
		return NULL;
	}
	tmppos = pos % (clist->length);

	for (i = 0; i < tmppos && (clist->slider->next != NULL); i++)
	{
		clist->slider = clist->slider->next;
	}

	ret = clist->slider->next;
	clist->slider->next = ret->next;

	clist->length--;

	//Exception
	if (clist->length == 0)
	{
		clist->header.next = NULL;
		clist->slider = NULL;
	}

	return ret;
}

CircleListNode* CircleList_DeleteNode(CircleList* list, CircleListNode* node)
{
	TCircleList* slist = (TCircleList*)list;
	CircleListNode* ret = NULL;
	int i = 0;

	if (slist!=NULL)
	{
		CircleListNode* current = (CircleListNode*)slist;

		if (current->next == node)
		{
			ret = current->next;
			goto a;
		}
		current = current->next;
	}
	//I don't know why I cannot use func break , but it doen't matter
	a:
	if (ret != NULL)
	{
		CircleList_Delete(slist, i);
	}

	return ret;
}

CircleListNode* CircleList_Reset(CircleList* list)
{
	TCircleList* slist = (TCircleList*)list;
	CircleListNode* ret = NULL;

	if (slist != NULL)
	{
		slist->slider = slist->header.next;
		ret = slist->slider;
	}

	return ret;
}

CircleListNode* CircleList_Current(CircleList* list)
{
	TCircleList* slist = (TCircleList*)list;
	CircleListNode* ret = NULL;

	if (slist != NULL)
	{
		ret = slist->slider;
	}

	return ret;
}

CircleListNode* CircleList_Next(CircleList* list)
{
	TCircleList* slist = (TCircleList*)list;
	CircleListNode* ret = NULL;

	if ((slist != NULL)&&(slist->slider!=NULL))
	{
		ret = slist->slider;
		slist->slider = ret->next;
	}

	return ret;
}