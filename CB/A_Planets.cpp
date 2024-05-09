/*
* @Author: Zakaria 
* @Date:   2022-09-25 20:35:25
* @Last Modified time: 2022-09-25 20:36:29
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

       int a[n];
       map<int, int>m;

       for(int i=0 ; i<n ; i++)
       {
          cin>>a[i];
          m[a[i]]++;
       }
       int ans=0;
       for(auto i:m)
       {
            ans+=min(i.s, k);
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