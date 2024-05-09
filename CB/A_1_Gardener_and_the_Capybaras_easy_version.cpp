/*
* @Author: Zakaria 
* @Date:   2023-01-10 17:15:29
* @Last Modified time: 2023-01-10 17:50:26
*/
#include <bits/stdc++.h>
#define  pb          push_back
#define  f           first
#define  s           second
#define  pi          acos(-1.0)
#define  LCM(a,b)    a*b/__gcd(a,b)
#define  GCD(a,b)    __gcd(a,b)
#define  sof         sizeof
#define  endl        '\n'
#define  eps         1e-6
typedef long long ll;
using namespace std;

const int mod = 1e9+7;
const int N = 2e5+6;

void Solve()
{
        
      string s;
      cin>>s;
      
      int n = s.size();

      if(s[0]==s.back())
      {
      	 cout<<s[0]<<" ";

      	 for(int i=1 ; i<n-1 ; i++)
      	 	cout<<s[i];

      	 cout<<" ";

      	 cout<<s.back()<<endl;

      	 return ;
      }

      if(s[0]=='a' && s.back()=='b')
      {
      	  string pans = "";
      	  bool ok = 0;
      	  for(int i=0 ; i<n-1 ; i++)
      	  {
      	  	if(s[i]=='b')
      	  	{
      	  		cout<<pans<<" ";

      	  		for(int k=i ; k<n-1 ; k++)
      	  			cout<<s[k];

      	  		cout<<" ";

      	  		cout<<s.back()<<endl;

      	  		return ;
      	  	}
      	  	else
      	  	{
      	  		pans+=s[i];
      	  	}
      	  }

      	  pans.pop_back();

      	  cout<<pans<<" "<<"a"<<" "<<s.back()<<endl;
      	  return ;
      }

      if(s[0]=='b' && s.back()=='a')
      {
      	  int cntb = 0;

      	  for(auto i:s)
      	  {
      	  	 if(i=='b')
      	  	 	cntb++;
      	  }

      	  if(cntb==1)
      	  {
      	  	 cout<<s[0]<<" "<<s[1]<<" ";

      	  	 for(int k=2 ; k<n ; k++)
      	  	 	cout<<s[k];

      	  	 cout<<endl;

      	  	 return ;
      	  }
      	  

      	  // if ab exist

      	  bool ab=0;
      	  int index = -1;

      	  for(int i=1 ; i<n ; i++)
      	  {
      	  	 if(s[i-1]=='a' && s[i]=='b')
      	  	 {
      	  	 	ab = 1;
      	  	 	index = i;
      	  	 }
      	  }
          
      	  if(index==-1)
      	  {  
      	  	   cout<<s[0]<<" ";

      	  	   for(int i=1 ; i<n-1 ; i++)
      	  	   	cout<<s[i];
      	  	   cout<<" ";
      	  	   cout<<s.back()<<endl;

      	  	   return ;
      	  }

      	  for(int i=0 ; i<=index-2 ; i++)
      	  	cout<<s[i];

      	  cout<<" ";

      	  cout<<s[index-1]<<" ";

      	  for(int i=index ; i<n ; i++)
      	  	cout<<s[i];

      	  cout<<endl;

      	  return ;
      }
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;
        
        cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 