/*
* @Author: Zakaria
* @Date:   2022-08-24 07:55:54
* @Last Modified time: 2023-04-11 01:07:12
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

const int N = 105;
const int mod = 998244353;
string s;
ll dp[N][2][2]; // age kothao zero paisi kina
ll POWER[N];
ll k, d;

ll getsum(int pos,  bool ok, bool foursevenpaisi)
{
        

        if (pos == s.size())
        {
            return 1;
        }


        ll &R = dp[pos][ok][foursevenpaisi];

        if (R != -1)
                return R;

        int maxdigit = 9;
        if (!ok)
                maxdigit = s[pos] - '0';

        ll res = 0;
        for (ll i = 0 ; i <= maxdigit ; i++)
        {
            
            if(i==4 || i==7 || (i==0 && !foursevenpaisi))    
            {
                if (i < maxdigit || ok)
                {
                        if(i==4 || i==7)
                            foursevenpaisi = 1;
                        res += getsum(pos + 1, true, foursevenpaisi);
                        res %= mod;
                }
                else
                {
            
                        if(i==4 || i==7)
                            foursevenpaisi = 1;
                        res += getsum(pos + 1, false, foursevenpaisi);
                        res%=mod;
                }
            }
        }


        return R = res;

}


void Solve()
{


        string a;
        cin>>a;


        memset(dp, -1, sizeof(dp));

        s = a;

        ll tot = 0;
        tot = getsum(0, 0, 0);

        cout<<tot-1<<endl;

        

}

int main()
{

        ios::sync_with_stdio(false);
        cin.tie(0);

        int tt = 1;

    //    cin>>tt;

        while (tt--)
        {

                Solve();
        }

        return 0;

}