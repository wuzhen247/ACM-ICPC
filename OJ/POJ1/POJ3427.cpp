#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
    int n,l,a,ans;
    while(scanf("%d%d",&n,&l)!=EOF)
    {
        ans=0;
        while(n--)
        {
            scanf("%d",&a);
            if(a%l==0)
              continue;
            ans=max(ans,l-a%l);
        }
        printf("%d\n",ans);
    }
    return 0;
}
