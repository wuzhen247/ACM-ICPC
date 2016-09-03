#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
char s[100];

void SwapInt(int *a,int *b)
{
    *a += *b;
    *b = *a-*b;
    *a -= *b;
}
int main()
{
    int a, b;
    cin>>a>>b;
    SwapInt(&a,&b);
    cout<<a<<' '<<b<<endl;
    return 0;
}
