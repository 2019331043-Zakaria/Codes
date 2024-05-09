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
        
       int a, b;

       cin>>a>>b;

       set<int>st;

       if(a>=4)
       st.insert(4), a-=4;

       if(a>=2)
       st.insert(2), a-=2;

       if(a>=1)
       st.insert(1);
       
       a=b;

       if(a>=4)
       st.insert(4), a-=4;

       if(a>=2)
       st.insert(2), a-=2;

       if(a>=1)
       st.insert(1);

       int ans=0;
       for(auto i:st)
       ans+=i;

       cout<<ans<<endl;


       
      
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