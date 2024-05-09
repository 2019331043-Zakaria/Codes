/*
* @Author: Zakaria 
* @Date:   2023-01-01 20:46:00
* @Last Modified time: 2023-01-01 21:11:22
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
        
      string s, t;
      cin>>s>>t;
      
      vector<int>offset;

      for(int i=0 ; i<s.size() ; i++)
      {
        if(s[i]=='?')
         offset.push_back(i);
      }
      map<char, vector<int> > m;

      for(int i=0 ; i<s.size() ; i++)
      {
      	m[s[i]].push_back(i);
      }

      while(1)
      {
      	  for(auto i:t)
      	  {
      	  	 if(m[i].size())
      	  	 {
      	  	 	m[i].pop_back();
      	  	 	continue;
      	  	 }
      	  	 if(offset.size())
      	  	 {
                s[offset.back()] = i;
                offset.pop_back();
      	  	 }
      	  	 else
      	  	 	break;
      	  }

      	  if(offset.size()==0)
      	  	break;
      }
      

      cout<<s<<endl;
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;
        
      //  cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 