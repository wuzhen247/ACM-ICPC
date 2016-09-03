//判断两个10位数以内的数相加进位数
//和中每位数是否小于两数对应位之和 
//注意1+9999 
#include<iostream>
using namespace std;
int main()
{
	long long n1,n2,sum,temp1,temp2,temp3,num;
	while(cin>>n1>>n2,n1||n2)
	{
		num=temp1=temp2=temp3=0;
		sum=n1+n2;
		while(n1/10&&n2/10)
		{
			temp1=n1%10;
			temp2=n2%10;
			temp3=sum%10;
			n1=n1/10,n2=n2/10,sum=sum/10;
			if(temp3<temp1+temp2)
				num++;
		}
		temp1=n1%10;
		temp2=n2%10;
		temp3=sum%10;
		if(temp3<temp1+temp2)
			num++;
		n1/=10,n2/=10,sum/=10;
		if(n1||n2)
		{
		if(n1>n2)
		{
			while(n1/10)
			{
				temp1=n1%10;
				temp3=sum%10;
				if(temp3<temp1)
					num++;
				n1/=10,sum/=10;
			}
			if(sum>n1)
				num++;
		}
		else
		{
			while(n2/10)
			{
				temp2=n2/10;
				temp3=sum%10;
				if(temp3<temp2)
					num++;
				n2/=10,sum/=10;
			}
			if(sum>n2)
				num++;
		}
		}
		if(num==0)
			cout<<"No carry operation."<<endl;
		if(num==1)
		{
			cout<<1<<" carry operation."<<endl;
		}
		if(num>1)
			cout<<num<<" carry operations."<<endl;
	}
	return 0;
}


