/*
题目描述：
    It is said that in 2011, there are about 100 graduate schools ready to proceed over 40,000 applications in Zhejiang Province. It would help a lot if you could write a program to automate the admission procedure.
    Each applicant will have to provide two grades: the national entrance exam grade GE, and the interview grade GI. The final grade of an applicant is (GE + GI) / 2. The admission rules are:
    • The applicants are ranked according to their final grades, and will be admitted one by one from the top of the rank list.
    • If there is a tied final grade, the applicants will be ranked according to their national entrance exam grade GE. If still tied, their ranks must be the same.
    • Each applicant may have K choices and the admission will be done according to his/her choices: if according to the rank list, it is one's turn to be admitted; and if the quota of one's most preferred shcool is not exceeded, then one will be admitted to this school, or one's other choices will be considered one by one in order. If one gets rejected by all of preferred schools, then this unfortunate applicant will be rejected.
    • If there is a tied rank, and if the corresponding applicants are applying to the same school, then that school must admit all the applicants with the same rank, even if its quota will be exceeded.
输入：
    Each input file may contain more than one test case.
    Each case starts with a line containing three positive integers: N (≤40,000), the total number of applicants; M (≤100), the total number of graduate schools; and K (≤5), the number of choices an applicant may have.
    In the next line, separated by a space, there are M positive integers. The i-th integer is the quota of the i-th graduate school respectively.
    Then N lines follow, each contains 2+K integers separated by a space. The first 2 integers are the applicant's GE and GI, respectively. The next K integers represent the preferred schools. For the sake of simplicity, we assume that the schools are numbered from 0 to M-1, and the applicants are numbered from 0 to N-1.
输出：
    For each test case you should output the admission results for all the graduate schools. The results of each school must occupy a line, which contains the applicants' numbers that school admits. The numbers must be in increasing order and be separated by a space. There must be no extra space at the end of each line. If no applicant is admitted by a school, you must output an empty line correspondingly.
样例输入：
11 6 3
2 1 2 2 2 3
100 100 0 1 2
60 60 2 3 5
100 90 0 3 4
90 100 1 2 0
90 90 5 1 3
80 90 1 0 2
80 80 0 1 2
80 80 0 1 2
80 70 1 3 2
70 80 1 2 3
100 100 0 2 4
样例输出：
0 10
3
5 6 7
2 8

1 4
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
 
struct appType
{
    int id;
    int ge, gi;
    queue<int> choices;
 
    appType(int a)
    {
        id = a;
    }
};
 
bool cmp(const appType &a, const appType &b)
{
    if (a.ge + a.gi != b.ge + b.gi)
        return (a.ge + a.gi) > (b.ge + b.gi);
    else
        return a.ge > b.ge;
}
 
int main()
{
    int n, m, k;
    int quota[105];
 
    while(scanf("%d %d %d", &n, &m, &k) != EOF)
    {
        for(int i = 0;i < m;i++)
            scanf("%d", &quota[i]);
 
        vector<appType> apps;
        for(int i = 0;i < n;i++)
        {
            appType oneApp(i);
            scanf("%d %d", &oneApp.ge, &oneApp.gi);
            for(int j = 0;j < k;j++)
            {
                int temp;
                scanf("%d", &temp);
                oneApp.choices.push(temp);
            }
            apps.push_back(oneApp);
        }
        sort(apps.begin(), apps.end(), cmp);
 
        vector< vector<int> > ans;
        ans.resize(m);
        for(int i = 0;i < n;i++)
            while(!apps[i].choices.empty())
            {
                int choice = apps[i].choices.front();
                apps[i].choices.pop();
 
                if (quota[choice])
                {
                    quota[choice]--;
                    ans[choice].push_back(i);
                    break;
                }
                else if (ans[choice].size() > 0)
                {
                    int lastApp = ans[choice].back();
                    if (apps[i].ge + apps[i].gi == apps[lastApp].ge + apps[lastApp].gi && apps[i].ge == apps[lastApp].ge)
                    {
                        ans[choice].push_back(i);
                        break;
                    }
                }
            }
 
        for(int i = 0;i < m;i++)
        {
            for(int j = 0;j < ans[i].size();j++)
                ans[i][j] = apps[ans[i][j]].id;
            sort(ans[i].begin(), ans[i].end());
            if (ans[i].size() > 0)
                printf("%d", ans[i][0]);
            for(int j = 1;j < ans[i].size();j++)
                printf(" %d", ans[i][j]);
            putchar('\n');
        }
    }
 
    return 0;
}
