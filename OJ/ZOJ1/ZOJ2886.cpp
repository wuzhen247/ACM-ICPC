#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    int n,i,count,len;
    char s[1100],tm;
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
                printf("%d%c",count,tm);
                count=0;
                tm=s[i];
            }
            count++;
        }
        printf("%d%c\n",count,tm);
    }
    return 0;
}

