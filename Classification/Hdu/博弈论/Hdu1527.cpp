//Íþ×ô·ò²©ÞÈ
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
	int a, b, tm, k;
	while (scanf("%d%d", &a, &b) != EOF)
	{
		if (b < a)	swap(a,b);
		tm = b - a;
		k = floor(tm*(1.0 + sqrt(5.0))/2);
		if (k == a)
		  printf("0\n");
		else
		  printf("1\n");
	}
	return 0;
}
