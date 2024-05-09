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
const int MXN = 5e5 + 7;

const int BASE [] = {1231, 1567};
const int MOD [] = {1000000000 + 7, 1000000000 + 9};
#define ll long long int

int n;
string s;

ll HASH[2][MXN], POW[2][MXN];

void init()
{
    POW[0][0] = POW[1][0] = 1;
    for (int b = 0; b < 2; b++) {
        for (int j = 1; j < MXN; j++) {
            POW[b][j] = (POW[b][j - 1] * BASE[b]) % MOD[b];
        }
    }
}

pair<ll, ll> initHash(string str) //str 0 base indexing so no '*' + s
{
    int len = str.size();
    HASH[0][0] = HASH[1][0] = 0;
    for (int b = 0; b < 2; b++) {
        for (int i = 1; i <= len; i++) {
            HASH[b][i] = (HASH[b][i - 1] * BASE[b] + (str[i - 1] - 'a' + 1)) % MOD[b];
        }
    }
    return make_pair(HASH[0][len], HASH[1][len]);
}

ll getHash(int left, int right, int hsh)
{
    int len = (right - left + 1);
    ll ret = (HASH[hsh][right] - HASH[hsh][left - 1] * POW[hsh][len]) % MOD[hsh];
    if (ret < 0) ret += MOD[hsh];
    return ret;
}

pair<ll, ll> getHash(int left, int right)
{
    ll hsh0 = getHash(left, right, 0);
    ll hsh1 = getHash(left, right, 1);

    return make_pair(hsh0, hsh1);
}


void Solve()
{
    cin >> n >> s;

    s += s;

    initHash(s);

    int low = 1, high = n, mid;
    int ans = 0;

    while (low <= high)
    {
        mid = (low + high) / 2;

        bool ok = 0;
        set<pair<ll, ll> > st;

        for (int i = 1 ; i <= n ; i++)
        {
            int l = i;
            int r = i + mid - 1;

            pair<ll, ll>p;
            p = getHash(l, r);

            if (st.find(p) != st.end())
            {
                ok = 1;
                break;
            }

            st.insert(p);

        }

        if (ok)
            ans = mid, low = mid + 1;
        else
            high = mid - 1;
    }

    cout << ans << endl;
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);

    init();

    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    int tt = 1, testcae = 1;

    cin >> tt;

    while (tt--)
    {

        //cout<<"Case "<<testcae++<<": ";

        Solve();
    }

    return 0;

}