#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int n,i,j,num,len;
	char a[1010],*p0,temp,b[1010];
	scanf("%d",&n);
	for(j=0;j<n;j++)
	{
		scanf("%s",a);
		char*p=new char[1001000];
		p0=p;
		for(i=0;a[i]!=0;i++)
		{
			temp=a[i];
			for(num=0;a[i]==a[i+1];i++)
				num++;
			num++;
			sprintf(b,"%d",num);
			len=strlen(b);
			sprintf(p,"%d",num);
			p+=len;
			*p=temp;
			p++;
		}
		p=0;
		printf("%s\n",p0);
		delete p;
	}
	return 0;
}



	
