//POJ2484 �ԳƲ���
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int n;
	while (scanf("%d", &n),n)
	{
		if (n < 3)
		  printf("Alice\n");
		else
		  printf("Bob\n");
	}
	return 0;
}
