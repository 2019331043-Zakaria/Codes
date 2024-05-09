/*
* @Author: Zakaria 
* @Date:   2022-09-19 21:31:58
* @Last Modified time: 2022-09-19 22:18:59
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

ll n, x, y;
string s, t;

void Solve()
{
        
        cin>>n>>x>>y;
        cin>>s>>t;

        ll ans=0;

        int match=0;

        for(int i=0 ; i<n ; i++)
        {
        	if(s[i]!=t[i])
        		match++;
        }

        if(match%2)
        {
        	cout<<-1<<endl;
        	return ;
        }
        
        vector<int>unmatch;

        for(int i=0 ; i<n ; i++)
        {
        	if(s[i]!=t[i])
        		unmatch.push_back(i);
        }

        if(unmatch.size()==2)
        {
           if(unmatch[1] - unmatch[0]==1)
           {
           	    if(n==2)
           	    {
           	    	cout<<x<<endl;
                }
                else if(n==3)
                {
                	cout<<x<<endl;
                }
                else
                {
                	cout<<min(x, y+y)<<endl;
                }
           }
           else
           {
           	   cout<<y<<endl;
           }
        }
        else
        {
        	ll temp=unmatch.size()/2;
        	cout<<temp*y<<endl;
        }

       


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