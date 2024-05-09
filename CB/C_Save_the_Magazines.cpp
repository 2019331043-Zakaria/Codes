/*
* @Author: Zakaria 
* @Date:   2022-10-17 20:42:54
* @Last Modified time: 2022-10-17 21:32:31
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
        string s;

        cin>>n;
        cin>>s;
        ll a[n];

        for(int i=0 ; i<n ; i++)
        	cin>>a[i];

        ll ans=0;
        

       

        vector<int>v;
        
        v.push_back(-1);

       
        for(int i=0 ; i<n-1 ; i++)
        {
        	if(s[i]=='0')
        	{
        		if(s[i+1]=='1')
        			v.push_back(i);
        	}
        }

        

        for(auto i:v)
        {
        	priority_queue<ll>pq;
            if(i>=0)
        	pq.push(a[i]);
        	int index=i+1;
            int cnt=0;
            bool ok=0;
        	while(index<n)
        	{
                 if(s[index]=='1')
                 	pq.push(a[index]), cnt++, index++;
                 else
                 {

                 	 break;
                 }

                
        	}
           
        		
			while(cnt--)
				ans+=pq.top(), pq.pop();

        		
        		//break;
        	
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