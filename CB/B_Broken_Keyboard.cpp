/*
* @Author: Zakaria 
* @Date:   2022-11-27 20:35:12
* @Last Modified time: 2022-11-27 20:38:21
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

       if(n==1)
       {
       	  cout<<"YES"<<endl;
       	  return ;
       }

       if(n%3==2)
       {
       	  cout<<"NO"<<endl;
       	  return ;
       }

       for(int i=0 ; i<n ; i+=3)
       {
            if(i+1<n && i+2<n)
            {
            	if(s[i+1]!=s[i+2])
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