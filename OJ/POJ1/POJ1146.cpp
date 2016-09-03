//«Û»´≈≈¡–
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    char s[70];
    int len;
    while(scanf("%s",s)&&s[0]!='#')
    {
        len=strlen(s);
        if(next_permutation(s,s+len))
          printf("%s\n",s);
        else
          printf("No Successor\n");
    }
    return 0;
}
