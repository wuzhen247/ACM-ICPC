#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	char f[120][80],b[120][80],c[10],temp[80];
	int i=0,j=0;
	strcpy(temp,"http://www.acm.org/");
	while(scanf("%s",c)&&c[0]!='Q')
	{
		switch(c[0])
		{
			case 'V':j=0;
					 strcpy(b[++i],temp);
					 scanf("%s",temp);
					 printf("%s\n",temp);
					 break;
			case 'B':if(i==0)
						printf("Ignored\n");
					 else
					 {
					   strcpy(f[++j],temp);
					   strcpy(temp,b[i--]);
					   printf("%s\n",temp);
					 }
					 break;
			case 'F':if(j>0)
					 {
						 strcpy(b[++i],temp);
						 strcpy(temp,f[j--]);
						  printf("%s\n",temp);

					 }
					 else
					   	printf("Ignored\n");
					 break;
		}
	}
	return 0;
}
