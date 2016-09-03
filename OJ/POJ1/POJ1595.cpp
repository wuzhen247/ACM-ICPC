#include<istream>
#include<cstdio>
#include<cstring>
using namespace std;
int prime[1001],isprime[1001];
int N,C;
int len;
void prim(int N)
{
    memset(prime,0,sizeof(prime));
    memset(isprime,0,sizeof(isprime));
    for(int m=0;m<=N;m++)
    {
      prime[m]=1;
    }
    prime[0]=0;
    for(int i=2;i<=N;i++)
    {
        if(prime[i])
        {
            for(int j=2;i*j<=N;j++)
            {
                prime[i*j]=0;
            }
        }
    }
    len=0;
    for(int i=0;i<=N;i++)
    {
        if(prime[i])
        {
            isprime[len++]=i;
        }
    }
}
int main()
{
    while(scanf("%d %d",&N,&C)!=EOF)
    {
        printf("%d %d:",N,C);
        prim(N);
        if(2*C>=len)
        {
            for(int i=0;i<len;i++)
            printf(" %d",isprime[i]);
            printf("\n\n");
        }
        else
        {
            if(len%2==0)
            {
                for(int i=(len-2*C)/2,t=1;t<=2*C;i++,t++)
                printf(" %d",isprime[i]);
            }
            else
            {
             for(int i=(len-(2*C-1))/2,t=1;t<=2*C-1;i++,t++)
              printf(" %d",isprime[i]);
            }
            printf("\n\n");
        }
    }
    return 0;
}
