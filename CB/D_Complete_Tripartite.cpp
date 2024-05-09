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
const int N = 5e5 + 6;




int a[1005][1005];


// int Parent[N], Rank[N];

// void Init(int n)
// {
//  for (int i = 1 ; i <= n ; i++)
//    Rank[i] = 1, Parent[i] = i;
// }

// int Find_Parent(int v)
// {
//  if (v == Parent[v])
//    return v;

//  return Parent[v] = Find_Parent(Parent[v]);
// }

// void Union(int a, int b)
// {
//  a = Find_Parent(a);
//  b = Find_Parent(b);

//  if (a != b)
//  {

//    if (Rank[a] > Rank[b])
//      swap (a, b);

//    Parent[a] = b;
//    Rank[b] += Rank[a];
//  }
// }

void Solve()
{


  

  // for (int i = 1 ; i <= n ; i++)
  // {
  //  for (int j = 1 ; j <= n ; j++)
  //  {
  //    if (a[i][i])
  //    {
  //      cout << "NO" << endl;
  //      return ;
  //    }

  //    if (a[i][j] != a[j][i])
  //    {
  //      cout << "NO" << endl;
  //      return ;
  //    }

  //    if (i != j)
  //    {
  //      v.push_back({i, j, a[i][j]});
  //    }
  //  }
  // }



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