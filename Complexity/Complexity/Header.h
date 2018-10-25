#pragma once
//空间复杂度是程序所需要的内存
#include<malloc.h>

long sum1(int n) {//2n+3 4n+8个字节
	long ret = 0;//1 4个字节
	int* array = (int*)malloc(n * sizeof(int));//1 4*n个字节
	int i = 0;//1 4个字节

	for (i = 0; i < n; i++) {//n 内部运算不需要新内存
		array[i] = i + 1;
	}

	for (i = 0; i < n; i++) {//n
		ret += array[i];
	}

	free(array);//1
	return ret;
}

long sum2(int n) {//n+2 8个字节
	long ret = 0;//1
	int i = 0;//1

	for (i = 1; i <= n; i++) {//n
		ret += i;
	}

	return ret;
}

long sum3(int n) {//2 4个字节
	long ret = 0;//1

	if (n > 0) {//1
		ret = (1 + n)*n / 2;
	}

	return ret;
}