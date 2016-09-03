#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char s[150]={'\t'};
int main()
{
	s[';'] = 'L',s['L'] = 'K',s['K'] = 'J',s['J'] = 'H',s['H'] = 'G',s['G'] = 'F';
	s['F'] = 'D',s['D'] = 'S',s['S'] = 'A',s[','] = 'M',s['M'] = 'N',s['N'] = 'B';
	s['B'] = 'V',s['V'] = 'C',s['C'] = 'X',s['X'] = 'Z',s['['] = 'P',s['P'] = 'O';
	s['O'] = 'I',s['I'] = 'U',s['U'] = 'Y',s['Y'] = 'T',s['T'] = 'R',s['R'] = 'E';
	s['E'] = 'W',s['W'] = 'Q',s['/'] = '.',s['\''] = ';',s[']'] = '[',s['\\'] = ']';
	s['.'] = ',',s['='] = '-',s['-'] = '0',s['0'] = '9';s['9'] = '8';s['8'] = '7';
	s['7'] = '6';s['6'] = '5';s['5'] = '4';s['4'] = '3';s['3'] = '2';s['2'] = '1';
	s['1'] = '`';s[' ']=' ';

	int n,i,temp;
	char ch[100000];
	while(gets(ch)!=NULL)
	{
		n=strlen(ch);
		for(i=0;i<n;i++)
			  printf("%c",s[ch[i]]);
		cout<<endl;
	}
	return 0;
}
