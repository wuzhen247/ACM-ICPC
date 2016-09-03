//dp
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int N = 100+5;
char s[N];
int t, dp[N][2];

bool islowercase(char ch)
{
    if (ch >= 'a' && ch <= 'z')
        return true;
    return false;
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%s", s+1);
        int len = strlen(s+1);
        memset(dp, 0, sizeof(dp));
        dp[0][1] = 1;
        for (int i = 1; i <= len; i++)
        {
            if (islowercase(s[i]))
            {
                dp[i][0] = min(dp[i-1][0]+1, dp[i-1][1]+2);
                dp[i][1] = min(dp[i-1][0]+2, dp[i-1][1]+2);
            }
            else
            {
                dp[i][0] = min(dp[i-1][0]+2, dp[i-1][1]+2);
                dp[i][1] = min(dp[i-1][0]+2, dp[i-1][1]+1);
            }
        }
        printf("%d\n", min(dp[len][0], dp[len][1]+1));
    }
    return 0;
}
