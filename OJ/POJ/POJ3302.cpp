#include<iostream>
#include<cstring>
using namespace std;
int main()
{
 	char a[101],s[101];
	 int n,l,m,w,b,c;
	 cin>>n;
	 for(int i=0;i<n;i++) 	
	 {
 		 w=1;
	  	 cin>>a>>s;
 	   	 l=strlen(a);
	 	 m=strlen(s);
	  	 b=0;c=0; 
	     int j=0;
	     for(int i=0;i<m;i++)
	     {   
			 while(j<l)
	    	 {
	     	    if(s[i]==a[j])
				 {b++;j++;break;}
        	   	j++;
   	    	} 
  		}
 	 	if(b==m){cout<<"YES"<<endl;w=0;}
 		 if(w)
 		 {
 		  int k=l-1;
 		  for(int i=0;i<m;i++)
 		  {   
			    while(k>=0)
 		 	  {
   				  if(s[i]==a[k]){c++;k--;break;}
 	 		   k--;
		    }
		   }
		   if(c==m)cout<<"YES"<<endl;
		   else cout<<"NO"<<endl;
		  }
	 }
}
