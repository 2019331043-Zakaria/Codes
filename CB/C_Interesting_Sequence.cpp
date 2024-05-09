/*
* @Author: Zakaria 
* @Date:   2023-01-10 18:39:31
* @Last Modified time: 2023-01-11 15:06:32
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

ll twopower[66];

void Solve()
{
        
        ll n, x;
        cin>>n>>x;

      

        if(n==x)
        {
        	cout<<n<<endl;
        	return ;
        }

        if(x==0)
        {
        	for(ll i = 0 ; i<=62 ; i++)
        	{
        		ll temp = twopower[i];

        		if(temp>n)
        		{
        			cout<<temp<<endl;
        			return ;
        		}
        	}
        }

        ll tot = 0 ;

        map<ll, ll>ans;

        for(int i=62 ; i>=0 ; i--)
        {
        	 ll temp = twopower[i];

        	 if(temp&n)
        	 {
        	 	
        	 	tot+=temp;
        	 	bool zero  = 0;

        	 	for(int k=i-1 ; k>=0 ; k--)
        	 	{
        	 		ll pans = twopower[k];
                   

        	 		if(!(pans&n)) 
        	 		{
        	 			zero = 1;
        	 			
        	 		}
        	 		else 
        	 		{
                        if(zero)
                        {
                        	
                        	ans[tot] = tot + twopower[k+1];
                        	break;
                        }
                        else
                        {
                        	break;
                        }
        	 		}
        	 	}
        	 }
        }

        if(ans[x]==0)
        {
        	cout<<-1<<endl;
        }
        else
        	cout<<ans[x]<<endl;


      
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;
        
        for(int i=0 ; i<=62 ; i++)
        {
        	twopower[i] = (1LL<<i);
        }


        cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 