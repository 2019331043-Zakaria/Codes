/*
* @Author: Zakaria 
* @Date:   2022-10-17 20:35:33
* @Last Modified time: 2022-10-17 20:39:40
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

       set<int>st;

       for(int i=1 ; i<=n ; i++)
       {
           int x;
           cin>>x;
           st.insert(x);
       }

       int baki = 10 - st.size();

       if(baki<=1)
       {
       	  cout<<0<<endl;
       	  return ;
       }

       cout<<6*((baki*(baki-1))/2)<<endl;
      
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