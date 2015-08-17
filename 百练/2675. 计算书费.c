/*
描述
下面是一个图书的单价表：
计算概论 28.9 元/本
数据结构与算法 32.7 元/本
数字逻辑 45.6元/本
C++程序设计教程 78 元/本
人工智能 35 元/本
计算机体系结构 86.2 元/本
编译原理 27.8元/本
操作系统 43 元/本
计算机网络 56 元/本
JAVA程序设计 65 元/本
给定每种图书购买的数量，编程计算应付的总费用。
输入
输入第一行包含一个正整数k（0<k<100），表示有k组测试数据；接下来k行，每行包含一组测试数据。每组测试数据包含10个整数(大于等于0，小于等于100)，分别表示购买的《计算概论》、《数据结构与算法》、《数字逻辑》、《C++程序设计教程》、《人工智能》、《计算机体系结构》、《编译原理》、《操作系统》、《计算机网络》、《JAVA程序设计》的数量（以本为单位）。每两个整数用一个空格分开。
输出
对于每组测试数据，输出一行。该行包含一个浮点数f，表示应付的总费用。精确到小数点后两位。

可用printf("%.2f\n", sum)来输出sum的值，并精确到小数点后两位。
样例输入
2
1 5 8 10 5 1 1 2 3 4 
3 5 6 3 100 1 1 0 1 0
样例输出
2140.20
4427.80
*/


#include <stdio.h>

double price[10] = {28.9, 32.7, 45.6, 78, 35, 86.2, 27.8, 43, 56, 65};

int main()
{
	int i, ncase;
	double sum;
	int num[100];

	scanf("%d", &ncase);
	while(ncase--)
	{
		sum = 0;
		for(i = 0;i < 10;i++)
		{
			scanf("%d", &num[i]);
			sum += num[i] * price[i];
		}
		printf("%.2f\n", sum);
	}
	return 0;
}
