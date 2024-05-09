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


    int n = 18, m = 42;

    for (int i = 1 ; i <= N ; i++)
    {
        if ((i + n) % m == 0 && (i + m) % n == 0)
        {
            cout << i << endl;
        }
    }
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt = 1;

    //  cin>>tt;

    while (tt--)
    {

        Solve();
    }

    return 0;

}