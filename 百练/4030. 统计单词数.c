/*
描述
  一般的文本编辑器都有查找单词的功能，该功能可以快速定位特定单词在文章中的位置，有的还能统计出特定单词在文章中出现的次数。 
现在，请你编程实现这一功能，具体要求是：给定一个单词，请你输出它在给定的文章中出现的次数和第一次出现的位置。注意：匹配单词时，不区分大小写，但要求完全匹配，即给定单词必须与文章中的某一独立单词在不区分大小写的情况下完全相同 （参见样例 1） ，如果给定单词仅是文章中某一单词的一部分则不算匹配（参见样例 2） 。

输入
第 1 行为一个字符串，其中只含字母，表示给定单词； 
第 2 行为一个字符串，其中只可能包含字母和空格，表示给定的文章。
输出
只有一行， 如果在文章中找到给定单词则输出两个整数， 两个整数之间用一个空格隔开，分别是单词在文章中出现的次数和第一次出现的位置（即在文章中第一次出现时，单词首字母在文章中的位置，位置从 0 开始） ；如果单词在文章中没有出现，则直接输出一个整数-1。
样例输入
样例 #1:
To 
to be or not to be is a question 

样例 #2:
to 
Did the Ottoman Empire lose its power at that time
样例输出
样例 #1:
2 0

样例 #2:
-1
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define dis ('a' - 'A')
int main()
{
	char str[100];
	char templ[1000010];
	int i;
	int first, num;

	cin >> str;
	for(i = 0;str[i] != '\0';i++)
	{
		if (str[i] < 'a')
			str[i] += dis;
		if (!(str[i] >= 'a' && str[i] <= 'z'))
			while(1);
	}
	char c = getchar();
	while(c != '\n')
		c = getchar();
	first = -1;
	num = 0;
	gets(templ);
	char delims[] = " ";
	char *result = NULL;
	result = strtok( templ, delims );
	while( result != NULL )
	{
		//cout<<result << endl;
		for(i = 0;result[i] != '\0';i++)
		{
			if (result[i] < 'a')
				result[i] += dis;
		}
		if (strcmp(str, result) == 0)
		{
			if (first == -1)
				first = result - templ;
			num++;
		}
       result = strtok( NULL, delims );
	}

	if (num) cout << num << " ";
	cout << first << endl;
	return 0;
}
