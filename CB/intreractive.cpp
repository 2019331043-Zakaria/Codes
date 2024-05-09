#include <bits/stdc++.h>
#define  pb          push_back
#define  f           first
#define  s           second
#define  pi          acos(-1.0)
#define  LCM(a,b)    a*b/__gcd(a,b)
#define  GCD(a,b)    __gcd(a,b)
#define  sof         sizeof

#define  eps         1e-6
typedef long long ll;
using namespace std;

mt19937 mt_rand(chrono::high_resolution_clock::now().time_since_epoch().count());


const int mod = 1e9 + 7;
const int N = 5e5 + 6;


int n;

int queryone(int p)
{

  cout << "? ";
  for (int i = 1 ; i <= p ; i++)
    cout << 1;
  for (int i = p + 1 ; i <= n ; i++)
    cout << 0;

  cout << endl;

  int x;
  cin >> x;

  return x;
}

int queryzero(int p)
{

  cout << "? ";
  for (int i = 1 ; i <= p ; i++)
    cout << 0;
  for (int i = p + 1 ; i <= n ; i++)
    cout << 1;

  cout << endl;

  int x;
  cin >> x;

  return x;
}


void Solve()
{

  cin >> n;

  int totone = queryone(0);
  int totzero = queryzero(0);
  int bruh = queryone(1);

  if (bruh < totone)
  {
    int low = 1, high = n - 1, mid;
    int ans = -1;
    while (low <= high)
    {
      mid = (low + high) / 2;

      int temp = queryone(mid);
      int diff = totone - temp;
      int curone = (diff + mid) / 2;

      if (curone != mid)
      {
        high = mid - 1;
      }
      else
      {
        ans = mid;
        low = mid + 1;
      }
    }

    cout << "! " << ans + 1 << " " << ans << endl;
  }
  else
  {

    int low = 1, high = n - 1, mid;
    int ans = -1;
    while (low <= high)
    {
      mid = (low + high) / 2;

      int temp = queryzero(mid);
      int diff = totzero - temp;
      int curzero = (diff + mid) / 2;

      if (curzero != mid)
      {
        high = mid - 1;
      }
      else
      {
        ans = mid;
        low = mid + 1;
      }
    }

    cout << "! " << ans << " " << ans + 1<< endl;
  }

}

int main()
{



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
