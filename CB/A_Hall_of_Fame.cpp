/*
* @Author: Zakaria 
* @Date:   2023-01-03 20:37:32
* @Last Modified time: 2023-01-03 20:49:18
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

       string s;
       cin>>s;

       vector<int>left;


       for(int i=0 ; i<n ; i++)
       {
       	   if(s[i]=='R')
       	   	left.push_back(i+1);
       }

       if(left.size()==n || left.size()==0)
       {
       	  cout<<-1<<endl;
       }
       else
       {
       	    int tempR = n+1, tempL = 0;

       	    for(int i=0 ; i<n ; i++)
       	    {
               if(s[i]=='R')
               	tempR = min(tempR, i+1);
               else
               	tempL = max(tempL, i+1);
       	    }

       	    if(tempR<tempL)
       	    {
       	    	cout<<0<<endl;
       	    	return;
       	    }

       	    for(int i=0 ; i<n ; i++)
       	    {
       	    	if(s[i]=='R')
       	    	{
       	    		cout<<i<<endl;
       	    		return ;
       	    	}
       	    }

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