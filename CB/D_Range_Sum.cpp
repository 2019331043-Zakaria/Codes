/*
* @Author: Zakaria 
* @Date:   2022-11-25 23:07:07
* @Last Modified time: 2022-11-26 14:43:06
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
        
      ll n;
      cin>>n;

    
      if(n%2==0)
      {
          for(int i=n/2 ; i<=(n/2)+n ; i++)
          {
            if(i==n) continue;
            else
                cout<<i<<" ";
          }

          cout<<endl;
      }
      else
      {
           ll temp = (n+1)/2;

           temp++;
        
           set<int>st;

           ll sum = 0;
            
           for(int i=temp ; i<=temp+n+1 ; i++)
           {
              
              st.insert(i);
           }

           st.erase(n+1);
           st.erase(n+2);

           for(auto i:st)
            cout<<i<<" ";

          cout<<endl;

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