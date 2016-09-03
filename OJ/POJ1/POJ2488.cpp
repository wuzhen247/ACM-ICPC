//dfs 简单题 注意方向数组要按字典序构造
#include<iostream>
#include<cstring>
#include<cstdio>
#define N 28
using namespace std;
bool vis[N][N];
char path[66];
int dir[8][2]={{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};
int p,q,t;
bool judge(int x,int y)
{
    if(x>0&&x<=q&&y>0&&y<=p&&!vis[y][x])
      return true;
    return false;
}

bool dfs(int x,int y,int n)
{
    if(n==p*q)
      return true;
  //  vis[y][x]=true;
    for(int i=0;i<8;i++)
    {
        int x1=dir[i][0]+x;
        int y1=dir[i][1]+y;
        if(judge(x1,y1))
        {
            vis[y1][x1]=true;
            path[2*n]=char('A'+x1-1);
            path[2*n+1]=char('1'+y1-1);
            if(dfs(x1,y1,n+1))
              return true;
            vis[y1][x1]=false;
        }
    }
    return false;
}
            
        

int main()
{
    int Case;
    scanf("%d",&t);
    for(Case=1;Case<=t;Case++)
    {
        scanf("%d%d",&p,&q);
        memset(vis,false,sizeof(vis));
        memset(path,0,sizeof(path));
        vis[1][1]=true;
        path[0]='A';
        path[1]='1';
        printf("Scenario #%d:\n",Case);
        if(dfs(1,1,1))
        {
            int i,len=strlen(path);
            for(i=0;i<len;i++)
              printf("%c",path[i]);
            printf("\n\n");
        }
        else
          printf("impossible\n\n");
    }
    return 0;
}
