//�󵽴��s�����ٲ�������������1��ʼһ�ε���1���г���ʼ���ݣ����ֹ��ɣ�j����ֵ���2
#include<iostream>
using namespace std; 
int main()
{
	int s,n,i,j,temp;
	cin>>s;
	i=1;
	while(i*(i+1)/2<s)
		i++;
	temp=i*(i+1)/2;
	if(temp==s)
	{
		cout<<i<<endl;
		return 0;
	}
	if(s%2==0)
	{
		if(temp%2==0)
		{
			cout<<i<<endl;
			return 0;
		}
		if(((i+1)*(i+2)/2)%2==0)
		{
			cout<<i+1<<endl;
			return 0;
		}
		cout<<i+2<<endl;
		return 0;
	}
	if(temp%2==1)
	{
		cout<<i<<endl;
		return 0;
	}
	if(((i+1)*(i+2)/2)%2==1)
	{
		cout<<i+1<<endl;
		return 0;
	}
	cout<<i+2<<endl;
	return 0;
}
	

