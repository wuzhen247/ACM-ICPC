//Ä£Äâ ·´½âÂë
#include <iostream>
#include <cstdio>
#include <string.h>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
	string s, p, c;
	int x, n, pos[300], d, i, sn, t, a, b;
	char m[200];
	while (cin>>x && x)
	{
		cin>>s>>p>>c;
		sn = s.length();
		for	(i = 0; i < sn; i++)
		  pos[int(s[i])] = i;
		n = c.length();
		d = (int(pow(n,1.5) + x)) % n;
		m[d] = p[pos[c[d]]];
		for (i = n + d -1; i > d; i--)
		{
			t = i % n;
			a = pos[c[t]];
			b = pos[m[(t+1)%n]];
			m[t] = p[a^b];
		}
		m[n] = '\0';
		cout<<m<<endl;
	}
	return 0;
}
