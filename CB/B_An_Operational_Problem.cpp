/*
* @Author: Zakaria 
* @Date:   2023-03-26 01:26:09
* @Last Modified time: 2023-03-26 01:36:38
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
       {
       	  cin>>a[i];
       }

       int mx = 0;

       while(1)
       {
       	    ll sum = 0;
       	    ll odd = 0;
       	    for(auto i:a)
       	    	odd+=i%2, sum+=i;


       	    if(sum%2)
       	    {
       	    	cout<<mx<<endl;
       	    	return ;
       	    }
       	    if(sum%2==0)
       	    {
       	    	if(odd)
       	    	{
       	    		cout<<mx+1<<endl;
       	    		return ;
       	    	}
       	    }

       	    for(int i=0 ; i<n ; i++)
       	    	a[i]/=2;

       	    mx++;
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