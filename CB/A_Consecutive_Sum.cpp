/*
* @Author: Zakaria 
* @Date:   2022-09-19 20:35:21
* @Last Modified time: 2022-09-19 20:42:47
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
        
       int n, k;
       cin>>n>>k;

       ll a[n+1];
       
       map<int, vector<ll> > m;

       for(int i=1 ; i<=n ; i++)
       {
       	   cin>>a[i];
       	   m[i%k].push_back(a[i]);
       }

       for(int i=0 ; i<=k ; i++)
       {
       	  if(m[i].size())
       	  {
       	  	 sort(m[i].begin(), m[i].end());
       	  }
       }

       for(int i=1 ; i<=n ; i++)
       {
       	   a[i]=m[i%k].back();
       	   m[i%k].pop_back();
       }
       ll sum=0;

       for(int i=1 ; i<=k ; i++)
       {
       	  sum+=a[i];
       }

       cout<<sum<<endl;
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