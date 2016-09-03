/*f1=1£¬f2=1£¬¼ÆËãfn=(f(n-1)*a+f(n-2)*b)%7;Ñ°ÕÒÑ­»·½Ú*/
#include<iostream>
using namespace std;
int d[50];
int serach(int a,int b,int n)
{
	int i;
	for(i=3;i<=50;i++)
	{
		d[i]=(a*d[i-1]+b*d[i-2])%7;
		if(d[i]==1&&d[i-1]==1)
			break;
	}
	return d[(n-1)%(i-2)+1];
}
int main()
{
	int a,b,n;
	d[1]=1,d[2]=1;
	while(cin>>a>>b>>n,a||b||n)
	{
		cout<<serach(a,b,n)<<endl;
	}
	return 0;
}
