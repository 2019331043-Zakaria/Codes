/*
* @Author: Zakaria 
* @Date:   2022-09-23 18:28:06
* @Last Modified time: 2022-09-23 23:36:19
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

         int ache[n+1], nai[n+1];
         for(int i=1 ; i<=n ; i++)
            ache[i]=0, nai[i]=0;

         for(int i=1 ; i<=n ; i++)
         {
             if(s[i-1]=='1')
                ache[i]=1;
             else
                nai[i]=1;
         }

         int minimummultiple[n+1];

         for(int i=1 ; i<=n ; i++)
            minimummultiple[i]=i;
         

         for(int i=1 ; i<=n ; i++)
         {
             int add=i;
             int temp=i;
             
             while(temp<=n)
             {
               
                if(ache[temp])
                {
                    break;
                }
                else
                {

                    minimummultiple[temp]=min(minimummultiple[temp], i);
                }
                temp+=add;
             }
            
         }

         ll ans=0;

         for(int i=1 ; i<=n ; i++)
         {
             if(nai[i])
             {
               
                ans+=minimummultiple[i];
             }
         }

         cout<<ans<<endl;
      
       
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