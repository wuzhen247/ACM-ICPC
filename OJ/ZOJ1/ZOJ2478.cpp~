#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    int n,i,count,len;
    char s[110],tm;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",s);
        len=strlen(s);
        tm=s[0],count=0;
        for(i=0;i<len;i++)
        {
            if(s[i]!=tm)
            {
                if(count==1)
                  printf("%c",tm);
                else
                  printf("%d%c",count,tm);
                count=0;
                tm=s[i];
            }
            count++;
        }
        if(count==1)
            printf("%c\n",tm);
        else
            printf("%d%c\n",count,tm);
    }
    return 0;
}
