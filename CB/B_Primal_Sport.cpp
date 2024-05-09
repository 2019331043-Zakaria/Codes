/*
* @Author: Zakaria
* @Date:   2023-02-27 01:48:55
* @Last Modified time: 2023-02-27 13:58:00
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

const int mod = 1e9 + 7;
const int N = 2e5 + 6;

#define sz 10000010
bool siv[sz];
int lps[sz];
set<int>factor;
int n, m;
void seive()
{
    int  limit = sqrt(sz + 1);

    for (int i = 1 ; i < sz ; i++)
        lps[i] = i;

    for (int i = 2 ; i < sz ; i += 2)
        lps[i] = 2;

    for (int  i = 3; i <= limit; i += 2)
        if (!siv[i])
            for (int  j = i * i; j < sz; j += i + i)
                siv[j] = 1, lps[j] = min(lps[j], i);
}

set<int>foo(int x)
{
    set<int>st;
    while(x>1)
        st.insert(lps[x]), x/=lps[x];

    return st;
}

void Solve()
{

    seive();

    
    cin >> n;
    
    m = n;

    while (m > 1)
    {
        factor.insert(lps[m]);
        m /= lps[m];
    }

    int ans = n;

    for(auto i:factor)
    {
        int left = n - i + 1;
        int right = n;

        for(int k = left ; k<=right ; k++)
        {
             set<int>tempfact;

             tempfact = foo(k);

             for(auto p:tempfact)
             {
                if(p==k)
                    ans = min(ans, k);
                else
                    ans = min(ans, k-p+1);
             }
        }
    }

    cout<<ans<<endl;



    


}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt = 1;

    // cin>>tt;

    while (tt--)
    {

        Solve();
    }

    return 0;

}