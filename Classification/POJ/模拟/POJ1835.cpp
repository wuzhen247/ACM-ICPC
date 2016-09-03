#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int x, y, z, dis;

void go(int dir)
{
	switch(dir)
	{
		case 0: x += dis; break;
		case 1: y += dis; break;
		case 2: z += dis; break;
		case 3: x -= dis; break;
		case 4: y -= dis; break;
		case 5: z -= dis; break;
	}
}

int main()
{
	int m, n, dir, up, left, tm;
	char order[10];
	scanf("%d", &m);
	while(m--)
	{
		scanf("%d",&n);
		x = y = z = dir = 0;
		up = 2;
		left = 4;
		while(n--)
		{
			scanf("%s %d",order, &dis);
			switch(order[0])
			{
				case 'f': break;
				case 'b': dir = (dir+3)%6, left = (left+3)%6; break;
				case 'l': tm = dir, dir = left, left = (tm+3)%6; break;
				case 'r': tm = dir, dir = (left+3)%6, left= tm; break;
				case 'u': tm = dir, dir = up, up = (tm+3)%6; break;
				case 'd': tm = dir, dir = (up+3)%6, up = tm; break;
			}
			go(dir);
		}
		printf("%d %d %d %d\n", x, y, z, dir );
	}
	return 0;
}
