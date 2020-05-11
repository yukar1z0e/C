//Test Sequence List

#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include"seqlist.h"

typedef struct MyStruct
{
	int age;
	char name[64];
}Mystruct;

void main() {
	int ret = 0, i = 0;
	SeqList* list = NULL;

	Mystruct s1, s2, s3, s4, s5;
	s1.age = 31;
	s2.age = 32;
	s3.age = 33;
	s4.age = 34;
	s5.age = 35;

	list = SeqList_Create(10);
	if (list == NULL) {
		printf("Func SeqList_Create() ret :%d \n ", ret);
		return;
	}

	ret = SeqList_Insert(list, (SeqListNode*)&s1, 0);
	ret = SeqList_Insert(list, (SeqListNode*)&s2, 0);
	ret = SeqList_Insert(list, (SeqListNode*)&s3, 0);
	ret = SeqList_Insert(list, (SeqListNode*)&s4, 0);
	ret = SeqList_Insert(list, (SeqListNode*)&s5, 0);

	for (i = 0; i < SeqList_Length(list); i++) {
		Mystruct* tmp = (Mystruct *)SeqList_Get(list, i);
		if (tmp == NULL) {
			printf("Empty\n");
			return;
		}
		printf("tmp->age:%d", tmp->age);
	}

	/*while (SeqList_Length(list) > 0) {
		SeqList_Delete(list, 0);
	}*/

	system("pause");
}