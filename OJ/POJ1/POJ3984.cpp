#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[10][10];
bool f[10][10];
bool dfs(int x,int y)
{
    if(x==5&&y==5)
    {
        f[x][y]=true;
        return true;
    }
    if(x+1<=5&&y<=5&&a[x+1][y]==0&&f[x+1][y]==false)
    {
        f[x+1][y]=true;
        if(dfs(x+1,y))
          return true;
        else
        {
            f[x+1][y]=false;
        }
    }
    if(x<=5&&y+1<=5&&a[x][y+1]==0&&f[x][y+1]==false)
    {
        f[x][y+1]=true;
        if(dfs(x,y+1))
          return true;
        else
        {
            f[x][y+1]=false;
        }
    }
    return false;
}
void print(int x,int y)
{
    if(x==5&&y==5)
    {
        printf("(4, 4)\n");
        return ;
    }
    if(f[x][y]==true)
      printf("(%d, %d)\n",x-1,y-1);
    if(x<=5&&y+1<=5&&f[x][y+1])
      print(x,y+1);
    if(x+1<=5&&y<=5&&f[x+1][y])
      print(x+1,y);
    return ;
}
int main()
{
    memset(a,1,sizeof(a));
    memset(f,false,sizeof(f));
    int i,j;
    for(i=1;i<=5;i++)
      for(j=1;j<=5;j++)
        scanf("%d",&a[i][j]);
    f[1][1]=true;
    dfs(1,1);
    print(1,1);
    return 0;
}

