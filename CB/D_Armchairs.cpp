/*
* @Author: Zakaria 
* @Date:   2022-10-04 13:08:04
* @Last Modified time: 2022-10-04 13:19:00
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

vector<ll>person, emptychair;
ll dp[5005][5005]; //dp[i][j] -> i person , j chair

ll foo(int i, int j)
{
	   if(i<0)
	   	return 0;
	   if(j<0)
	   	return 1e9;

	   ll &R = dp[i][j];
	   if(R!=-1)
	   	return R;

	   return R = min(foo(i, j-1) ,  abs(person[i] - emptychair[j]) + foo(i-1, j-1));

}

void Solve()
{
        
       int n;
       cin>>n;
       
       for(int i=1 ; i<=n ; i++)
       {
       	   int x;
       	   cin>>x;
       	   if(x) person.push_back(i);
       	   else  emptychair.push_back(i);
       }

       memset(dp, -1, sizeof(dp));
       
       cout<<foo(person.size()-1 , emptychair.size()-1)<<endl;

        
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