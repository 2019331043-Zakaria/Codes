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

mt19937 mt_rand(chrono::high_resolution_clock::now().time_since_epoch().count());

const int mod = 1e9 + 7;
const int N = 1e5 + 5;;

bitset<N>bset[30];
bitset<N>pattern;

void Solve()
{

    string s;
    cin >> s;

    int n = s.size();

    for (int i = 0 ; i < 26 ; i++) {
        for (int j = n - 1 ; j >= 0 ; j--) {
            if (s[j] - 'a' == i)
            {
                bset[i][j] = 1;
            }
        }
    }

    int q;
    cin >> q;

    while (q--)
    {
      
        int type;
        cin >> type;
        if (type == 1)
        {
            int idx;
            char c;
            cin >> idx >> c;

            char d = s[idx - 1];
            s[idx - 1] = c;

            bset[d - 'a'].reset(idx - 1);

            bset[c - 'a'].set(idx - 1);

        }
        else
        {
            int l, r;
            cin >> l >> r;
            string p;
            cin >> p;

            int m = p.size();
            pattern.set();

            for (int i = 0 ; i < m ; i++)
            {
                pattern &= (bset[p[i] - 'a']);
                if (i != (m - 1))
                    pattern <<= 1;
            }

            l+=(m-1);

            int bad = l - 1;
            pattern >>= bad;
         
            int x = pattern.count();

            r -= bad;
            bad = r;
            pattern >>= bad;

            x -= pattern.count();

            cout << x << endl;


        }
    }
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);


    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    int tt = 1, testcae = 1;

    // cin >> tt;

    while (tt--)
    {

        //cout<<"Case "<<testcae++<<": ";

        Solve();
    }

    return 0;

}