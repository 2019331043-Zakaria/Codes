/*
* @Author: Zakaria 
* @Date:   2022-09-25 20:38:31
* @Last Modified time: 2022-09-26 17:35:24
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

int a[N], cost[N];
vector<pair<ll, ll> > v;

pair<double, bool>Check(double mid)
{
       double left=0, right=1e9;

       for(auto i:v)
       {
          if(mid<i.s)
            return {right, 0};

          left=max(left, i.f - (mid-i.s));
          right=min(right , i.f + (mid-i.s));
       }
       
       if(left<=right)
        return {right, 1};
       else
        return {right, 0};
}

void Solve()
{

        int n;    
        cin>>n;
        v.clear();

        for(int i=0 ; i<n ; i++)
        	cin>>a[i];

       
        for(int i=0 ; i<n ; i++)
        	cin>>cost[i];
        
        for(int i=0 ; i<n ; i++)
            v.push_back({a[i], cost[i]});

       
         double low=0.0, high=1e9, mid;
         double ans=0.0;
         double res=0.0;

         

         while(abs(low - high)>=eps)
         {
              
               mid=(low+high)/2.0;

              
               pair<double, bool>p;
               p=Check(mid);
               if(p.s==1)
               {
                   high = mid;
                   res=p.f;
               }
               else
               {
                  low = mid;
               }
         }

         cout<<fixed<<setprecision(10)<<res<<endl;

        
        
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