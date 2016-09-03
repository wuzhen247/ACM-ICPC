#include<iostream>
using namespace std;
int main()
{
	int n,a,b,c,d,e,f,g,h,i,j,k,temp1,temp2,temp3,y;
	cin>>n;
	for(k=0;k<n;k++)
	{
		cin>>a>>b>>c>>d>>e>>f>>g>>h>>i;
		if(i==0)
		{		
			cout<<a<<endl;
			continue;
		}
		else if(i==1)
		{
			cout<<b<<endl;
			continue;
		}
		else if(i==2)
		{
			cout<<c<<endl;
			continue;
		}
		temp1=a,temp2=b,temp3=c;
		for(j=3;j<=i;j++)
		{
			if(j%2==0)
			{
				y=(f*temp3-d*temp2+e*temp1)%h;
				if(y<0)
					y+=h;
				temp1=temp2,temp2=temp3,temp3=y;
			}
			else
			{
				y=(d*temp3+e*temp2-f*temp1)%g;
				if(y<0)
					y+=g;
				temp1=temp2,temp2=temp3,temp3=y;
			}
		}
		cout<<y<<endl;
	}
	return 0;
}
				


