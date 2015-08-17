/*
Description

A rooted tree is a well-known data structure in computer science and engineering. An example is shown below: 

 
In the figure, each node is labeled with an integer from {1, 2,...,16}. Node 8 is the root of the tree. Node x is an ancestor of node y if node x is in the path between the root and node y. For example, node 4 is an ancestor of node 16. Node 10 is also an ancestor of node 16. As a matter of fact, nodes 8, 4, 10, and 16 are the ancestors of node 16. Remember that a node is an ancestor of itself. Nodes 8, 4, 6, and 7 are the ancestors of node 7. A node x is called a common ancestor of two different nodes y and z if node x is an ancestor of node y and an ancestor of node z. Thus, nodes 8 and 4 are the common ancestors of nodes 16 and 7. A node x is called the nearest common ancestor of nodes y and z if x is a common ancestor of y and z and nearest to y and z among their common ancestors. Hence, the nearest common ancestor of nodes 16 and 7 is node 4. Node 4 is nearer to nodes 16 and 7 than node 8 is. 

For other examples, the nearest common ancestor of nodes 2 and 3 is node 10, the nearest common ancestor of nodes 6 and 13 is node 8, and the nearest common ancestor of nodes 4 and 12 is node 4. In the last example, if y is an ancestor of z, then the nearest common ancestor of y and z is y. 

Write a program that finds the nearest common ancestor of two distinct nodes in a tree. 

Input

The input consists of T test cases. The number of test cases (T) is given in the first line of the input file. Each test case starts with a line containing an integer N , the number of nodes in a tree, 2<=N<=10,000. The nodes are labeled with integers 1, 2,..., N. Each of the next N -1 lines contains a pair of integers that represent an edge --the first integer is the parent node of the second integer. Note that a tree with N nodes has exactly N - 1 edges. The last line of each test case contains two distinct integers whose nearest common ancestor is to be computed.
Output

Print exactly one line for each test case. The line should contain the integer that is the nearest common ancestor.
Sample Input

2
16
1 14
8 5
10 16
5 9
4 6
8 4
4 10
1 13
6 15
10 11
6 7
10 2
16 3
8 1
16 12
16 7
5
2 3
3 4
3 1
1 5
3 5
Sample Output

4
3

*/


#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int node1, node2;
int res;
vector< vector<int> > graph;

void dfs(int node, int fa, int &has1, int &has2)
{
	for(int i = 0;i < graph[node].size();i++)
	{
		int temp1 = 0, temp2 = 0;
		if (graph[node][i] != fa)
		{
			dfs(graph[node][i], node, temp1, temp2);
			if (temp1 == 1)
				has1 = 1;
			if (temp2 == 1)
				has2 = 1;
		}
	}

	if (node == node1)
		has1 = 1;
	if (node == node2)
		has2 = 1;


	if (has1 && has2 && res == -1)
		res = node;
}

int main()
{
	int ncase;
	cin >> ncase;

	while(ncase--)
	{
		int n;
		scanf("%d", &n);
		graph.clear();
		graph.resize(n);
		vector<int> inDegree;
		inDegree.resize(n);

		for(int i = 0;i < n - 1;i++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			graph[a - 1].push_back(b - 1);
			inDegree[b - 1]++;
		}

		int root = -1;
		for(int i = 0;i < n;i++)
			if (inDegree[i] == 0)
			{
				root = i;
				break;
			}

		scanf("%d %d", &node1, &node2);
		node1--, node2--;
		res = -1;

		int has1 = 0, has2 = 0;
		dfs(root, -1, has1, has2);
		cout << res + 1 << endl;		
	}

	return 0;
}
