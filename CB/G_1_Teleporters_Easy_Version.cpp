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

vector<pair<ll, ll> >v;
vector<ll>cum;
int pos[N];
vector<ll>leftest;
ll n, k;


int foo(int index, ll x)
{
	 // cout<<x<<endl;

	  int low = 0, high = n-1, mid;
	  int ans = 0;

	  while(low<=high)
	  {
	  	  mid = (low+high)>>1;

	  	  ll tot = cum[mid];

	  	  if(mid>=pos[index])
	  	  {
	  	  	 tot-=v[pos[index]].f;
	  	  }

	  	  if(tot<=x)
	  	  {
	  	  	 ans = mid+1;
	  	  	 low = mid + 1;
	  	  }
	  	  else
	  	  	 high = mid - 1;
	  }
	  if(ans<pos[index])
	  {
	  	ans+=(x>=0);
	  }

	  return ans;
}

void Solve()
{
        
       
       cin>>n>>k;

       ll a[n+1];

       v.clear();
       cum.clear();
       leftest.clear();
       for(int i=1 ; i<=n ; i++)
       {
       	  cin>>a[i];
       	  v.push_back({min(a[i] + i, a[i] + n - i + 1), i-1});
       	  leftest.push_back(a[i] + i);
       }

       sort(v.begin(), v.end());

       for(int i=0; i<n ; i++)
       	pos[v[i].s] = i;

       ll tot = 0;
       for(auto i:v)
       	cum.push_back(tot+i.f), tot+=i.f;

       // for(auto i:v)
       // 	cout<<i.f<<" ";
       // cout<<endl;

       // for(auto i:v)
       // 	cout<<i.s<<" ";
       // cout<<endl;
       
       // for(int i=0 ; i<n ; i++)
       // 	cout<<pos[i]<<" ";
       // cout<<endl;

       // for(auto i:leftest)
       // 	cout<<i<<" ";
       // cout<<endl;
       // cout<<endl;

      
       int ans = 0;

       for(auto i:v)
       {
       	  ans = max(ans, foo(i.s, k - leftest[i.s]));
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