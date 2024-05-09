/*
* @Author: Zakaria 
* @Date:   2022-09-04 00:27:09
* @Last Modified time: 2022-09-04 01:11:29
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
#define  MAX         200002
#define  eps         1e-6
typedef long long ll;
using namespace std;

void Solve()
{
        string s;
        cin>>s;

        if(s=="Friday")       
         cout<<1<<endl;
        if(s=="Thursday")
        cout<<2<<endl;
        if(s=="Wednesday")
        cout<<3<<endl;
        if(s=="Tuesday")
        cout<<4<<endl;
        if(s=="Monday")
        cout<<5<<endl;

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