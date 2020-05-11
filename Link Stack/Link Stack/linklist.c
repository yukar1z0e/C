#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include "linklist.h"

typedef struct _tag_LinkList
{
	LinkListNode header;
	LinkListNode* slider;
	int length;
}TLinkList;

LinkList* LinkList_Create()
{
	TLinkList *ret = NULL;
	ret = (TLinkList*)malloc(sizeof(TLinkList));
	//memset(ret, 0, sizeof(TLinkList));

	ret->length = 0;
	ret->header.next = NULL;
	ret->slider = NULL;

	return ret;
}

void LinkList_Destory(LinkList* list)
{
	if (list != NULL)
	{
		free(list);
		list = NULL;
	}
	return;

}

//return beginning
void LinkList_Clear(LinkList* list)
{
	TLinkList *tlist = NULL;
	if (list == NULL)
	{
		return;
	}
	tlist = (TLinkList*)list;

	tlist->length = 0;
	tlist->header.next = NULL;
	return;
}

int LinkList_Length(LinkList* list)
{
	TLinkList *tlist = NULL;
	if (list == NULL)
	{
		return 0;
	}
	tlist = (TLinkList*)list;

	return tlist->length;
}

int LinkList_Insert(LinkList* list, LinkListNode* node, int pos)
{
	//int i = 0;
	//TLinkList *tlist = (TLinkList*)list;
	//LinkListNode *current = (LinkListNode*)tlist;

	//if (list == NULL || node == NULL || pos < 0)
	//{
	//	printf("func insert() error \n");
	//	return 0;
	//}

	////current = &(tlist->header);
	////current = tlist;

	//for (i = 0; i < pos && (current->next != NULL); i++)
	//{
	//	current = current->next;
	//}

	//node->next = current->next;
	//current->next = node;

	//tlist->length++;
	//return 0;

	int i = 0;
	TLinkList *tlist = (TLinkList*)list;
	tlist->slider = (LinkListNode*)tlist;

	if (list == NULL || node == NULL || pos < 0)
	{
		printf("func insert() error \n");
		return 0;
	}

	for (i = 0; i < pos && (tlist->slider->next != NULL); i++)
	{
		tlist->slider = tlist->slider->next;
	}

	node->next = tlist->slider->next;
	tlist->slider->next = node;


	tlist->length++;

	return 0;
}

LinkListNode* LinkList_Get(LinkList* list, int pos)
{	
	int i = 0;
	
	LinkListNode *ret = NULL;
	TLinkList *tlist = (TLinkList*)list;
	//tlist = (TLinkList*)list;
	tlist->slider = (LinkListNode*)tlist;

	if (list == NULL || pos < 0||pos >= tlist->length)
	{
		printf(" func get() error \n");
		return NULL;
	}
	
	//current = (LinkListNode*)tlist;
	//current = &(tlist->header);

	for (i = 0; i < pos && (tlist->slider->next != NULL); i++)
	{
		tlist->slider = tlist->slider->next;
	}

	ret = tlist->slider->next;

	return ret;
}

LinkListNode * LinkList_Delete(LinkList * list, int pos)
{
	int i = 0;
	LinkListNode *current = NULL;
	LinkListNode *tmp = NULL;
	TLinkList *tlist = NULL;

	if (list == NULL || pos < 0)
	{
		printf("error");
		return NULL;
	}
	tlist = (TLinkList*)list;
	current = &(tlist->header);

	for (i = 0; i < pos && (current->next != NULL); i++)
	{
		current = current->next;
	}
	tmp = current->next;
	current->next = tmp->next;

	tlist->length--;
	return tmp;
}
