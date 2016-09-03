#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char ch[25];
int main()
{
	int n,i,j,temp;
	while(scanf("%s",ch)!=EOF)
	{
		n=strlen(ch);
		for(i=0;i<n;i++)
		{
			switch(ch[i])
			{
				case'B':case'F':case'P':case'V': temp=ch[i+1];
					if(temp!='B'&&temp!='F'&&temp!='P'&&temp!='V')
						cout<<1;break;
				case'C':case'G':case'J':case'K':case'Q':
				case'S':case'X':case'Z':temp=ch[i+1];
					if(temp!='C'&&temp!='G'&&temp!='J'&&temp!='K'&&temp!='Q'&&temp!='S'&&temp!='X'&&temp!='Z')
						cout<<2;break;
				case'D':case'T':temp=ch[i+1];
					if(temp!='D'&&temp!='T')
						cout<<3;break;
				case'L':temp=ch[i+1];
					if(temp!='L')
						cout<<4;break;
				case'M':case'N':temp=ch[i+1];
					if(temp!='M'&&temp!='N') 
						cout<<5;break;
				case'R':if(ch[i+1]!='R') 
						cout<<6;break;
				default:break;
			}
		}
		cout<<endl;
	}
	return 0;
}


