#include<iostream>
using namespace std;
int main()
{
	int x;
	unsigned int small,rip,ones;
	while(cin>>x)
	{
		if(x==0)
			continue;
		small=x&-x;             //�ҳ����ұߵ�1����k������1           
		rip=x+small;		
		ones=x^rip;		//���м������1��Ϊk+1��
		ones=(ones>>2)/small;	//����͵�(k-1)��0��Ϊ1������2���γ�k-1��1���������λ
		cout<<(rip|ones)<<endl;
	}
	return 0;
}

