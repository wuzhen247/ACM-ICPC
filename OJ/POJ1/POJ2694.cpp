//ÆË¿ËÅÆÄ£Äâ 
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
char ch[5];
int value[5];

bool Suit()
{
	int i;
	for(i=0;i<4;i++)
	{
		if(ch[i]!=ch[i+1])
		  return false;
	}
	return true;
}

bool Straight()
{
	bool f=true;
	for(int i=1;i<5;i++)
	  if(value[i]-value[i-1]!=1)
		f=false;
	if(f) return true;
	if(value[0]==1&&value[1]==10&&value[2]==11&&value[3]==12&&value[4]==13)
	  return true;
	else
	  return false;
}
bool Four()
{
	if(value[0]==value[1]&&value[1]==value[2]&&value[2]==value[3]&&value[3]!=value[4])
	  return true;
	if(value[0]!=value[1]&&value[1]==value[2]&&value[2]==value[3]&&value[3]==value[4])
	  return true;
	return false;
}

bool House()
{
	if(value[0]==value[1]&&value[1]!=value[2]&&value[2]==value[3]&&value[3]==value[4])
	  return true;
	if(value[3]==value[4]&&value[0]==value[1]&&value[1]==value[2]&&value[2]!=value[3])
	  return true;
	return false;
}

bool Three()
{
	if(value[0]!=value[1]&&value[1]!=value[2]&&value[2]==value[3]&&value[3]==value[4])
	  return true;
	if(value[3]!=value[4]&&value[3]!=value[2]&&value[0]==value[1]&&value[1]==value[2])
	  return true;
	return false;
}

bool Two()
{
	if(value[0]==value[1]&&value[1]!=value[2]&&value[2]==value[3]&&value[3]!=value[4]) return true;
	if(value[0]==value[1]&&value[1]!=value[2]&&value[2]!=value[3]&&value[3]==value[4]) return true;
	if(value[0]!=value[1]&&value[1]==value[2]&&value[2]!=value[3]&&value[3]==value[4]) return true;
	return false;
}

bool One()
{
	if(value[0]==value[1]||value[1]==value[2]||value[2]==value[3]||value[3]==value[4])
	  return true;
	return false;
}

int main()
{
	int t,i,j;
	char tm,s[20];
	cin>>t;
	getchar();
	while(t--)
	{
		gets(s);
		for(i=0;i<5;i++)
		{
			ch[i]=s[3*i];
			switch(s[3*i+1])
			{
				case 'A':value[i]=1;break;
				case 'X':value[i]=10;break;
				case 'J':value[i]=11;break;
				case 'Q':value[i]=12;break;
				case 'K':value[i]=13;break;
				default:value[i]=s[3*i+1]-'0';break;
			}
		}
		sort(value,value+5);
		if(Suit()&&Straight())
		{
			printf("1000\n");
			continue;
		}
		if(Four()) 
		{
			printf("750\n");
			continue;
		}
		if(House())
		{
			printf("500\n");
			continue;
		}
		if(Suit())
		{
			printf("350\n");
			continue;
		}
		if(Straight())  
		{
			printf("250\n");
			continue;
		}
		if(Three()) 
		{
			printf("200\n");
			continue;
		}
		if(Two())  
		{
			printf("100\n");
			continue;
		}
		if(One())
		{
			printf("50\n");
			continue;
		}
		printf("0\n");
	}
	return 0;
}
