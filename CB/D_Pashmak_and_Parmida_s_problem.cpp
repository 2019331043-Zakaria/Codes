/*
* @Author: Zakaria 
* @Date:   2022-12-05 14:55:32
* @Last Modified time: 2022-12-05 15:51:06
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
const int N = 2e6+6;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree< pair<int, int>, null_type, less< pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

ll cnt[N];
ll lans[N];

void Solve()
{
        
         int n;
         cin>>n;

         ll a[n+1];
         
         
         map<ll, int>m;

         set<ll>dist;

         for(int i=1 ; i<=n ; i++)
         {
         	cin>>a[i];
         	dist.insert(a[i]);
         }
         
         int pans = 1;

         for(auto i:dist)
         {
         	 m[i] = pans++;
         }

         for(int i=1 ; i<=n ; i++)
         	a[i] = m[a[i]];

         for(int i=1 ; i<=n ; i++)
         	lans[a[i]]++;



         pbds st;
         ll ans = 0;
        


         for(int i=n ; i>=1 ; i--)
         {
              pair<ll, ll>p = {lans[a[i]] - cnt[a[i]], 0};
              //p.f++;
              int x = st.order_of_key(p);
              ans+=x;

             /* for(auto i:st)
              	cout<<i.f<<" "<<i.s<<endl;

              cout<<"here "<<p.f<<" and "<<p.s<<endl;
              cout<<x<<endl;*/
              cnt[a[i]]++;
              st.insert({cnt[a[i]] , i});

             // cout<<endl;
              
         }


         cout<<ans<<endl;
         


}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;
        
       // cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 