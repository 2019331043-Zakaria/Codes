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

      for(auto &i :s)
      {
         if(i>='A' && i<='Z')
            i = i-'A' + 'a';
      }

      string pans = "";
      pans+=s[0];

      for(auto i:s)
      {
        if(i!=pans.back())
            pans+=i;
      }

      //cout<<pans<<endl;
      if(pans=="meow")
      {
        cout<<"YES"<<endl;
        return ;
      }
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