/*
* @Author: Zakaria 
* @Date:   2023-02-27 20:35:43
* @Last Modified time: 2023-02-27 20:59:13
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

      set< pair<int, int> >st;
      int temp = 1;

      map<int,  int> cur;

      int ans[n+m+5];

      for(int i=1 ; i<=n ; i++)
      	ans[i] = 1e9, cur[i] = ++temp, st.insert({cur[i], i});

      temp = 1;

      
      for(int i=1 ; i<=m ; i++)
      {
      	  int x;
      	  cin>>x;

      	  pair<int, int>p;
      	  p={cur[x], x};

      	  if(st.find(p)!=st.end())
      	  {
      	  	 st.erase(p);
      	  	 cur[x] = --temp;
      	  	 st.insert({cur[x], x});
      	  }
      	  else
      	  {
      	  	 pair<int, int>p;

      	  	 p = *st.rbegin();

      	  	 

      	  	 ans[p.s] = min(ans[p.s], i);

      	  	 st.erase(p);

      	  	 cur[x] = --temp;
      	  	 st.insert({cur[x], x});
      	  }

      	 
      }

     

      for(int i=1 ; i<=n ; i++)
      {
      	 if(ans[i] != 1e9)
      	 	cout<<ans[i]<<" ";
      	 else
      	 	cout<<-1<<" ";
      }
      cout<<endl;


      
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