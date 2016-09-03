#include<stdio.h>
#include<iostream>
using namespace std;

int color[16][3];
int main()
{
	int R,G,B;
	int index;
	int diff;
	int cal;

	//Ä¿±êÑÕÉ«
	for(int i=0;i<16;i++)
	{
		cin>>color[i][0];
		cin>>color[i][1];
		cin>>color[i][2];
	}

	while(1)
	{
		index=-1;
		diff=-1;
		cin>>R;
		cin>>G;
		cin>>B;
		
		if(R==-1&&G==-1&&B==-1)
			break;

		for(int i=0;i<16;i++)
		{
			cal=(R-color[i][0])*(R-color[i][0])+(G-color[i][1])*(G-color[i][1])+(B-color[i][2])*(B-color[i][2]);
			if(diff==-1||cal<diff)
			{
				diff=cal;
				index=i;
			}
		}

		printf("(%d,%d,%d) maps to (%d,%d,%d)\n",R,G,B,color[index][0],color[index][1],color[index][2]);

	}


	
}


