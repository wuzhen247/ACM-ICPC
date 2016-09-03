//双最大子段和
#include<iostream>
#include<cstdio>
#include<cstring>
#define INF 1000000000
using namespace std;
int t,n,a[50050],b[50050];
int main()
{
    int i,j,sum,temp,ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        sum=0;
        temp=ans=-INF;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
            if(sum>temp)
              temp=sum;
            b[i]=temp;
            if(sum<0)
              sum=0;
        }
        temp=-INF;
        sum=0;
        for(i=n;i>=2;i--)
        {
            sum+=a[i];
            if(sum>temp)
              temp=sum;
            if(b[i-1]+temp>ans)
              ans=b[i-1]+temp;
            if(sum<0)
              sum=0;
        }
        printf("%d\n",ans);
    }
    return 0;
}
        
