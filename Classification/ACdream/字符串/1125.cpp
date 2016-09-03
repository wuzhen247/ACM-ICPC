//求s中任意子串不同的字典序最小的串
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

char s[1100];

int main()
{
    int t, n, m, len;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%s", s);
        len = strlen(s);
        n = m = 0;
        for (int i = 0; i < len; i++)
        {
            if (s[i] == 'A')
                m++;
            else
                m = 0;
            n = max(n, m);
        }
        n++;
        while (n--)
          printf("A");
        printf("\n");
    }
    return 0;
}
