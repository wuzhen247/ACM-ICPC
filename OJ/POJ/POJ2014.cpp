//给出区域最大宽度和一系列盒子，长度不限，求围住它们的最小面积
/* 35
10 5
20 12
8 13
-1 -1
25
10 5
20 13
3 12
-1 -1
15
5 17
5 17
5 17
7 9
7 20
2 10
-1 -1
0*/ 
#include<iostream>
using namespace std;
int a[17][2],m,n;
int main()
{
	int i,j,temp1,temp2,max1,max2;
	while(cin>>m&&m!=0)
	{
		n=0;
		for(i=0;;i++)
		{
			for(j=0;j<2;j++)
				cin>>a[i][j];
			n++;
			if(a[i][0]==-1&&a[i][1]==-1)
				break;
		}
		n--;
//		cout<<n<<endl;
		temp2=max1=max2=0;
		for(i=0;i<n;)
		{
			temp1=0;temp2=0;
			while(1)
			{
				if((temp1+a[i][0]>m)||i==n)
				{
					break;
				}
				temp1=temp1+a[i][0];
				if(a[i][1]>temp2)
					temp2=a[i][1];
				i++;
				
			}
	//		temp1=temp1-a[i][0];
			if(temp1>max1)
				max1=temp1;
			max2+=temp2;
		}
		cout<<max1<<" x "<<max2<<endl;
	}
	return 0;
}
