#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    int n0,n1,n2,n3,n4,i=0;
    while(scanf("%d",&n0)&&n0)
    {
        i++;
        n1=3*n0;
        if(n1%2)
          n2=(n1+1)/2;
        else
          n2=n1/2;
        n3=3*n2;
        n4=n3/9;
        printf("%d. ",i);
        if(n1%2)
          printf("odd ");
        else
          printf("even ");
        printf("%d\n",n4);
    }
    return 0;
}

