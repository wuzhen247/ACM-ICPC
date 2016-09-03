#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    char s[15];
    bool f;
    int i,j,sum,id,tm,x;
    scanf("%s",s);
    sum=0;
    f=false;
    for(i=0,j=10;i<=9;j--,i++)
    {
        if(s[i]=='?')
        {
            id=i;
            continue;
        }
        if(s[i]=='X')
        {
            sum+=10*(10-i);
        }
        else
        {
            sum+=(s[i]-'0')*(10-i);
        }
    }
    tm=sum;
    for(i=0;i<10;i++)
    {
        tm=sum;
        tm+=i*(10-id);
        if(tm%11==0)
        {
          f=true;
          x=i;
          break;
        }
    }
    if(f==false&&id==9)
    {
        sum+=10*(10-id);
        if(sum%11==0)
        {
          f=true;
          x=10;
        }
    }
    if(f==false)
      printf("-1\n");
    else if(x==10)
      printf("X\n");
    else
      printf("%d\n",x);
    return 0;
}
