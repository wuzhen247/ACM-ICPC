//poj3264 œ° Ë±Ì 
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#define N 500010

using namespace std;

int a[N], minc[N][20], maxc[N][20];
int n, q;

void Init()
{
    int i, j, m;
    for(i=1; i<=n; ++i)
        minc[i][0] = maxc[i][0] = a[i];
    m = int(log(n*1.0)/log(2.0));
    for(i=1; i<=m; ++i)
        for(j=n; j>=1; --j)
        {
            maxc[j][i] = maxc[j][i-1];
            minc[j][i] = minc[j][i-1];
            if(j+(1<<(i-1)) <= n)
            {
                maxc[j][i] = max(maxc[j][i], maxc[j+(1<<(i-1))][i-1]);
                minc[j][i] = min(minc[j][i], minc[j+(1<<(i-1))][i-1]);
            }
                
        }
}

int query(int l, int r)
{
    int m = int(log(r-l+1.0)/log(2.0));
    return max(maxc[l][m], maxc[r-(1<<m)+1][m])-min(minc[l][m], minc[r-(1<<m)+1][m]);;
}

int main()
{
    int l, r;
    int i;
    scanf("%d %d", &n, &q);
    for(i=1; i<=n; ++i)
        scanf("%d", &a[i]);
    Init();
    while(q--)
    {
        scanf("%d %d", &l, &r);
        printf("%d\n", query(l, r));
    }
    return 0;
}

