/*
* @Author: Zakaria 
* @Date:   2022-10-23 14:47:39
* @Last Modified time: 2022-10-25 11:11:16
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

       ll a[n+1];

       for(int i=1; i<=n ; i++)
        cin>>a[i];

       if(n%2)
       {
           cout<<-1<<endl;
           return ;
       }

       vector<pair<int, int> > ans;

       for(int i=2 ; i<=n ; i+=2)
       {
           if(a[i]==a[i-1])
            ans.push_back({i-1, i});
           else
            ans.push_back({i-1, i-1}), ans.push_back({i, i});
       }

       cout<<ans.size()<<endl;

       for(auto i:ans)
        cout<<i.f<<" "<<i.s<<endl;

      
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