/*
* @Author: Zakaria 
* @Date:   2022-04-01 01:08:32
* @Last Modified time: 2022-06-05 02:41:04
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
#define  MAX         1000002
typedef long long ll;
using namespace std;

ll k , n;

bool check(ll mid, ll prev , ll post)
{

      ll temp=prev+post;
      ll lage=k+post;
      if(temp>=lage)
         return 1;
      if(temp==0)
         return 0;

      if(mid>=(lage-1+temp)/temp && temp>=(lage-1+mid)/mid)
         return 1;

     
         return 0;
}

void Solve()
{  
             
          
          cin>>k>>n;

          ll a[n+1];
          ll cum[n+1];

          memset(cum, 0, sizeof(cum));
          ll tot=0;

          for(int i=1 ; i<=n ; i++)
          {
               cin>>a[i];
               a[i]*=-1LL;
               cum[i]=cum[i-1]+a[i];
              
               tot+=a[i];
          }
         

          ll ans=LLONG_MAX;

          for(ll i=1 ; i<=n ; i++)
          {
                 ll prev=cum[i];
                 ll post=tot - cum[i];
              
             
               ll low=1, high=1e12, mid;
               ll res=1e18;

               if(prev>=k)
               {
                  res=i;
                  ans=min(ans, i);
                  continue;

               }
               while(low<=high)
               {
                   ll mid=(low+high)/2;
                  
                   if(check(mid, prev, post))
                     high=mid-1, res=min(res, mid);
                   else
                     low=mid+1;
               }
             
               if(res!=1e18)
               ans=min(ans, res*i+(res-1)*(n-i));
              

          }
          if(ans==LLONG_MAX)
            cout<<-1<<endl;
          else
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