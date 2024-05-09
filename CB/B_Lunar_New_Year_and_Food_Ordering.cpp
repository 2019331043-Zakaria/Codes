/*
* @Author: Zakaria 
* @Date:   2023-02-21 16:02:38
* @Last Modified time: 2023-02-21 16:13:17
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
        
      int n, m;
      cin>>n>>m;

      ll a[n+1];
      for(int i=1 ; i<=n ; i++)
      cin>>a[i];

      set<pair<int, int> > st;
      ll c[n+1];
      for(int i=1; i<=n ; i++)
      {
      	  cin>>c[i];
      	  st.insert({c[i], i});
      }  


      while(m--)
      {
      	 ll index, qunatity;
      	 cin>>index>>qunatity;

      //	 cout<<index<<" "<<qunatity<<endl;

      	 ll ans = 0;

      	 ans+=min(a[index], qunatity) * c[index];

      	 ll done = min(a[index], qunatity);
      	 a[index]-=done;
      	 qunatity-=done;

      	 if(a[index]==0)
      	 {
      	 	st.erase({c[index], index});
      	 }

      	 while(qunatity && st.size())
      	 {

      	 	auto it = *st.begin();
      	 	ll pos = it.s;
      	 	
      	 	done = min(a[pos], qunatity);

      	 	ans+=done*c[pos];

      	 	a[pos]-=done;
      	 	qunatity-=done;

      	 	if(a[pos]==0)
      	 		st.erase({c[pos], pos});
      	 }
      	 if(qunatity)
      	 	ans = 0;

      	 cout<<ans<<endl;
      }    
      
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;
        
    //    cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 