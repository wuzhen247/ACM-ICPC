//next_permutatona
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

char s[20];

bool cmp(char a, char b)
{
	if(a>='A'&&a<='Z'&&b>='A'&&b<='Z')
	  return a<b;
	if(a>='a'&&a<='z'&&b>='a'&&b<='z')
	  return a<b;
	if(a>='A'&&a<='Z'&&b>='a'&&b<='z')
	  return a+'a'-'A'<=b;
	if(a>='a'&&a<='z'&&b>='A'&&b<='Z')
	  return a<b+'a'-'A';
}

int main()
{
	int t,len;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s);
		len=strlen(s);
		sort(s,s+len,cmp);
		do
		{
			printf("%s\n",s);
		}while(next_permutation(s,s+len,cmp));
	}
	return 0;
}
