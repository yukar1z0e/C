//算法的实现是具体的计算机指令
//每一条指令在具体的计算机cpu上运行的时间是固定的
//通过具体的n的步骤的多少就可以推导出算法复杂度

#include"Header.h"
#include<iostream>

using namespace std;

int main() {
	int n = 10;

	cout << sum1(n) << endl;//O(n)
	cout << sum2(n) << endl;//O(n)
	cout << sum3(n) << endl;//O(1)

	system("pause");
	return 0;
}