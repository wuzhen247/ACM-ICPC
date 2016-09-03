#include<iostream>  
#include<cstring> 
using namespace std;  
  
const int large=200030;  
  
typedef class  
{  
    public:  
        int x;  
        int step;  
}pos;  
  
int n,k;  
bool vist[large];   //����ϴ󣬱��뿪Ϊȫ�����飬��Ȼ�϶�RE   
pos queue[large];   
  
void BFS(void)  
{  
    int head,tail;  
    queue[head=tail=0].x=n;  
    queue[tail++].step=0;
    
    vist[n]=true;  
  
    while(head<tail)  
    {  
        pos w=queue[head];  
  
        if(w.x==k)  
        {  
            cout<<w.step<<endl;  
            break;  
        }  
        if(w.x-1>=0 && !vist[w.x-1])     //w.x-1>=0  �Ǽ�֦   
        {  
            vist[w.x-1]=true;  
            queue[tail].x=w.x-1;  
            queue[tail++].step=w.step+1;  
        }  
        if(w.x<=k && !vist[w.x+1])     //w.x<=k  �Ǽ�֦   
        {  
            vist[w.x+1]=true;  
            queue[tail].x=w.x+1; 
            queue[tail++].step=w.step+1;  
        }  
        if(w.x<=k && !vist[2*w.x])     //w.x<=k  �Ǽ�֦   
        {  
            vist[2*w.x]=true;  
            queue[tail].x=2*w.x;  
            queue[tail++].step=w.step+1;  
        }
		head++;  
    }  
  
    return;  
}  
  
int main(void)  
{  
    while(cin>>n>>k)  
    {  
        memset(vist,false,sizeof(vist));  
        BFS();  
    }  
      
    return 0;  
}  

