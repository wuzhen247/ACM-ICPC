//anti-NIM
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n, ans, tm;
    bool f;
    while(scanf("%d", &n) != EOF)
    {
        ans = 0;
        f = false;
        for (int i=0; i<n; i++)
        {
            scanf("%d", &tm);
            if (tm != 1)
              f = true;
            ans ^= tm;
        }
        if ((ans && f) || (!ans && !f))
          printf("Yes\n");
        else
          printf("No\n");
    }
    return 0;
}
