#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
bool p[500005];
void makeprime()
{
    memset(p,true,sizeof(p));
    p[0]=p[1]=false;
    int i,j;
    for(i=2;i<500005;i++)
    {
        if(p[i])
        {
            for(j=i+i;j<500005;j+=i)
              p[j]=false;
        }
    }
}
int main()
{
    int a,b,ans,i,j;
    makeprime();
    while(scanf("%d%d",&a,&b)&&!(a==-1&&b==-1))
    {
        if(b<2)
        {
          printf("0\n");
          continue;
        }
        if(a<2)
          a=2;
        ans=0;
        for(a;a<=b;a++)
        {
            if(p[a])
              ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
