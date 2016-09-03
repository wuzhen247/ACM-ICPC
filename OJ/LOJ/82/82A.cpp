#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int n;
char s[10];

int main()
{
	double sum, tm;
	int c;
	while (scanf("%d", &n) != EOF)
	{
		sum = c = 0;
		for (int i = 1; i <= n; i++)
		{
		scanf("%lf %s", &tm, s);
//		cout<<tm << ' '<<s<<endl;
		if (strcmp(s,"A") == 0)
		 {
			 c += tm;
			 sum += 4.00*tm;
		 }
		else if (strcmp(s, "A-") == 0)
		{
			c += tm;
			sum += 3.7*tm;
		}
		else if (strcmp(s, "B+") == 0)
		{
			c += tm;
			sum += 3.3*tm;
		}
		else if (strcmp(s, "B") == 0)
		{
			c += tm;
			sum += 3.0*tm;
		}
		else if (strcmp(s, "B-") == 0)
		{
			c += tm;
			sum += 2.7*tm;
		}
		else if (strcmp(s, "C+") == 0)
		{
			c += tm;
			sum += 2.3*tm;
		}
		else if (strcmp(s, "C") ==0 )
		{
			c += tm;
			sum += 2.0*tm;
		}
		else if (strcmp(s, "C-") == 0)
		{
			c += tm;
			sum += 1.7*tm;
		}
		else if (strcmp(s, "D") ==0 )
		{
			c += tm;
			sum += 1.3*tm;
		}
		else if (strcmp(s, "D-") == 0)
		{
			c += tm;
			sum += 1.0*tm;
		}
		else if (strcmp(s, "F") == 0)
		{
			c += tm;
			sum += 0;
		}
		}
		if (c == 0)
		  printf("0.00\n");
		else
		  printf("%.2lf\n", sum/c);
	}
	return 0;
}

