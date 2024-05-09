/*
* @Author: Zakaria 
* @Date:   2022-09-19 20:55:53
* @Last Modified time: 2022-09-19 21:44:00
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

        int oddindex=n+1, evenindex=n+1;

        for(int i=1 ; i<=n ; i++)
        {
        	cin>>a[i];
        	if(a[i]%2)
        		oddindex=min(oddindex, i);
        	else
        		evenindex=min(evenindex, i);
        }

        
    	vector<int>odd, even;

    	for(int i=1 ; i<=n ; i++)
    	{
    		if(a[i]%2)
    		{
    			odd.push_back(i);
    		}
    		else
    			even.push_back(i);
    	}
        
        vector<pair<int, int> >ans;

        if(oddindex<evenindex)
        {
        	 
        	 for(auto i:odd)
        	 {
        	 	if(i!=odd.back())
        	    ans.push_back({i, odd.back()});
             }

        	 for(auto i:even)
        	 	ans.push_back({oddindex, i});
        }
        else
        { 
            for(auto i:even)
            {
            	if(i!=even.back())
            	ans.push_back({i, even.back()});
            }

            for(auto i:odd)
            	ans.push_back({evenindex, i});
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