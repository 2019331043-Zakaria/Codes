/*
* @Author: Zakaria 
* @Date:   2022-10-28 16:36:10
* @Last Modified time: 2022-10-28 18:02:03
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

ll n, m;

ll a[N], b[N];
vector<ll>one, two;
vector<ll>CumTwo;
int foo(ll x)
{
	  int low = 0, high = two.size(), mid;
	  int index = two.size() + 1;

	  while(low<=high)
	  {
	  	 mid = (low+high)/2;
	  	 if(CumTwo[mid]>=x)
	  	 	index = mid, high = mid - 1;
	  	 else
	  	 	low = mid + 1;
	  }

	  if(index<=two.size())
	  	return index;
	  else
	  	return 1e9;

}
void Solve()
{
        
       
       cin>>n>>m;

       for(int i=1 ; i<=n ; i++)
       	cin>>a[i];

       for(int i=1 ; i<=n ; i++)
       	cin>>b[i];
       
       one.clear();
       two.clear();
       CumTwo.clear();

       for(int i=1 ; i<=n ; i++)
       {
       	   if(b[i]==1)
       	   	one.push_back(a[i]);
       	   else
       	   	two.push_back(a[i]);
       }

       sort(one.rbegin(), one.rend());
       sort(two.rbegin(), two.rend());

       ll pans = 0;

       CumTwo.push_back(0);

       for(auto i:two)
       {
       	  pans+=i;
       	  CumTwo.push_back(pans);
       }
       
       ll sum = 0;

       int ans = 2*foo(m - sum);
       
       for(int i=0 ; i<one.size() ; i++)
       {
            sum+=one[i];

            ans = min(ans, i + 1 + 2*foo(m-sum));
       }
       
       if(ans<1e9)
       cout<<ans<<endl;
       else
       	cout<<-1<<endl;





       
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