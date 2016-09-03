//任意两数之和不大于s
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    int a[20020],num,i,j,n,s;
    scanf("%d%d",&n,&s);
    for(i=0;i<n;i++)
      scanf("%d",&a[i]);
    sort(a,a+n);
    j=n-1;
    num=0;
    for(i=0;i<n;i++)
    {
        if(a[i]>s)
          break;
        while(a[i]+a[j]>s)
          j--;
        if(j<=i)
          break;
        num+=j-i;
    }
    printf("%d\n",num);
    return 0;
}

