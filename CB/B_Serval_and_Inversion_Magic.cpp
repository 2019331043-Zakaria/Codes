/*
* @Author: Zakaria 
* @Date:   2023-02-25 20:27:04
* @Last Modified time: 2023-02-25 20:34:24
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
        
      int n;
      cin>>n;

      string s;
      cin>>s;

      int i=0, j=n-1;

      int left = -1, right = -1;

      while(i<=j)
      {
           if(s[i]!=s[j])
           {
           	   left = i;
           	   right = j;
           	   break;
           }
           else
           {
           	  i++;
           	  j--;
           }
      }

      if(left==-1 && right==-1)
      {
      	  cout<<"YES"<<endl;
      	  return ;
      }

      bool ok =0;

      i = left;
      j = right;
      bool pans = 1;
      while(i<=j) // flip from right;
      {
          if(ok)
          {
          	  if(s[i]!=s[j])
          	  {
          	  	 pans = 0;
          	  	 break;
          	  }
          	  i++;
          	  j--;
          }
          else
          {
          	  if(s[i]==s[j])
          	  {
          	  	 ok = 1;
          	  }
          	  i++;
          	  j--;
          }
      }

      if(pans)
      	cout<<"YES"<<endl;
      else
      	cout<<"NO"<<endl;
      
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