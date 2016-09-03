#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    char s[2000];
    int n, len, l, a, b;
    while (scanf("%d", &n) != EOF)
    {
        getchar();
        gets(s);
        l = 0;
        len = strlen(s);
        for (int i=0;i<len;i++)
          if (s[i]=='L')
            l++;
        a = n-len+l;
        printf("%d %d\n",a,l);
    }
    return 0;
}
