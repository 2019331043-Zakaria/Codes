/*
* @Author: Zakaria
* @Date:   2021-09-14 15:44:21
* @Last Modified time: 2022-06-06 21:04:19
*/
#include <bits/stdc++.h>
#define  pb          push_back
#define  f           first
#define  s           second
#define  pi          acos(-1.0)
#define  LCM(a,b)    a*b/__gcd(a,b)
#define  GCD(a,b)    __gcd(a,b)
#define  mod         1000000007
#define  sof         sizeof
#define  endl        '\n'
#define  MAX         2000002
#define  sz          200005
typedef long long ll;
using namespace std;

ll bigmod(ll a,ll b,ll n)
{
    ll res=1;
    a=a%n;
    if(a==0)
        return 0;
    while(b>0)
    {

            if(b%2)
            res=(res*a)%n;
            b=b/2;
            a=(a*a)%n;
    }
    return res;
}

void Solve()
{
    
           
           string s;
           cin>>s;

           ll a, b;
           cin>>a>>b;

          
           ll pre=0;
           
           int n=s.size();
           
           ll pans[n], lans[n];
           
           memset(pans, 0 , sizeof pans);
           memset(lans , 0, sizeof lans);

           for(int i=0 ; i<s.size() ; i++)
           {
               pre*=10LL;
               pre+=(s[i]-'0');
               pre%=a;
               if(pre%a==0)
                  pans[i]=1;
           }

       
           ll post=0;
           int cnt=0;

           for(int i=n-1 ; i>=0 ; i--)
           {
                cnt++;
                
               
                ll temp=bigmod(10 , cnt-1, b);
            
                temp*=(s[i]-'0');
                temp%=b;
                temp+=post;
                temp%=b;
                 
                if(temp==0 && s[i]!='0')
                {
                     lans[i]=1;
                }
                post=temp;
               

           } 

        
           string ans="";
           for(int i=1 ; i<n ; i++)
           {
               ans+=s[i-1];
               if(lans[i] && pans[i-1])
               {
                     cout<<"YES\n";
                     cout<<ans<<endl;
                     for(int j=i ; j<n ; j++)
                        cout<<s[j];
                     cout<<endl;
                     return ;
               }
           }
           cout<<"NO\n";



      
}

int main()
{
            ios::sync_with_stdio(false);
            cin.tie(0);
           
            int tt=1;
            //cin>>tt;
            while(tt--)
            {
                  Solve();
            }

            return 0;

}
