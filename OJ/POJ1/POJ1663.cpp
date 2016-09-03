#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    int n,x,y;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%d",&x,&y);
        if(x==y||x-y==2)
        {
            if(x%2)
              printf("%d\n",x+y-1);
            else
              printf("%d\n",x+y);
        }
        else
            printf("No Number\n");
    }
    return 0;
}
