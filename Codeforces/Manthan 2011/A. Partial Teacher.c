#include <stdio.h>

int main()
{
	int n;
	int i, j;
	int temp;
	int res[5000];
	char str[5000];

	scanf("%d", &n);
	scanf("%s", str);

	for(i = 0;i < n;i++)
	{
		res[i] = 1;
		for(j = i - 1;j >= 0;j--)
			if (str[j] == 'L')
				break;
			else
				if (str[j] == 'R')
					res[i]++;

		temp = 1;
		for(j = i;j < n -1;j++)
			if (str[j] == 'R')
				break;
			else
				if (str[j] == 'L')
					temp++;
		if (temp > res[i])
			res[i] = temp;
	}
	for(i = 0;i < n;i++)
		printf("%d ", res[i]);
	return 0;
}
