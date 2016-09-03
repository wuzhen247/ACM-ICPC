#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    char a[70];
    int len,i,j,b,tm,c[70];
    bool f;
    while(scanf("%s",a)!=EOF)
    {
        len=strlen(a);
        b=len+1;
        for(i=0;i<len;i++)
          c[i]=int(a[i]-'0');
        bool f=true;
        for(i=len-1;i>=0;i--)
        {
            c[i]*=b;
        }
        for(i=len-1;i>0;i--)
        {
            if(c[i]%10!=9)
            {
                f=false;
                break;
            }
            c[i-1]+=c[i]/10;
        }
        if(c[0]!=9)
            f=false;
        if(f)
          printf("%s is cyclic\n",a);
        else
          printf("%s is not cyclic\n",a);
    }
    return 0;
}
