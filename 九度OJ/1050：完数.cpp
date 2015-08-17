/*
题目描述：
    求1-n内的完数，所谓的完数是这样的数，它的所有因子相加等于它自身，比如6有3个因子1,2,3,1+2+3=6，那么6是完数。即完数是等于其所有因子相加和的数。
输入：
    测试数据有多组，输入n，n数据范围不大。
输出：
    对于每组输入,请输出1-n内所有的完数。如有案例输出有多个数字，用空格隔开，输出最后不要有多余的空格。
样例输入：
6
样例输出：
6
*/


#include <iostream>
using namespace std;
int main()
{
    int n, a;
    while(cin >> a)
    {
        int flag = 1;
        for(n = 2;n <= a;n++)
        {
            int res = 1;
            for(int i = 2;i * i <= n;i++)
                if (n % i == 0)
                    res += i + n / i;
            if (res == n)
            {
                if (flag)
                {
                    cout << res;
                    flag = 0;
                }
                else
                    cout << " " << res;
            }
        }
        cout << endl;
    }
    return 0;
}
