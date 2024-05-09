/*
* @Author: Zakaria 
* @Date:   2023-01-15 18:15:05
* @Last Modified time: 2023-01-15 19:07:26
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

      int a[n];

      map<int, int>m;
      set<int>st;
     
      for(int i=0 ; i<n ; i++)
      	cin>>a[i], m[a[i]]++, st.insert(a[i]);

      sort(a, a+n);

      
      
      ll ans = 0;
      ll cnt = 0;

      

      for(int i=0 ; i<n ; i++)
      {
      	  if(m[i])
      	  {
      	  	 cnt+=m[i];
      	     
      	     auto val = st.upper_bound(i);

      	     int temp ;

      	     if(val==st.end())
      	     	temp = n+5;
      	     else
      	     	temp = *val;
      	    
      	  	 if(cnt<temp  && cnt>i)
      	  	 {
      	  	 	 ans++;
      	  	 //	 cout<<i<<endl;
      	  	 }
      	  }
      }

      if(m[0]==0)
      	ans++;

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