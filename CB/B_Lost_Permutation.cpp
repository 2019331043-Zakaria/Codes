/*
* @Author: Zakaria 
* @Date:   2022-11-18 20:40:34
* @Last Modified time: 2022-11-18 20:44:26
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
        
       int n, s;
       cin>>n>>s;

       int a[n];
       map<int, int>m;
       
       int mx = 0;

       for(int i=0 ; i<n ; i++)
       	cin>>a[i], m[a[i]]=1, mx = max(mx, a[i]);


       for(int i=1 ; i<=mx ; i++)
       {
       	   if(m[i])
       	   	continue;
       	   else
       	   {
       	   	  if(s>=i)
       	   	  	s-=i;
       	   	  else
       	   	  {
       	   	  	 cout<<"NO"<<endl;
       	   	  	 return ;
       	   	  }
       	   }
       }

       for(int i=mx+1 ; ; i++)
       {
       	  if(s==0)
       	  	break;
       	  else
       	  {
       	  	if(s>=i)
       	  		s-=i;
       	  	else
       	  	{
       	  		cout<<"NO"<<endl;
       	  		return ;
       	  	}
       	  }
       }

       cout<<"YES"<<endl;


      
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