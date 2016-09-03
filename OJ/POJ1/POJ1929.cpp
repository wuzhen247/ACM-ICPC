#include<cstring>
#include<cstdio>
using namespace std;

char s[100];
double tol,fat;
const double eps=10e-9;
int a[4]={4,4,4,7};

void input()
{
  int temp;
  char ch;
  sscanf(s,"%d%c",&temp,&ch);
  bool f;
  int p=0,c=0;
  if(ch=='%')
  {
    f=true;
    p+=temp;
  }
  else if(ch == 'g')
  {
    f=false;
    c+=temp*9;
    fat+=temp*9;
  }
  else
  {
    f=false;
    c+=temp;
    fat+=temp;
  }
  int tm=temp;
  for(int i=0;i<4;i++)
  {
    scanf("%d%c",&temp,&ch);
    if(ch=='%')
      p+=temp;
    else if(ch=='g')
      c+=temp*a[i];
    else
      c+=temp;
  }
  tol+=c/(100.0-p)*100;
  if(f)
    fat+=c/(100.0-p)*tm;
}

int main()
{
  while(scanf("%s",s),strcmp(s,"-"))
  {
    tol=fat=0;
    do
    {
      input();
    }while(scanf("%s",s),strcmp(s,"-"));
    printf("%d%%\n", int(fat/tol*100+0.5+eps));
  }
}