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
const int N = 1e5 + 6;

int a[N];

//Range update bit template from Youkn0who
struct BIT {
        long long M[N], A[N];
        BIT() {
                memset(M, 0, sizeof M);
                memset(A, 0, sizeof A);
        }
        void update(int i, long long mul, long long add)
        {
                while (i < N)
                {
                        M[i] += mul;
                        A[i] += add;
                        i |= (i + 1);
                }
        }
        void upd(int l, int r, long long x)
        {
                update(l, x, -x * (l - 1));
                update(r, -x, x * r);
        }
        long long query(int i)
        {
                long long mul = 0, add = 0;
                int st = i;
                while (i >= 0)
                {
                        mul += M[i];
                        add += A[i];
                        i = (i & (i + 1)) - 1;
                }
                return (mul * st + add);
        }
        long long query(int l, int r)
        {
                return query(r) - query(l - 1);
        }
} t[7];

void Solve()
{

        int n;
        cin >> n;
        

        for (int i = 1 ; i <= n ; i++)
        {

                cin >> a[i];
                t[2].upd(i, i, 0);
                t[3].upd(i, i, 0);
                t[5].upd(i, i, 0);
        }

        int q;
        cin >> q;

        while (q--)
        {
                int type;
                cin >> type;

                if (type == 1)
                {
                        int l, r, p;
                        cin >> l >> r >> p;
                        t[p].upd(l, r, 1);
                }
                else
                {
                        int x, p;
                        cin >> x >> p;
                        a[x] = p;
                        int temp = t[2].query(x, x);
                        t[2].upd(x, x, -temp);

                        temp = t[3].query(x, x);
                        t[3].upd(x, x, -temp);

                        temp = t[5].query(x, x);
                        t[5].upd(x, x, -temp);
                }
        }

        for (int i = 1 ; i <= n ; i++)
        {
                int p = 2;
                int temp = t[p].query(i, i);
                while (a[i] % p == 0 && temp--)
                        a[i] /= p;
                p = 3;
                temp = t[p].query(i, i);
                while (a[i] % p == 0 && temp--)
                        a[i] /= p;

                p = 5;
                temp = t[p].query(i, i);
                while (a[i] % p == 0 && temp--)
                        a[i] /= p;

                cout<<a[i]<<" ";
        }

}

int main()
{

        ios::sync_with_stdio(false);
        cin.tie(0);

        int tt = 1;

        //cin >> tt;

        while (tt--)
        {

                Solve();
        }

        return 0;

}

//https://www.codechef.com/problems/CHEFD 