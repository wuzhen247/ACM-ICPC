//电话号码转换问题，注意print函数
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
char ch;
int a[100010]={0};
int n,i,j;
int main()
{	
	int num=0;
	bool flag=false;
	memset(a,0,sizeof(a));
	scanf("%d",&n);
	getchar();
	for(i=0;i<n;i++)
	{
		ch=getchar();
		while(ch!='\n')
		{
			switch(ch)
			{
				case '-':break;
				case 'A':case 'B':case 'C':a[i]=a[i]*10+2;break;
				case 'D':case 'E':case 'F':a[i]=a[i]*10+3;break;
				case 'G':case 'H':case 'I':a[i]=a[i]*10+4;break;
				case 'J':case 'K':case 'L':a[i]=a[i]*10+5;break;
				case 'M':case 'N':case 'O':a[i]=a[i]*10+6;break;
				case 'P':case 'R':case 'S':a[i]=a[i]*10+7;break;
				case 'T':case 'U':case 'V':a[i]=a[i]*10+8;break;
				case 'W':case 'X':case 'Y':a[i]=a[i]*10+9;break;
				default:a[i]=a[i]*10+(ch-'0');break;
			}
			ch=getchar();	
		}
	//	cout<<a[11]<<endl;
	}
	sort(a,a+n);
//	for(i=0;i<n;i++)
//		cout<<a[i]<<'\n';
    for(i=0;i<n-1;i++)
	{
		num=1;
		while(a[i]==a[i+1]&&i<n-1)
		{
			num++;
			i++;
		}
		if(num>1)
		{
			printf("%03d-%04d %d\n",a[i]/10000,a[i]%10000,(int)num);
			flag=true;
		}
	}
	if(flag==false)
	cout<<"No duplicates.\n";
	return 0;
}



				
	
	
	
