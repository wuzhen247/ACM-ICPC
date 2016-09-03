#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
vector<string>s;
int main()
{
	int n,w,r,id;
	string name;
	scanf("%d",&n);
	while(n--)
	{
		cin>>name;
		s.push_back(name);
	}
	scanf("%d,%d",&w,&r);
	id=w-1;
	while(s.size())
	{
		id=(id+r-1)%s.size();
		cout<<s[id]<<endl;
		s.erase(s.begin()+id);
	}
	return 0;
}

