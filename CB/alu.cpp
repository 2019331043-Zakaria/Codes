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

#define db(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); cerr << "\n\n";}
void err (istream_iterator<string> it) {}
template<typename T, typename... Args>
void err (istream_iterator<string> it, T a, Args... args) {
    cerr << *it << "=" << a << " ! ";
    err (++it, args...);
}

template<class L, class R> ostream& operator << (ostream& out, pair<L, R>& p) { return out << "(" << p.f << ", " << p.s << ")"; }
template<class T> ostream& operator << (ostream& out, vector<T>& v) { out << "["; for (auto it = v.begin (); it != v.end (); ++it) { if (it != v.begin ())out << ", "; out << *it; } return out << "]"; }
template<class T> ostream& operator << (ostream& out, deque<T>& v) { out << "["; for (auto it = v.begin (); it != v.end (); ++it) { if (it != v.begin ())out << ", "; out << *it; } return out << "]"; }
template<class T> ostream& operator << (ostream& out, set<T>& s) { out << "{"; for (auto it = s.begin (); it != s.end (); ++it) { if (it != s.begin ())out << ", "; out << *it; } return out << "}"; }
template<class T> ostream& operator << (ostream& out, multiset<T>& s) { out << "{"; for (auto it = s.begin (); it != s.end (); ++it) { if (it != s.begin ())out << ", "; out << *it; } return out << "}"; }
template<class L, class R> ostream& operator << (ostream& out, map<L, R>& m) { out << "{"; for (auto it = m.begin (); it != m.end (); ++it) { if (it != m.begin ())out << ", "; out << *it; } return out << "}"; }


mt19937 mt_rand(chrono::high_resolution_clock::now().time_since_epoch().count());

const int mod = 1e9 + 7;
const int N = 5e5 + 6;

void Solve()
{

    for (int i = 1 ; i <= 1000 ; i++)
    {
        int n = 10;

        set<ll>v;

        ll mn = 1e18;
        for (int i = 1 ; i <= n ; i++)
        {
            ll x = mt_rand() % 100;
            if (x % 2 == 0 && x)
                v.insert(x), mn = min(mn, x);
        }


        if (v.size() < 1)
            continue;

        for (auto i : v)
            cout << i << " ";

        cout << " => ";


        for (ll i = 1 ;  ; i++)
        {
            set<ll>st;
            for (auto j : v)
                st.insert(j % i);

            if (st.size() == 2)
            {

                cout << i << endl;
                break;
            }
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

    //cin >> tt;

    while (tt--)
    {

        //cout<<"Case "<<testcae++<<": ";

        Solve();
    }

    return 0;

}
