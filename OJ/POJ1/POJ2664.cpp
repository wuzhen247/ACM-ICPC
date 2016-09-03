#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int k,m,r,c;
char sk[105][6],sc[105][6];
bool f;
int main()
{
    int i,j,num;
    while(scanf("%d",&k)&&k)
    {
        scanf("%d",&m);
        for(i=0;i<k;i++)
          scanf("%s",sk[i]);
        f=true;
        while(m--)
        {
            num=0;
            scanf("%d%d",&c,&r);
            for(i=0;i<c;i++)
                scanf("%s",sc[i]);
            if(f)
            {
                for(i=0;i<c;i++)
                {
                    for(j=0;j<k;j++)
                    {
                        if(strcmp(sc[i],sk[j])==0)
                        {
                            num++;
                            break;
                        }
                    }
                }
            if(num<r)
              f=false;
            }     
        }
        if(f)
          printf("yes\n");
        else
          printf("no\n");
    }
    return 0;
}


