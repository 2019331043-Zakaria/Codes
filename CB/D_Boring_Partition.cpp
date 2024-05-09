/*
* @Author: Zakaria 
* @Date:   2022-09-10 09:07:37
* @Last Modified time: 2022-09-10 09:39:19
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
#define  MAX         200002
#define  eps         1e-6
typedef long long ll;
using namespace std;

const int N = 2e5+6;

ll ans[N];

struct type
{
	 ll value, index;

};

bool comp(type a, type b)
{
	  return a.value<b.value;
}

void Solve()
{
        
        ll n, k;
        cin>>n>>k;
        
        type a[n+1];

        for(int i=1 ; i<=n ; i++)
        {
        	cin>>a[i].value;
        	a[i].index = i;
        }
       
        sort(a+1, a+n+1, comp);


        ll res = a[n].value + a[n-1].value - (a[1].value + a[2].value);
        
        if(n==2)
        {
        	 cout<<res<<endl;
        	 cout<<1<<" "<<1<<endl;
        	 return ;
        }

        ll temp=res;

        for(int i=2 ; i<=n ; i++)
        {
        	  ll mx = max(a[n].value + a[n-1].value, a[n].value + a[1].value + k);

        	  ll mn = min(a[2].value + a[3].value , a[1].value + a[2].value + k);

        	  temp=min(temp, mx - mn);
        }

        if(res<=temp)
        {
        	cout<<res<<endl;
        	for(int i=1 ; i<=n ; i++)
        		cout<<1<<" ";
        	cout<<endl;
        }
        else
        {
        	cout<<temp<<endl;
        	
        	ans[a[1].index]=1;

        	for(int i=2 ; i<=n ; i++)
        		ans[a[i].index]=2;
            
            for(int i=1 ; i<=n ; i++)
            	cout<<ans[i]<<" ";

            cout<<endl;

        }

      
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;
        
      //  cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 