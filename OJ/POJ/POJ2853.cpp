/*求任意正整数可拆成连续正整数的方法数*/ 
#include<iostream>
using  namespace std;
int main()
{
	int N,i,n,j,count,temp;
	cin>>N;
	for(i=0;i<N;i++)
	{
		count=0;
		cin>>temp>>n;
		for(j=3;j<=n/2;j+=2)//拆成奇数个整数之和 
		{
			if((n/j-j/2)<0)
				break;
			if(n%j==0)
				count++;
		}
		for(j=2;j<=n/2;j+=2)//拆成偶数个整数之和 
		{
			if((n/j-j/2)<0)
				break;
			if((double(n)/j-n/j)==0.5)
	   			count++;
		}
		cout<<temp<<' '<<count<<endl;
	}
	return 0;
}
