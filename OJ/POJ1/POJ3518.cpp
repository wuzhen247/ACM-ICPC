//nÁ½¶ËµÄËØÊı¾àÀë
#include<iostream>
#include<cstring>
#include<cstdio>
#define N 1299809
using namespace std;
int p[N],c[N],np;
bool prime[N];
void getprime()
{
    int i,j;
    memset(prime,true,sizeof(prime));
    prime[0]=prime[1]=false;
    np=0;
    for(i=2;i<N;i++)
    {
        if(prime[i])
            p[++np]=i;
        for(j=1;j<=np&&p[j]*i<N;j++)
        {
            prime[p[j]*i]=false;
            if(i%p[j]==0)
            break;
        }
    }
}

int main()
{
    int i,j,n;
    getprime();
    memset(c,0,sizeof(c));
    for(i=1;i<np;i++)
    {
        for(j=p[i]+1;j<p[i+1];j++)
          c[j]=p[i+1]-p[i];
    }
    while(scanf("%d",&n)&&n)
    {
        printf("%d\n",c[n]);
    }
    return 0;
}
