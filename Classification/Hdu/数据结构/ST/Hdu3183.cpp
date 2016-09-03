/*STÀ„∑®*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
const int N = 1000+5;
int a[N], st[N][10], ans[N];
char s[N];
int n, m;

void init()
{
    for (int i = 1; i <= n; i++)
        st[i][0] = i;
    for (int i = 1; (1<<i) <= n; i++)
    {
        for (int j = 1; j+(1<<i)-1 <= n; j++)
        {      
            if (a[st[j][i-1]] <= a[st[j+(1<<(i-1))][i-1]])
                st[j][i] = st[j][i-1];
            else
                st[j][i] = st[j+(1<<(i-1))][i-1];
        }
    }
}

int get(int l, int r)
{
    int k = (log(r-l+1.0)/log(2.0));
    if (a[st[l][k]] <= a[st[r-(1<<k)+1][k]])
        return st[l][k];
    return st[r-(1<<k)+1][k];
}

int main()
{
    while (scanf("%s %d", s+1, &m) != EOF)
    {
        n = strlen(s+1);
        if (n == m)
        {
            printf("0\n");
            continue;
        }
        for (int i = 1; i <= n; i++)
            a[i] = (s[i]-'0');
        init();
        int l = 1, r = m+1, id;
        m = n-m;
        for (int i = 1; i <= m; i++)
        {
            id = get(l, r);
            ans[i] = a[id];
            l = id+1, r = (n-m)+i+1;
        }
        int i;
        for (i = 1; i < m; i++)
            if (ans[i]) 
                break;
        for (; i <= m; i++)
            printf("%d", ans[i]);
        printf("\n");
    }
    return 0;
}
