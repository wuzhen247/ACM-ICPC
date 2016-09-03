//最长公共子序列
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int N = 1000+5;

int t, len1, len2, ans, dp[N][N];
char s1[N], s2[N];

int main()
{
    scanf("%d", &t);
    int i, j;
    while (t--)
    {
        scanf("%s%s", s1+1, s2+1);
        len1 = strlen(s1+1);
        len2 = strlen(s2+1);
        for (i = 1; i <= len1; i++)
          dp[i][0] = 0;
        for (j = 1; j <= len2; j++)
          dp[0][j] = 0;
        for (i = 1; i <= len1; i++)
          for (j = 1; j <= len2; j++)
            if (s1[i] == s2[j])
              dp[i][j] = dp[i-1][j-1]+1;
            else
              dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        printf("%d\n", dp[len1][len2]);
    }
    return 0;
}
