#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

bool f1,f2;
int a[15][15];

int main()
{
    int n,m,i,j,bn,cn;
    while(scanf("%d%d",&n,&m)&&(m||n))
    {
        memset(a,1,sizeof(a));
        f1=true,f2=false;
        for(i=1;i<=n;i++)
          for(j=1;j<=m;j++)
          {
              scanf("%d",&a[i][j]);
              if(a[i][j]==0)
              {
                f1=false;
                if(a[i][j-1]==0||a[i-1][j]==0)
                  f2=true;
              }
          }
        if(f1||f2)
          printf("No\n");
        else
          printf("Yes\n");
    }
    return 0;
}

