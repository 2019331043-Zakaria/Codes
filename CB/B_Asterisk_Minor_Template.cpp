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

      if(s[0]==t[0])
      {
      	 cout<<"YES"<<endl;
      	 cout<<s[0]<<"*"<<endl;
      	 return ;
      }
      if(s.back()==t.back())
      {
      	 cout<<"YES"<<endl;
      	 cout<<"*"<<s.back()<<endl;
      	 return ;
      }

      map<string, int>all;

      for(int i=0 ; i<s.size()-1 ; i++)
      {
      	string pans = "";
      	pans+=s[i];
      	pans+=s[i+1];
      	all[pans] = 1;
      }

      for(int i=0 ; i<t.size()-1 ; i++)
      {
      	string pans = "";
      	pans+=t[i];
      	pans+=t[i+1];

      	if(all[pans])
      	{
      		cout<<"YES"<<endl;
      		cout<<"*"<<pans<<"*"<<endl;
      		return ;
      	}
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