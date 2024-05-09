/*
* @Author: Zakaria 
* @Date:   2022-12-08 16:31:51
* @Last Modified time: 2022-12-08 21:26:32
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

unsigned long long pos, neg;

void Solve()
{
        
        ll sum = 0;
       
        int n;
        cin>>n;

        map<ll, ll>m;
        
        for(int i=1 ; i<=n ; i++)
        {
            ll x;
            cin>>x;
            ll temp = sum;
            ll cntless = m[x-1];
            ll cntequal = m[x];
            ll cntegreat = m[x+1];

            ll total = i-1;
            total-=(cntegreat+cntequal+cntless);

            temp-=cntless*(x-1);
            temp-=cntegreat*(x+1);
            temp-=cntequal*(x);
            
            ll result = total*x - temp;
           
            if(result>0)
                pos = pos + result;
            else
                neg = neg + abs(result);

            m[x]++;
            sum+=x;

        }
        
        

        if(pos>=neg)
            cout<<pos-neg<<endl;
        else
            cout<<"-"<<neg-pos<<endl;
      
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