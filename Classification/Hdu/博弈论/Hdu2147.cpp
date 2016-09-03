//Hdu2147 kiki's game
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main()
{
	int n, m;
	while (scanf("%d%d", &n, &m) && (n||m))
	{
		if (n%2 && m%2)
		  printf("What a pity!\n");
		else
		  printf("Wonderful!\n");
	}
	return 0;
}
