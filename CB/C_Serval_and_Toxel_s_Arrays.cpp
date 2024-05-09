/*
* @Author: Zakaria 
* @Date:   2023-02-25 20:36:57
* @Last Modified time: 2023-02-25 21:10:51
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
        
      ll n, m;
      cin>>n>>m;

      map<ll, ll>freq;

      int a[n];

      ll exist = 1;

      map<ll , ll> prev;
      set<ll>st;

      for(int i=0 ; i<n ; i++)
      {
      	cin>>a[i];
      	prev[a[i]] = 1 ;
      	st.insert(a[i]);
      }

      int k = m;
      while(k--)
      {
      	  exist++;

      	  int index, x;
      	  cin>>index>>x;
      	  
      	  index--;

      	  if(a[index]!=x)
      	  {
      	  	 freq[a[index]]+= exist - prev[a[index]];
      	  	 prev[a[index]] = exist;
      	  	 st.erase(a[index]);
      	  	 st.insert(x);
      	  	 prev[x] = exist;
      	  	 a[index] = x;
      	  }
      }

      for(auto i:st)
      	freq[i]+=exist - prev[i] + 1;

      // for(auto i:freq)
      // {

      // 	 cout<<i.f<<" "<<i.s<<endl;

      // }

      // cout<<endl;

      ll ans = 0;

      for(auto i:freq)
      {
      	  ll temp = i.s;

      	  ll absent = (m+1) - temp;

      	  ll off = (absent*(absent-1))/2;

      	  ll tot = ((m+1)*(m))/2;
      	  ans+=tot-off;

      	  // cout<<i.f<<" => "<<endl;
      	  // cout<<temp<<" "<<absent<<endl;
      	  // cout<<"contr "<<tot-off<<endl;
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