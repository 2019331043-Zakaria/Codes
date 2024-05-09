/*
* @Author: Zakaria 
* @Date:   2022-04-01 01:08:32
* @Last Modified time: 2022-06-05 22:05:03
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
#define  MAX         500002
typedef long long ll;
using namespace std;

ll n,k;
ll down[MAX],pre[MAX];
ll a[MAX];
ll tot;

bool check(ll mid, ll remain)
{

        ll up=upper_bound(a, a+n, mid)-a;
       
        if(up==n)
         return 1;
       
        if(tot - pre[up-1] - 1LL*((n-up))*mid > remain)
         return 0;
        else
         return 1;

}
bool check1(ll mid, ll remain)
{

        ll low=upper_bound(a,a+n, mid)-a;
        
        if(low==0)
         return 1;
        low--;
     
        if(down[low] + (mid-a[low])*(low+1)>remain)
         return 0;
        else
         return 1;

}
void Solve()
{  
       
       cin>>n>>k;
      
       for(int i=0 ; i<n ; i++)
       {

          cin>>a[i];
          tot+=a[i];
       }

       sort(a, a+n);

      
       ll cum=0;
       down[0]=0;
       pre[0]=a[0];
       for(int i=1 ; i<n ; i++)
       {
           pre[i]=a[i]+pre[i-1];
           down[i]=cum+(1LL*i*(a[i]-a[i-1]));
           cum=down[i]; 

       }

   

       ll res=LLONG_MAX;


       for(int i=0 ; i<n ; i++)
       {
            ll temp=a[i];  
            
            ll low=a[i], high=a[n-1]+10;
            ll mid;
            ll ans=1e18;

            ll remain = k - down[i];
          
            if(remain<0)
               continue;
            

            while(low<=high)
            {
                ll mid=(low+high)/2;
               
                if(check(mid, remain))
                  high=mid-1, ans=min(ans, mid);
                else
                  low=mid+1;
            }
       
          

            res=min(res, ans-temp);
          
       }
       
 
        cum=0;
        ll pans=0;
        ll cnt=0;
       for(int i=n-1 ; i>=0 ; i--)
       {
            ll lans=0;

            if(i==n-1)
            {
                 cnt++;
                 cum=a[i];
            }
            else
            {
                  lans=pans+1LL*cnt*(cum-a[i]);
                  cum=a[i];
                  pans=lans;
                  cnt++;
            }
             
            ll temp=a[i];
            ll low=1, high=a[i], mid;
            ll ans=0;
            ll remain=k - lans;
         
            if(remain<0)
               continue;

             while(low<=high)
            {
                ll mid=(low+high)/2;
               
                if(check1(mid, remain))
                  low=mid+1, ans=max(ans, mid);
                else
                  high=mid-1;
            }

            res=min(res, temp-ans);

       }
       cout<<res<<endl;


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

