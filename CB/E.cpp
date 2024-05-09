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

mt19937_64 rnd64(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> gen(0, LLONG_MAX);

const int mod = 998244353;
const int N = 5e5 + 6;

ll fact[N];

ll bigmod(ll b, ll p)
{
    if (p == 0) return 1;
    ll h = bigmod(b, p / 2);
    h = h * h % mod;
    if (p & 1) h = h * b % mod;
    return h;
}

ll ncr(ll n, ll r)
{
    if (n < r)
        return 0;
    return fact[n] * bigmod(fact[r] * fact[n - r] % mod, mod - 2) % mod;
}

void Fact()
{
    fact[0] = 1;
    for (int i = 1; i < N; i++) fact[i] = fact[i - 1] * i % mod;
}

ll calculate(ll n)
{

    if (n % 2)
        return 0;

    ll temp = ncr(n, n / 2);
    ll inv = bigmod((n / 2) + 1, mod - 2);
    temp %= mod;
    inv %= mod;
    temp *= inv;
    temp %= mod;

    return temp;
}

void Solve()
{

    ll n, k;
    cin >> n >> k;

    ll jor[n + 5];
    memset(jor, 0, sizeof(jor));

    for (int i = 1; i <= k ; i++)
    {
        int l, r;
        cin >> l >> r;

        ll xx = gen(rnd64);

        jor[l] ^= xx;
        jor[r + 1] ^= xx;
    }

    map<ll, ll>freq;

    for (int i = 1 ; i <= n ; i++)
        jor[i] ^= jor[i - 1], freq[jor[i]]++;

    ll ans = 1;

    for (auto i : freq)
        ans *= calculate(i.s), ans %= mod;

    cout << ans << endl;
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);


    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    Fact();

    int tt = 1, testcae = 1;

    cin >> tt;

    while (tt--)
    {

        //cout<<"Case "<<testcae++<<": ";

        Solve();
    }

    return 0;

}