/*Hdu39944,杨辉三角路径和的最小值，有模除，找公式+Lucas定理+预处理*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;
const int N = 10000+3;

int n, k, p, c[10002][1235], np;
bool flag[N];
int prime[N], num[N];
void getprime()
{
    memset(flag, true, sizeof(flag));
    np = 0;
    for (int i = 2; i < N; i++)
    {
        if (flag[i])
          prime[++np] = i;
        for (int j = 1; j <= np && i* prime[j] < N; j++)
        {
            flag[i*prime[j]] = false;
            if (i % prime[j] == 0)
              break;
        }
    }
    memset(num, 0, sizeof(num));
    int count = 0;
    for (int i = 2; i < N; i++)
      if (flag[i])
        num[i] = ++count;
}

void init()
{
    getprime();
    
    /*
    cout<<prime[np]<<endl;
    cout<<np<<endl;
    cout<<num[9973]<<endl;*/
    for (int j = 1; j <= np; j++)
    {
        c[0][j] = 1, c[1][j] = 1;
        for (int i = 2; i <= 10000; i++)
          c[i][j] = c[i-1][j] * i % prime[j];
    }
}

int powmod(int a, int n, int p)
{
    int ans = 1, tm = a % p;
    while (n)
    {
        if (n & 1)
          ans = ans * tm % p;
        tm = tm * tm % p;
        n >>= 1;
    }
    return ans;
}

int Lucas(int n, int m)
{
    int ans = 1;
    while (n && m)
    {
        int a = n % p, b = m % p;
        //cout<<a<<' '<<b<<endl;
        if (a < b)  return 0;
        //cout<<c[a][1]<<endl;
        ans = (ans*c[a][num[p]]%p) * powmod(c[b][num[p]]*c[a-b][num[p]], p-2, p)%p;
        n /= p, m /= p;
    }
    return ans;
}
int main()
{
    init();
    int cas = 0;
    while (scanf("%d%d%d", &n, &k, &p) != EOF)
    {
        if (k <= n/2)
          k = n - k;
        //Lucas(n+1, k+1);
        //cout<<Lucas(n+1, k+1)<<endl;
        printf("Case #%d: %d\n", ++cas, (k % p + Lucas(n+1, k+1)%p)%p);
    }
    return 0;
}
