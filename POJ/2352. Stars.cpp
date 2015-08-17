/*
Description

Astronomers often examine star maps where stars are represented by points on a plane and each star has Cartesian coordinates. Let the level of a star be an amount of the stars that are not higher and not to the right of the given star. Astronomers want to know the distribution of the levels of the stars. 


For example, look at the map shown on the figure above. Level of the star number 5 is equal to 3 (it's formed by three stars with a numbers 1, 2 and 4). And the levels of the stars numbered by 2 and 4 are 1. At this map there are only one star of the level 0, two stars of the level 1, one star of the level 2, and one star of the level 3. 

You are to write a program that will count the amounts of the stars of each level on a given map.
Input

The first line of the input file contains a number of stars N (1<=N<=15000). The following N lines describe coordinates of stars (two integers X and Y per line separated by a space, 0<=X,Y<=32000). There can be only one star at one point of the plane. Stars are listed in ascending order of Y coordinate. Stars with equal Y coordinates are listed in ascending order of X coordinate. 
Output

The output should contain N lines, one number per line. The first line contains amount of stars of the level 0, the second does amount of stars of the level 1 and so on, the last line contains amount of stars of the level N-1.
Sample Input

5
1 1
5 1
7 1
3 3
5 5
Sample Output

1
2
1
1
0
Hint

This problem has huge input data,use scanf() instead of cin to read data to avoid time limit exceed.

*/

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int arr[32005];
int N = 32001;
int lowBit(int t)
{
	return t - (t & (t - 1));
}

void add(int k, int v)
{
	for(int i = k;i <= N;i += lowBit(i))
		arr[i] += v;
}

int sum(int k)
{
	int res = 0;
	while(k > 0)
	{
		res += arr[k];
		k -= lowBit(k);
	}
	return res;
}

int res[15005];
int main()
{
	int n;
	cin >> n;
	memset(res, 0, sizeof(res));
	
	for(int i = 0;i < n;i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		res[sum(x + 1)]++;
		add(x + 1, 1);
	}

	for(int i = 0;i < n;i++)
		cout << res[i] << endl;
	
	return 0;
}
