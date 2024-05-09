/*
* @Author: Zakaria 
* @Date:   2022-12-12 20:38:43
* @Last Modified time: 2022-12-12 20:47:42
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


      map<string, vector<int> >m;

      for(int i=1 ; i<n ; i++)
      {
      	  string pans ="";

      	  pans+=s[i-1];
      	  pans+=s[i];
        
      	  if(m[pans].size())
      	  {
      	  	if(m[pans][0]<i-2)
      	  	{
             // cout<<pans<<" "<<m[pans][0]<<endl;
      	  	  cout<<"YES"<<endl;
      	  	  return ;
      	  	}
      	  }

      	  m[pans].push_back(i-1);
      }

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