#include<iostream>
using namespace std;
int main()
{
	char a[40];
	int y,i,j;
	while(1)
	{
		y=0;
		cin.getline(a,40);
		i=0;
		while(a[i])
		{
			i++;
		}
		i--;
		j=1;
		while(i+1)
		{
			y+=(a[i--]-'0')*((1<<j++)-1);
		}
		if(y==0)
			return 0;
		cout<<y<<endl;
	}
	return 0;
}

