#include<iostream>
#include<cstring>
#include<cstdio>
#include<map>
using namespace std;
char s[85];
int main()
{
    bool f;
    int i,j,len;
    while(scanf("%s",s)&&s[0]!='*')
    {
        f=true;
        len=strlen(s);
        if(len<=2)
        {
            printf("%s is surprising.\n",s);
            continue;
        }
        for(i=0;i<=len-2;i++)
        {
            map<string,bool>flag;
            for(j=0;j<=len-i-2;j++)
            {
                char p[3]={s[j],s[i+j+1],'\n'};
                if(!flag[p])
                  flag[p]=true;
                else
                {
                    f=false;
                    break;
                }
            }
            if(!f)
                break;
        }
        if(f)
          printf("%s is surprising.\n",s);
        else
          printf("%s is NOT surprising.\n",s);
    }
    return 0;
}

