/*
* @Author: Zakaria 
* @Date:   2022-10-01 18:00:47
* @Last Modified time: 2022-10-01 18:08:10
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
       char hex_string[255];
       
       sprintf(hex_string, "%X", n);
       if(n<=15)
       	cout<<0;
       cout<<hex_string<<endl;
}
 
int main()
{
         
      /*  ios::sync_with_stdio(false);
        cin.tie(0);*/
        
        int tt=1;
        
      //  cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 