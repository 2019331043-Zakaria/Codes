/*
* @Author: Zakaria 
* @Date:   2022-12-16 14:19:58
* @Last Modified time: 2022-12-16 14:29:41
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

        ll a[n];

        ll mn = LLONG_MAX;
        
        vector<pair<ll, ll> > pans;

        for(int i=0 ; i<n ; i++)
        	cin>>a[i], mn = min(mn, a[i]), pans.push_back({a[i],i});


        sort(pans.begin(), pans.end());



        vector<pair<int, int> > v;

        for(auto i:pans)
        {
        	ll val = i.f;
        	ll index = i.s+1;

        	ll temp = (val + mn - 1)/mn;
        	temp*=mn;
            
            v.push_back({index, temp - val});

            mn = temp;
        }

        cout<<v.size()<<endl;
        for(auto i:v)
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