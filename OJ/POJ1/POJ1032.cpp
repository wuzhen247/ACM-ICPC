//n拆分成不同的数之和，求积最大
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    int a[1000],i,j,sum,n,left,right;
    scanf("%d",&n);
    sum=0;
    a[0]=0;
    for(i=2,j=0;sum+i<=n;i++,j++)
    {
        a[j]=i;
        sum+=i;
    }
    right=j;
    if(sum!=n)
    {
        left=n-sum;
        for(j--;left>0&&j>=0;j--,left--)
          a[j]++;
        if(j==-1&&left==1)
          a[right-1]++;
    }
    for(i=0;i<right;i++)
      printf("%d ",a[i]);
    cout<<endl;
    return 0;
}

