/*�������������ɲ�������������ķ�����*/ 
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
		for(j=3;j<=n/2;j+=2)//�������������֮�� 
		{
			if((n/j-j/2)<0)
				break;
			if(n%j==0)
				count++;
		}
		for(j=2;j<=n/2;j+=2)//���ż��������֮�� 
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
