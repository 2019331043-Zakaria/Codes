/*
* @Author: Zakaria 
* @Date:   2022-11-14 17:34:37
* @Last Modified time: 2022-11-14 17:59:46
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

vector<pair<int, int> > v;
ll n, x, y, z;

int left(ll value, int limbo)
{
	int low = 1, high = limbo;
	int ans = limbo;

	while(low<=high)
	{
        int mid = (low+high)/2;
        if(v[mid].f<=value && v[mid].s>=value)
        {
        	ans = mid;
        	high = mid - 1;
        }
        else
        	low = mid + 1;
	} 

	return ans ;
}
int right(ll value, int limbo)
{
	 int low = limbo, high = n;
	 int ans = limbo;

	 while(low<=high)
	 {
	 	int mid = (low+high)/2;
	 	if(v[mid].f<=value && v[mid].s>=value)
	 	{
	 		ans = mid;
	 		low = mid + 1;
	 	}
	 	else
	 		high = mid - 1;
	 }

	 return ans;
}
void Solve()
{
        
        cin>>n>>x>>y>>z;
        
        vector<ll>all;

        for(int i=1 ; i<=n ; i++)
        {
        	ll l, r;
        	cin>>l>>r;
        	v.push_back({l, r});
        	all.push_back(l);
        	all.push_back(r);
        }

        v.push_back({0, 0});

        sort(all.begin(), all.end());
        sort(v.begin(), v.end());

       /* for(auto i: v)
        	cout<<i.f<<" "<<i.s<<endl;
*/
        ll ans = 0;

        for(int i=1 ; i<=n ; i++)
        {
        	ll l = left(v[i].f, i);
        	ll r = right(v[i].f, i);
         

        	ans = max({ans, x*(l-1) + (r - l +1)*y + (n - r)*z});

            l = left(v[i].s, i);
            r = right(v[i].s, i);

            ans = max({ans, x*(l-1) + (r - l +1)*y + (n - r)*z});

        }

        cout<<ans<<endl;

        
      
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