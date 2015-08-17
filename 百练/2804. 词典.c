/*
描述
你旅游到了一个国外的城市。那里的人们说的外国语言你不能理解。不过幸运的是，你有一本词典可以帮助你。
输入
首先输入一个词典，词典中包含不超过100000个词条，每个词条占据一行。每一个词条包括一个英文单词和一个外语单词，两个单词之间用一个空格隔开。而且在词典中不会有某个外语单词出现超过两次。词典之后是一个空行，然后给出一个由外语单词组成的文档，文档不超过100000行，而且每行只包括一个外语单词。输入中出现单词只包括小写字母，而且长度不会超过10。
输出
在输出中，你需要把输入文档翻译成英文，每行输出一个英文单词。如果某个外语单词不在词典中，就把这个单词翻译成“eh”。
样例输入
dog ogday
cat atcay
pig igpay
froot ootfray
loops oopslay

atcay
ittenkay
oopslay
样例输出
cat
eh
loops
*/

#include <iostream>
#include <map>
#include <cstdio>
using namespace std;

int main()
{
	map<string, string> dic;
	string a, b;
	string word;

	while(cin.peek() != '\n')
	{
		cin >> a >> b;
		dic[b] = a;
		getchar();
	}

	while(cin >> word)
	{
	//	cout << word << endl;
	//	cout << dic[word] << endl;
		if (dic.count(word) != 0)
			cout << dic[word] << endl;
		else
			cout << "eh" << endl;
	}		
	return 0;
}
