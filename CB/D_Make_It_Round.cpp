/*
* @Author: Zakaria 
* @Date:   2022-11-18 21:27:46
* @Last Modified time: 2022-11-18 21:46:57
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
        
       ll n, m;
       cin>>n>>m;

       ll N_temp = n;
       ll M_temp = m;

       ll two = 0, five = 0;

       while(N_temp%2==0)
        two++, N_temp/=2;

       while(N_temp%5==0)
        five++, N_temp/=5;
       
     //  cout<<two<<" "<<five<<endl;

       for(int total = 18 ; total>=0 ; total--)
       {
               
             int temp2 = two;
             int temp5 = five;

             int twolage = max(0, total - temp2);

             int fivelage = max(0, total - temp5);

            // cout<<twolage<<" "<<fivelage<<endl;

             ll pans = 1;

             for(int i=1 ; i<=twolage ; i++)
                pans*=2LL;

             for(int i=1 ; i<=fivelage ; i++)
                pans*=5LL;
             
            
             if(pans>m)
                continue;
             
           //  cout<<pans<<endl;

             ll rem = m/pans;

             rem*=pans;

             cout<<n*rem<<endl;

             return ;




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