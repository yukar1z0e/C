#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<malloc.h>
#include"seqlist.h"

//结构体中套一级指针
typedef struct _tag_Seqlist {
	int length;
	int capacity;
	unsigned int *node;
}TSeqlist;

SeqList* SeqList_Create(int capacity) {
	int ret = 0;
	TSeqlist *tmp = NULL;

	tmp = (TSeqlist*)malloc(sizeof(TSeqlist));
	if (tmp == NULL) {
		ret = -1;
		printf("func SeqList_Create() error :%d \n", ret);
		return NULL;
	}
	memset(tmp, 0, sizeof(TSeqlist));

	//根据capacity大小分配节点空间
	tmp->node = (unsigned int*)malloc(sizeof(unsigned int*)*capacity);
	if (tmp->node == NULL) {
		ret = -2;
		printf("func SeqList_Create() error : malloc error %d \n", ret);
		return NULL;
	}
	tmp->capacity = capacity;
	tmp->length = 0;
	return tmp;
}

void SeqList_Destroy(SeqList* list) {
	TSeqlist *tlist = NULL;
	if (list == NULL) {
		return;
	}
	tlist = (TSeqlist*)list;
	if (tlist->node != NULL) {
		free(tlist->node);
	}

	free(list);

	return;
}

void SeqList_Clear(SeqList* list) {
	TSeqlist *tlist = NULL;
	if (list == NULL) {
		return;
	}
	tlist = (TSeqlist*)list;
	tlist->length = 0;
	return;
}

int SeqList_Length(SeqList* list) {
	TSeqlist *tlist = NULL;
	if (list == NULL) {
		return -1;
	}
	tlist = (TSeqlist*)list;
	return tlist->length;
}

int SeqList_Capacity(SeqList* list) {
	TSeqlist *tlist = NULL;
	if (list == NULL) {
		return -1;
	}
	tlist = (TSeqlist*)list;
	return tlist->capacity;
}

int SeqList_Insert(SeqList* list, SeqListNode* node, int pos) {
	int i = 0, ret = 0;
	TSeqlist *tlist = NULL;
	if (list == NULL || node == NULL || pos < 0) {
		ret = -1;
		printf("func SeqList_Insert() error :%d \n", ret);
		return ret;
	}
	tlist = (TSeqlist*)list;

	//if full
	if (tlist->length >= tlist->capacity) {
		ret = -2;
		printf("func SeqList_Insert() error : the list is full %d \n", ret);
		return ret;
	}

	//correct some error
	//ex: length is 6 capacity is 20 insert pos 10 then insert pos 7
	if (pos >= tlist->length) {
		pos = tlist->length + 1;
	}

	for (i = tlist->length; i > pos; i--) {
		tlist->node[i] = tlist->node[i - 1];
	}
	tlist->node[i] = (unsigned int)node;
	tlist->length++;
	return 0;
}

SeqListNode* SeqList_Get(SeqList* list, int pos) {
	int i = 0;
	SeqListNode *ret = 0;
	TSeqlist *tlist = NULL;

	if (list == NULL || pos < 0) {
		//ret = -1;
		printf("func SeqList_Get() error\n");
		return NULL;
	}
	tlist = (TSeqlist*)list;

	ret = (void*)tlist->node[pos];
	return ret;
}

SeqListNode* SeqList_Delete(SeqList* list, int pos) {
	int i = 0;
	SeqListNode *ret = 0;
	TSeqlist *tlist = NULL;

	if (list == NULL || pos < 0) {
		//ret = -1;
		printf("func SeqList_Get() error \n");
		return NULL;
	}
	tlist = (TSeqlist*)list;

	ret = (SeqListNode *)tlist->node[pos];

	for (i = pos + 1; i < tlist->length; i++) {
		tlist->node[i - 1] = tlist->node[i];
	}
	tlist->length--;
	return ret;
}

