#include<stdio.h>
int main()
{
    int cases,a,b;
    scanf("%d",&cases);
    while(cases--)
	{
       scanf("%d%d",&a,&b);
       a>=b?printf("MMM BRAINS\n"):printf("NO BRAINS\n");
    }
    return 0;
}
