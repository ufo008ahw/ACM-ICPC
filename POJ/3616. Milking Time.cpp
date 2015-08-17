/*
Description

Bessie is such a hard-working cow. In fact, she is so focused on maximizing her productivity that she decides to schedule her next N (1 ≤ N ≤ 1,000,000) hours (conveniently labeled 0..N-1) so that she produces as much milk as possible.

Farmer John has a list of M (1 ≤ M ≤ 1,000) possibly overlapping intervals in which he is available for milking. Each interval i has a starting hour (0 ≤ starting_houri ≤ N), an ending hour (starting_houri < ending_houri ≤ N), and a corresponding efficiency (1 ≤ efficiencyi ≤ 1,000,000) which indicates how many gallons of milk that he can get out of Bessie in that interval. Farmer John starts and stops milking at the beginning of the starting hour and ending hour, respectively. When being milked, Bessie must be milked through an entire interval.

Even Bessie has her limitations, though. After being milked during any interval, she must rest R (1 ≤ R ≤ N) hours before she can start milking again. Given Farmer Johns list of intervals, determine the maximum amount of milk that Bessie can produce in the N hours.

Input

* Line 1: Three space-separated integers: N, M, and R
* Lines 2..M+1: Line i+1 describes FJ's ith milking interval withthree space-separated integers: starting_houri , ending_houri , and efficiencyi

Output

* Line 1: The maximum number of gallons of milk that Bessie can product in the N hours

Sample Input

12 4 2
1 2 8
10 12 19
3 6 24
7 10 31
Sample Output

43
*/


#include <stdio.h>
#include <algorithm>
using namespace std;
int dp[1000001];
struct list
{
	int bg,ed,out;
}arr[1001];
bool cmp(const list a,const list b)
{
	if(a.bg<b.bg)
		return 1;
	else
		return 0;
}
int main()
{
	int i,j,n,m,r,temp,max;
	scanf("%d%d%d",&n,&m,&r);
	for(i=0;i<m;i++)
		scanf("%d%d%d",&arr[i].bg,&arr[i].ed,&arr[i].out);
	sort(&arr[0],&arr[m],cmp);
	for(i=0;i<=n;i++)
		dp[i]=0;
	max=0;
	for(i=0;i<m;i++)
	{
		temp=dp[arr[i].bg]+arr[i].out;
		for(j=arr[i].ed+r;j<n;j++)
			if(dp[j]<temp)
				dp[j]=temp;
		if(max<temp)
			max=temp;
	}
	printf("%d\n",max);
	return 0;
}
