//单调递增子序列
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int N = 10000+5;
char s[N], dp[N];
int t, len;

int bisearch(int n, char k)
{
    int low = 1, high = n, mid;
    while (low <= high)
    {
        mid = (low+high)>>1;
        if (dp[mid] < k && k <= dp[mid+1])
          return mid+1;
        else if (k < dp[mid])
          high = mid-1;
        else
          low = mid+1;
    }
}

int LIS()
{
    int ans = 1, i, j;
    dp[1] = s[1];
    for (i = 2; i <= len; i++)
    {
        if (s[i] <= dp[1])
          j = 1;
        else if (s[i] > dp[ans])
          j = ++ans;
        else
          j = bisearch(ans, s[i]);
        dp[j] = s[i]; 
    }
    return ans;
}

int main()
{
    int ans, i, j;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%s", s+1);
        len = strlen(s+1);
        printf("%d\n", LIS());
    }
    return 0;
}
