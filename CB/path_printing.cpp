/*
* @Author: Zakaria 
* @Date:   2023-07-24 20:07:55
* @Last Modified time: 2023-07-24 20:10:15
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



const int mod = 1e9 + 7;
const int N = 2005;

int dp[N][N][2];
int n;
string s;

bool foo(int index, int cur, int p)
{
    if (index == n)
        return cur == 0;

    int &R = dp[index][cur][p];

    if (R != -1)
        return R;

    if (index)
    {
        if (s[index] == s[index - 1])
        {
            if (p)
                cur++;
            else
                cur--;

            R = foo(index + 1, cur, p);
        }
        else
        {
            R = foo(index + 1, cur + 1, 1) | foo(index + 1, cur - 1, 0);
        }
    }
    else
    {
        R = foo(index + 1, cur + 1, 1) | foo(index + 1, cur - 1, 0);
    }

    return R;


}

void path(int index, int cur, int p)
{
    if (index == n)
        return;

    int R = 0;

    if (index)
    {
        if (s[index] == s[index - 1])
        {
            if (p)
                cur++;
            else
                cur--;

            R = foo(index + 1, cur, p);

            if(R == 1) {
                cout << (p ? '(' : ')');
                path(index + 1, cur, p);           
            }

            return ;
        }
        else
        {
            R = foo(index + 1, cur + 1, 1);

            if(R == 1) {
                cout << '(';
                path(index+1, cur+1, 1);
                return;
            }

            R = foo(index + 1, cur - 1, 0);
            if(R == 1) {
                cout << ')';
                path(index+1, cur-1, 0);
            }

            return;
        }
    }
    else
    {
        R = foo(index + 1, cur + 1, 1);

        if(R == 1) {
            cout << '(';
            path(index+1, cur+1, 1);
            return;
        }

        R = foo(index + 1, cur - 1, 0);
        if(R == 1) {
            cout << ')';
            path(index+1, cur-1, 0);
        }
    }

    return;
}

void Solve()
{

    cin >> n >> s;

    memset(dp, -1, sizeof(dp));

    if (foo(0, 0, 0))
    {
        cout << "YES" << endl;
        path(0, 0, 0);
        cout << endl;
    }
    else
        cout << "NO" << endl;

}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt = 1;

    cin >> tt;

    while (tt--)
    {

        Solve();
    }

    return 0;

}

//https://www.codechef.com/problems/LASTRBS?tab=statement