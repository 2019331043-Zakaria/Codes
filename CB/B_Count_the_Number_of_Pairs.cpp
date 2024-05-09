/*
* @Author: Zakaria 
* @Date:   2023-03-02 20:44:45
* @Last Modified time: 2023-03-02 20:50:55
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
        
      int n, k;
      cin>>n>>k;

      map<char, int>m;
      string s;
      cin>>s;

      for(auto i:s)
      	m[i]++;

      ll ans = 0;

      for(char i='a' ; i<='z' ; i++)
      {
      	
      	  char c = i;
      	  char d = (char) (i-'a'+'A');

      	//  cout<<c<<" "<<d<<endl;

      	  ans+=min(m[c], m[d]);
      	  int temp = min(m[c], m[d]);
      	  m[c]-=temp;
      	  m[d]-=temp;

      	  int mx = max(m[c], m[d]);

      	  mx = min(mx/2, k);

      	  ans+=mx;
      	  k-=mx;
      }

      cout<<ans<<endl;
      
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