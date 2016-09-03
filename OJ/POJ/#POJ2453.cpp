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
		small=x&-x;             //找出最右边的1，有k个连续1           
		rip=x+small;		
		ones=x^rip;		//将中间的连续1变为k+1个
		ones=(ones>>2)/small;	//将最低的(k-1)个0变为1，右移2，形成k-1个1，在置最低位
		cout<<(rip|ones)<<endl;
	}
	return 0;
}

