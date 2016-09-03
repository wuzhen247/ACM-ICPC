#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int a[100];
char b[100][15],s[15];
int main()
{
    int n,i,j;
    bool f;
    while(scanf("%d",&n)&&n)
    {
        a[0]=n;
        i=1,j=0;
        getchar();
        while(gets(s)&&strcmp(s,"right on"))
        {
            strcpy(b[j++],s);
            scanf("%d",&a[i++]);
            getchar();
        }
        f=true;
        for(i=0;i<j;i++)
        {
            switch(b[i][4])
            {
                case 'h':
                    if(a[j]>=a[i])
                    {
                      f=false;
                     // cout<<"Yes\n";
                    }
                    break;
                case 'l':
                    if(a[i]>=a[j])
                    {
                      f=false;
                     // cout<<"Yes\n";
                    }
                    break;
            }
            if(f==false)
              break;
        }
        if(f)
          printf("Stan may be honest\n");
        else
          printf("Stan is dishonest\n");
    }
    return 0;
}
