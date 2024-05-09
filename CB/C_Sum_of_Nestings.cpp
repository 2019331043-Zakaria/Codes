/*
* @Author: Zakaria 
* @Date:   2022-09-11 10:45:10
* @Last Modified time: 2022-09-11 16:44:45
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
        
       ll n, k;
       cin>>n>>k;
       
       ll value=0;
       ll sum=0;

       for(ll i=1 ; i<=n ; i++)
       {
           ll temp=i-1;
           sum=(temp*(temp+1))/2;
           
           if(sum>=k)
           {
              value=i;
              break;
           }
       }

       if(!value)
       {
          cout<<"Impossible\n";
          return ;
       }

       string ans="";

       for(int i=1 ; i<=value ; i++)
        ans+='(';
       for(int i=1 ; i<=value ; i++)
        ans+=')';

       ll rem = sum-k;

      // cout<<ans<<endl;

       if(rem)
       {
          ans[value-1]=')';

          ans[value-1+rem]='(';
       }
       

       for(int i=1 ; i<=(n+n-value-value)/2 ; i++)
       {
          ans+="()";
       }

       cout<<ans<<endl;

       
      
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;
        
       // cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 

/*
()()()()()
(())()()()
(()())()()
((()))()()
((())())()
((()()))()
(((())))()
(((()))())
(((())()))
(((()())))
((((()))))
*/