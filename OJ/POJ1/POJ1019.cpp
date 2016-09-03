//¶þ·Ö·¨
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
long long a[40000],temp;
int main()
{
    unsigned int t,n,i,pos,len;
    long long high,low,middle;
    a[1]=1,temp=1;
    bool l,r,f;
    for(i=2;i<31269;i++)
    {
        temp=temp+(int)log10((double)i)+1;
        a[i]=a[i-1]+temp;
    }
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        low=1,high=31268;
        l=r=f=false;
        while(low<=high)
        {
            if(a[low]==n)
            {
                l=true;
                break;
            }
            if(a[high]==n)
            {
                r=true;
                break;
            }
            if(a[low]<n&&a[high]>n&&(high-low)==1)
              break;
            middle=(high+low)/2;
            if(a[middle]<n)
              low=middle;
            else
              high=middle;
        }
        if(l)
        {
            printf("%d\n",low%10);
            continue;
        }
        if(r)
        {
            printf("%d\n",high%10);
            continue;
        }
        pos=n-a[low];
        len=0;
        for(i=1;len<pos;i++)
          len+=(int)log10((double)i)+1;
        printf("%d\n",((i-1)/(int)pow((double)10,len-pos))%10);
    }
    return 0;
}
