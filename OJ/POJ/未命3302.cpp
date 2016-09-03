#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int i,j,k,temp1,temp2,n,count;
	char s1[102],s2[102];
	cin>>n;
	for(k=0;k<n;k++)
	{
		count=0;
		cin>>s1>>s2;
		temp1=strlen(s1);
		temp2=strlen(s2);
		i=0;
		for(j=0;j<temp2;j++)
		{
			while(i<temp1)
				if(s2[j]==s1[i])
				{
					count++;
					i++;
					break;
				}
				i++;			
		}
		if(count==temp2)
		{
			cout<<"YES"<<endl;
			continue;
		}
		count=0;
		i=temp1-1;
		for(j=0;j<temp2;j++)
		{
			while(i>=0)
				if(s2[j]==s1[i])
				{
					count++;
					i--;
					break;
				}
				i--;
		}
		if(count==temp2)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
