/*
* @Author: Zakaria 
* @Date:   2022-10-07 11:56:57
* @Last Modified time: 2022-10-07 12:09:25
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

const int mod = 100000000 ;
const int N = 2e5+6;

ll dp[101][101][11][11]; 
int n1, n2, k1, k2;

ll foo(int foot, int horse, int foot_in_arow, int horse_in_arow)
{
     
      if(foot==0 && horse==0 && foot_in_arow>=0 && horse_in_arow>=0)
      	return 1;

      if(foot<0 || horse<0 || foot_in_arow<0 || horse_in_arow<0)
      	return 0;
      
      ll &R = dp[foot][horse][foot_in_arow][horse_in_arow];

      if(R!=-1)
      	return R;

      R = (foo(foot-1, horse, foot_in_arow-1, k2) + foo(foot, horse-1, k1, horse_in_arow-1) )%mod;

      return R;

}

void Solve()
{
        
       cin>>n1>>n2>>k1>>k2;

       memset(dp, -1, sizeof(dp));
       


       cout<<foo(n1, n2, k1, k2)<<endl;
      
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;
        
     //   cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 