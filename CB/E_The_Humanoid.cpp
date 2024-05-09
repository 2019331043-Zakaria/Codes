/*
* @Author: Zakaria 
* @Date:   2022-11-18 21:50:01
* @Last Modified time: 2022-11-19 15:14:24
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

ll a[N];
ll n, m;

int foo(int p, int q, int r)
{
       ll Health = m;
       int cnt = 0;
       int i = 1;

       while(i<=n)
       {
            if(Health>a[i])
            {
                Health+=a[i]/2;
                cnt++;
                i++;
                continue;
            }
         
            if(p)
            {
                Health = 1LL * Health * p;
                p = 0;
                continue;
            }

            if(q)
            {
                Health = 1LL * Health * q;
                q = 0;
                continue; 
            }

            if(r)
            {
                Health = 1LL * Health * r;
                r = 0;
                continue;
            }

            break;


       }

       return cnt;
}

void Solve()
{
        cin>>n>>m;

        for(int i = 1 ; i<=n ; i++)
            cin>>a[i];


        sort(a+1, a+n+1);
    
        cout<<max({foo(2, 2, 3), foo(2, 3, 2), foo(3, 2, 2)})<<endl;
       
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