#include <stdio.h>
#define MAX_NUM 100000

int main()
{
    int i;
    double num[MAX_NUM];
    double sum=0.0;
    int index;
    num[0] = 0.0;
    for(i=1;i<MAX_NUM;i++)
    {
        sum+=1.0/(i+i);
        num[i]=sum;
    }
    printf("Cards  Overhang\n");
    while(scanf("%d",&index)!=EOF)
    printf("%5d%10.3lf\n",index,num[index]);
    return 0;
}

