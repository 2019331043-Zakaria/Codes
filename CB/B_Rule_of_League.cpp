/*
* @Author: Zakaria 
* @Date:   2022-09-19 20:43:31
* @Last Modified time: 2022-09-19 20:53:45
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
        
         ll n, x, y;

         cin>>n>>x>>y;

         if(x && y)
         {
         	cout<<-1<<endl;
         	return;
         }

         if(x==0 && y==0)
         {
         	cout<<-1<<endl;
         	return ;
         }


         x=max(x, y);

         if((n-1)%x)
         {
         	 cout<<-1<<endl;
         	 return ;
         }
         int win=1;
         int cnt=0;
         for(int i=2 ; i<=n ; i++)
         {
         	  if(cnt==x)
         	  {
         	  	win=i;
         	  	cnt=0;
         	  }
              cout<<win<<" ";
              cnt++;
         }
         cout<<endl;

      
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