#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
    bool f1[6],f2[6];
    char s1[6],s2[6];
    int i,j,a,b,t;
    scanf("%d",&t);
    while(t--)
    {
        a=b=0;
        scanf("%s",s1);
        scanf("%s",s2);
        memset(f1,false,sizeof(f1));
        memset(f2,false,sizeof(f2));
        for(i=0;i<4;i++)
        {
            if(s1[i]==s2[i])
            {
                a++;
                f1[i]=f2[i]=true;
            }
        }
        for(i=0;i<4;i++)
        {
            if(f2[i])
              continue;
            for(j=0;j<4;j++)
            {
                if(f1[j])
                  continue;
                if(s2[i]==s1[j])
                {
                    f1[j]=true;
                    b++;
                    break;
                }
            }
        }
        printf("%dA%dB\n",a,b);
    }
    return 0;
}


