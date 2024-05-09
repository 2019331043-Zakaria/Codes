/*
* @Author: Zakaria 
* @Date:   2022-12-25 21:08:06
* @Last Modified time: 2022-12-25 21:45:41
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

int cnt[1025];
int pans[1025];

void Solve()
{
        
      int n, k, x;
      cin>>n>>k>>x;

      for(int i=1 ; i<=n ; i++)
      {
      	  int p;
      	  cin>>p;
      	  cnt[p]++;
      }



      while(k--)
      {
          
          int rem = 0;
          memset(pans, 0, sizeof(pans));
      	  for(int i=0 ; i<1024 ; i++)
      	  {
               int tot = cnt[i];
               
               if(tot==0)
               	continue;



               int changed = (tot + 1 - rem)/2;
               int unchanged = tot - changed;

              
               int val = i^x;
               
               pans[val] += changed;
               pans[i] += unchanged;
               rem = (rem + tot)%2;
      	  }

      	
      	  memset(cnt, 0, sizeof(cnt));

      	  for(int i=0 ; i<1024 ; i++)
      	  	cnt[i] = pans[i];
      }
      int mn = 1025, mx = 0;

      for(int i=0 ; i<1024 ; i++)
      {
      	if(cnt[i])
      		mn = min(mn, i), mx = max(mx, i);
      }

      cout<<mx<<" "<<mn<<endl;



      
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;
        
     //   cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 