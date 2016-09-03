#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	char s[260];
	int i,j,k,n;
	long long sum=0;
	while(gets(s+1)&&s[1]!='#')
	{
		sum=0;
		n=strlen(s+1);
		for(i=1;i<=n;i++)
		{
			if(s[i]>='A'&&s[i]<='Z')
				sum+=i*(s[i]-'A'+1);
			else
				continue;
		}
		printf("%d\n",sum);
	}
	return 0;
}
