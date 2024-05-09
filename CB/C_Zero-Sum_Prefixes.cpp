/*
* @Author: Zakaria 
* @Date:   2022-11-12 21:17:47
* @Last Modified time: 2022-11-12 22:24:37
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

        vector<int>v;

        for(int i=1 ; i<=n ; i++)
        	cin>>a[i];

        for(int i=1 ; i<=n ; i++)
        {
        	if(a[i]==0)
        		v.push_back(i);
        }

        ll ans = 0;

        ll sum = 0;

        if(v.size()==0)
        {
        	for(int i=1 ; i<=n ; i++)
        	{
        		sum+=a[i];
        		if(sum==0)
        			ans++;
        	}

        	cout<<ans<<endl;
        	return ;
        }

        for(int i=1 ; i<v[0] ; i++)
    	{
    		sum+=a[i];
    		if(sum==0)
    			ans++;
    	}

    	for(int i=1 ; i<v.size() ; i++)
    	{
    		  map<ll, ll> cnt;
    		  ll mx = 1;
    		  ll tempsum = sum;
              ll pans = sum;
              ll mxsum = sum;

              int offset = 0;

    		  for(int j = v[i-1] ; j<v[i] ; j++)
    		  {
    		  	 offset++;
    		  	 tempsum+=a[j];
    		  	 cnt[tempsum]++;
    		  	 if(cnt[tempsum]>mx)
    		  	 {
    		  	 	 mx = cnt[tempsum];
    		  	 	 mxsum = tempsum;
    		  	 }
    		  }

    		  ans+=max(mx, 1LL);
    		  /*if(mxsum==sum && offset)
    		  {
    		  	  ans++;
    		  	  cout<<v[i]<<" ok"<<endl;
    		  }
    		  cout<<v[i]<<" => "<<mxsum<<endl;*/

    		  tempsum+=(-1LL*mxsum);
    		  sum = tempsum;
    	}
     
		map<ll, ll> cnt;
		ll mx = 1;
		ll tempsum = sum;
		ll pans = sum;
		ll mxsum = sum;

        for(int j=v.back() ; j<=n ; j++)
        {
              tempsum+=a[j];
              cnt[tempsum]++;
              if(cnt[tempsum]>mx)
              {
              	  mx = cnt[tempsum];
              }
        }
    	cout<<ans+max(mx, 1LL)<<endl;




      
        
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