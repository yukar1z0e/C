#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include"linklist.h"

typedef struct MyStruct
{
	int age;
	char name[64];
	LinkListNode node;
}MyStruct;

void main()
{
	int len = 0, ret = 0, i = 0;

	LinkList* list = NULL;

	MyStruct s1, s2, s3;
	s1.age = 1;
	s2.age = 2;
	s3.age = 3;

	list = LinkList_Create();

	if (list == NULL)
	{
		return;
	}

	len = LinkList_Length(list);

	ret = LinkList_Insert(list, (LinkListNode*)&s1, 0);
	ret = LinkList_Insert(list, (LinkListNode*)&s2, 0);
	ret = LinkList_Insert(list, (LinkListNode*)&s3, 0);

	for (i = 0; i < LinkList_Length(list); i++)
	{
		MyStruct *tmp = (MyStruct*)LinkList_Get(list, i);
		if (tmp == NULL)
		{
			printf("Empty");

			system("pause");

			return;
		}
		printf("tmp->age: %d \n", tmp->age);
	}

	/*while (LinkList_Length(list) > 0)
	{
		LinkList_Destory(list);
	}*/

	system("pause");
	return;
}