/*
* @Author: Zakaria
* @Date:   2022-08-24 07:55:54
* @Last Modified time: 2023-04-11 01:05:58
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

const int N = 4000;
const int mod = 1e9 + 7;
string s;
ll dp[N][2005][2];
ll POWER[N];

ll getsum(int pos, int cur, bool ok)
{
        

        if (pos == s.size())
        {
                cout<<cur<<endl;
                return cur == 0;
        }


        ll &R = dp[pos][cur][ok];

        if (R != -1)
                return R;

        int maxdigit = 9;
        if (!ok)
                maxdigit = s[pos] - '0';

        ll res = 0;


        for (ll i = 0 ; i <= maxdigit ; i++)
        {
             

                if (i < maxdigit || ok)
                {
                        int len = s.size() - pos - 1;
                        ll tot = i * (POWER[len]) *1LL;
                        ll temp = cur + tot;
                        //temp %= k;
                        res += getsum(pos + 1, temp, true);
                        res %= mod;
                }
                else
                {
                        int len = s.size() - pos - 1;
                        ll tot = i * (POWER[len])*1LL;
                        ll temp = cur + tot;
                        //temp %= k;
                        res += getsum(pos + 1, temp, false);
                        
                        res%=mod;
                }
        }


        return R = res;

}

void PowerGenerate()
{
        ll temp = 1;
        POWER[0] = temp;
        for (int i = 1 ; i < 15 ; i++)
        {
                temp*=10LL;
                POWER[i] = temp;
                
        }
}

void Solve()
{


        PowerGenerate();        

        string a;
        cin>>a;


        memset(dp, -1, sizeof(dp));

        s = a;

        ll tot = 0;
        tot = getsum(0, 0, 0);

        

}

int main()
{

        ios::sync_with_stdio(false);
        cin.tie(0);

        int tt = 1;

        //cin>>tt;

        while (tt--)
        {

                Solve();
        }

        return 0;

}
//https://codeforces.com/contest/628/problem/D