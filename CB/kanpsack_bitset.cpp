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

void Solve()
{

    int n;
    cin >> n;

    bitset<1000001> dp;

    dp[0] = 1;
    int sum = 0;

    for (int i = 0 ; i < n ; i++)
    {
        int x;
        cin >> x;
        dp |= (dp << x);
        sum += x;
    }

    int ans = 1e9;

    for (int i = 0 ; i <= 100000 ; i++)
    {
        if (dp[i])
            ans = min(ans, max(i, sum - i));
    }

    cout << ans << endl;

}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);


    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    int tt = 1, testcae = 1;

    //cin >> tt;

    while (tt--)
    {

        //cout<<"Case "<<testcae++<<": ";

        Solve();
    }

    return 0;

}