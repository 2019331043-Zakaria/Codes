/*
* @Author: Zakaria 
* @Date:   2023-01-08 22:18:03
* @Last Modified time: 2023-01-08 22:44:39
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

int cnt[N];

void Solve()
{
        
       ll n, k;
       cin>>n>>k;

       ll a[n];
       ll sum = 0;
       

       

       for(int i=0 ; i<=1000 ; i++)
       	cnt[i] = 0;

       for(int i=0 ; i<n ; i++)
       	cin>>a[i], cnt[a[i]]++;
       
       int maxwin = 0;

       for(int i=0 ; i<=1000 ; i++)
       {
       	  ll tot = 0;
       	  int win = 0;

       	  for(int j=i ; j<=1000 ; j++)
       	  {
              ll baki = k - tot;

              if(cnt[j] && baki>0)
              {
              	   ll temp = baki/j;

              	   if(temp>cnt[j])
              	   {
                        tot+=cnt[j]*j;
                        win+=cnt[j];
              	   }
              	   else
              	   {
                        win+=temp;
                        break;
              	   }
              }
       	  }
       	  maxwin = max(maxwin, win);
       }

       cout<<maxwin<<" ";

       if(maxwin==0)
       {
       	  cout<<n+1<<endl;
       	  return ;
       }

       if(maxwin>=n-1)
       {
       	  cout<<1<<endl;
       	  return ;
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