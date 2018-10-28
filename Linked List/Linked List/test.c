#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include"linklist.h"

typedef struct MyStruct
{
	int age;
	char name[64];
}MyStruct;

void main()
{
	int len = 0, ret = 0, i = 0;

	LinkList* list = NULL;

	MyStruct s1, s2, s3;
	s1.age = 1;
	s2.age = 2;
	s3.age = 3;

        LinkListNode lln1, lln2, lln3;
        lln1.data = &s1;
        lln2.data = &s2;
        lln3.data = &s3;

	list = LinkList_Create();

	if (list == NULL)
	{
		return;
	}

	len = LinkList_Length(list);

	ret = LinkList_Insert(list, &lln1, 0);
	ret = LinkList_Insert(list, &lln2, 0);
	ret = LinkList_Insert(list, &lln3, 0);

	for (i = 0; i < LinkList_Length(list); i++)
	{
		LinkListNode *tmp = LinkList_Get(list, i);
		if (tmp == NULL)
		{
			printf("Empty");

			system("pause");

			return;
		}
                MyStruct * tmpStruct = (MyStruct*)tmp->data; 
		printf("tmpStruct->age: %d \n", tmpStruct->age);
	}

	/*while (LinkList_Length(list) > 0)
	{
		LinkList_Destory(list);
	}*/

	system("pause");
	return;
}
