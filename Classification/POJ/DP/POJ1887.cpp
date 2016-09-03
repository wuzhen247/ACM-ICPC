//最长不升子序列
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 100000+5;
const int INF = 10000000;
int t, n, tm, a[N], dp[N], ans;

int bsearch(int l, int r, int x)
{
    int mid;
    while (l < r)
    {
        mid  = (l+r) >> 1;
        if (x <= dp[mid]) r = mid;
        else l = mid+1;
    }
    return l;
}
int main()
{
    t = 1;
    while (scanf("%d", &tm) && tm != -1)
    {
        a[1] = tm, n = 1;
        while (scanf("%d", &tm) && tm != -1)
            a[++n] = tm;
        for (int i = 1; i <=n/2; i++)
            swap(a[i], a[n-i+1]);
        ans = 1;
        dp[1] = a[1];
        for (int i = 2; i <= n; i++)
        {
            
            if (a[i] >= dp[ans])
                dp[++ans] = a[i];
            else
            {
                int id = bsearch(1, ans, a[i]);
                dp[id] = a[i];
            }
            

            /*
            dp[ans] = INF;
            int id = bsearch(1, ans, a[i]);
            if (id == ans)  ans++;
            dp[id] = a[i];
            */
        }
        printf("Test #%d:\n  maximum possible interceptions: %d\n\n", t++, ans);  
    }
    return 0;
}
