#include<iostream>
#include<cstring>
using namespace std;
int main()
{
 char s1[101],s2[101];
 int n,temp1,temp2,count,j,i;
 cin>>n;
 for(int k=0;k<n;k++)
 {
  cin>>s1>>s2;
  temp1=strlen(s1);
  temp2=strlen(s2); 
  j=0;
  count=0;
  for(i=0;i<temp2;i++)
  {   
   while(j<temp1)
   {
    if(s2[i]==s1[j]){count++;j++;break;}
    j++;
   }
  }
  if(count==temp2){cout<<"YES"<<endl;continue;}
   j=temp1-1;
   count=0;
   for(int i=0;i<temp2;i++)
   {   
    while(j>=0)
    {
     if(s2[i]==s1[j]){count++;j--;break;}
     j--;
    }
   }
   if(count==temp2)cout<<"YES"<<endl;
   else cout<<"NO"<<endl;
  }
 
}
