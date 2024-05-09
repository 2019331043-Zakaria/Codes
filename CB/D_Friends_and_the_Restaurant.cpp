/*
* @Author: Zakaria 
* @Date:   2022-09-12 21:51:02
* @Last Modified time: 2022-09-12 22:20:02
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
        for(int i=0 ; i<n ; i++)
        	cin>>a[i];
        ll b[n];

        for(int i=0 ; i<n ; i++)
        	cin>>b[i];


        vector<ll>v;

        for(int i=0 ; i<n ; i++)
        {
        	v.push_back(b[i]-a[i]);
        }

        sort(v.begin(), v.end());
        deque<ll>q;
        for(auto i:v)
        	q.push_back(i);

        int ans=0;

        while(q.size()>=2)
        {
        	ll sum=q.front()+q.back();

        	if(sum>=0)
        	{
        		ans++;
        		q.pop_front();
        		q.pop_back();
        	}
        	else
        	{
        		q.pop_front();
        	}
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