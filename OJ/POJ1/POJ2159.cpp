//º”√‹ºº ı
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
char s1[105],s2[105];
int a[30],b[30];
main()
{
    int len,i,j;
    bool f;
    while(scanf("%s%s",s1,s2)!=EOF)
    {
        len=strlen(s1);
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(i=0;i<len;i++)
        {
            a[int(s1[i]-'A'+1)]++;
            b[int(s2[i]-'A'+1)]++;
        }
        f=false;
        sort(a+1,a+27);
        sort(b+1,b+27);
        for(i=1;i<=26;i++)
        {
            if(a[i]!=b[i])
            {
                f=true;
                break;
            }
        }
        if(!f)
         printf("YES\n");
        else
         printf("NO\n");
    }
    return 0;
}

