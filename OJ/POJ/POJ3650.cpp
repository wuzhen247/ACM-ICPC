#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	char a[85];
	int i=0;
	while(gets(a)&&a[0]!='#')
	{
		for(i=0;a[i]!=0;i++)
			switch(a[i])
			{
				case ' ':cout<<"%20";break;
				case '!':cout<<"%21";break;
				case '$':cout<<"%24";break;
				case '(':cout<<"%28";break;
				case '%':cout<<"%25";break;
				case ')':cout<<"%29";break;
				case '*':cout<<"%2a";break;
				default :cout<<a[i];break;
			}
		cout<<endl;
	}
	return 0;
}

