#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1000010;
char s[N];
int f[N], num[N];

int main()
{
    int t, i, j, len, ans, end;
    bool flag;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%s", s+1);
        len = strlen(s+1);
        memset(f, 0, sizeof(f));
        memset(num, 0, sizeof(num));
        end = 8;
        flag = false;
        for (i = 1; i <= 7; i++)
        {
            for (j = len; j >= i; j--)
            {
                f[j]= f[j-1] * 8 + s[j] - 'A';
                num[f[j]]++;
            }
            for (j = 0; j < end; j++)
            {
                if (!num[j])
                {
                    ans = j;
                    flag = true;
                    break;
                }
                num[j] = 0;
            }
            if (flag)   break;
            end *= 8;
        }
        for (j = 0; i != 0; i--)
        {
            s[j++] = ans % 8 + 'A';
            ans /= 8;
        }
        for (i = j - 1; i >= 0; i--)
            printf("%c", s[i]);
        printf("\n");
    }
    return 0;
}
