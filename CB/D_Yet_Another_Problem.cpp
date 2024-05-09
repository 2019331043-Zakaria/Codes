/*
* @Author: Zakaria 
* @Date:   2022-12-09 00:57:41
* @Last Modified time: 2022-12-09 02:25:08
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

ll cumXor[N];
ll a[N];
ll prefsum[N];
map<ll, vector<int> > v[2];
int n, q;

void Solve()
{

      cin>>n>>q;

      for(int i=1 ; i<=n ; i++)
      {
      	cin>>a[i];
      	prefsum[i] = prefsum[i-1] + a[i];
      	cumXor[i] = cumXor[i-1]^a[i];
      	v[i%2][cumXor[i]].push_back(i);
      }

      while(q--)
      {
      	 int l, r ;
      	 cin>>l>>r;
        
      	 if(cumXor[r]^cumXor[l-1])
      	 {
      	 	cout<<-1<<endl;
      	 	continue;
      	 }

      	 if(prefsum[r] == prefsum[l])
      	 {
      	 	cout<<0<<endl;
      	 	continue;
      	 }

      	 int len = r - l + 1;

      	 if(len%2)
      	 {
      	 	cout<<1<<endl;
      	 	continue;
      	 }
      	 else
      	 {
      	 	if(!a[l] || !a[r])
      	 	{
      	 		cout<<1<<endl;
      	 		continue;
      	 	}

      	 	ll Checkvalue = cumXor[l-1];

      	 	auto it = lower_bound(v[l%2][Checkvalue].begin(), v[l%2][Checkvalue].end(), l);

      	 	if(it == v[l%2][Checkvalue].end() || *it>r)
      	 	{
      	 		cout<<-1<<endl;
      	 		continue;
      	 	}
      	 	else
      	 	{
      	 		cout<<2<<endl;
      	 		continue;
      	 	}
      	 }


      }

}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;
        
    //    cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 