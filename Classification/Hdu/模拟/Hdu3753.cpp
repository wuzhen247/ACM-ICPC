/*×Ö·û´®Êä³ö×ª»»*/
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int N = 1000+5;
int t, num[N][182], len[200];
char s[N][182], s1[N][182];

int main()
{
    scanf("%d", &t);
    getchar();
    while (t--)
    {
        int row = 0;
        while (gets(s[row]) != NULL)
        {
            strcpy(s1[row], s[row]);
            if (s[row][0] == '@' && strlen(s[row]) == 1)
              break;
            row++;
        }
        char *tokenPtr;
        int count, ma;
        for (int i = 0; i < row; i++)
        {
            tokenPtr = strtok( s[i], " " );
            count = 0;
            while ( tokenPtr != NULL ) 
	        {
	            num[i][++count] = strlen(tokenPtr);
    	        tokenPtr = strtok(NULL, " ");
  	        }
  	        num[i][0] = count;
        }
        len[0] = 0;
        count = -1;
        for (int i = 0; i < row; i++)
            count = max(count, num[i][0]);
        for (int i = 1; i <= count; i++)
        {
            ma = -1;
            for (int j = 0; j < row; j++)
            {
                if (i <= num[j][0])
                    ma = max(ma, num[j][i]);
            }
            len[i] = len[i-1] + ma + 1;
        }
        
        for (int i = 0; i < row; i++)
        {
            tokenPtr = strtok( s1[i], " " );
            for (int j = 1; j < num[i][0]; j++)
            {
                printf("%s", tokenPtr);
                tokenPtr = strtok(NULL, " ");
                num[i][j] = len[j] - len[j-1] - num[i][j];
                for (int k = 0; k < num[i][j]; k++)
                    printf(" ");
            }
            printf("%s\n", tokenPtr);
        }
        
    }
    return 0;
}
