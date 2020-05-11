#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include"linklist.h"
/*
typedef struct mystruct
{
	int age;
	char name[64];
	linklistnode node;
}mystruct;

void main()
{
	int len = 0, ret = 0, i = 0;

	//linklist* list = null;

	mystruct s1, s2, s3;
	s1.age = 1;
	s2.age = 2;
	s3.age = 3;

	linklist* list = linklist_create();

	if (list == null)
	{
		return;
	}

	len = linklist_length(list);

	linklist_insert(list, (linklistnode*)&s1, 0);
	linklist_insert(list, (linklistnode*)&s2, 0);
	linklist_insert(list, (linklistnode*)&s3, 0);

	for (i = 0; i < linklist_length(list); i++)
	{
		mystruct *tmp = (mystruct*)linklist_get(list, i);
		if (tmp == null)
		{
			printf("empty");

			system("pause");

			return;
		}
		printf("tmp->age: %d \n", tmp->age);
	}

	while (linklist_length(list) > 0)
	{
		linklist_destory(list);
	}

	system("pause");
	return;
}
*/

struct Value {
	LinkListNode listnode;
	int v;
};

int main()
{
	LinkList* list = LinkList_Create();

	struct Value v1;
	struct Value v2;
	struct Value v3;
	struct Value v4;
	/*struct Value v5;
	struct Value v6;
	struct Value v7;
	struct Value v8;*/

	int i = 0;

	v1.v = 1;
	v2.v = 2;
	v3.v = 3;
	v4.v = 4;
	/*v5.v = 5;
	v6.v = 6;
	v7.v = 7;
	v8.v = 8;*/

	LinkList_Insert(list, (LinkListNode*)&v1, 0);
	LinkList_Insert(list, (LinkListNode*)&v2, 0);
	LinkList_Insert(list, (LinkListNode*)&v3, 0);
	LinkList_Insert(list, (LinkListNode*)&v4, 0);

	//prove it is the link list
	for (i = 0; i < LinkList_Length(list); i++)
	{
		struct Value* pv = (struct Value*)LinkList_Get(list, i);

		printf("%d\n", pv->v);
	}

	//printf("\n");

	/*while (LinkList_Length(list) > 0)
	{
		LinkList_Delete(list, 0);
	}

	printf("\n");

	LinkList_Destory(list);*/

	system("pause");

	return 0;

}