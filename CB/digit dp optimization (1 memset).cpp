#include<bits/stdc++.h>
using namespace std ;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define endl '\n'
const double pi = 2 * acos (0.0) ;
const int N = 1000009 ;
const double eps = 1e-7 ;
#define ll long long
const int INF = INT_MAX ;
const int mod = 1000000007 ;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//cout <<fixed << setprecision(7)  <<res << endl;
template <typename T>
using order_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//order_set<int>od_s ;



ll dp[20][1030][2][2];
ll casio[20][1030][2][2];
int cur;
int v[20];

string s;
int n;

ll foo(int pos, int mask, int ok, bool other)
{
    // cout<<pos<<" "<<mask<<" "<<ok<<endl;
    if (pos == -1)
    {
        int tb = 0;
        int mxdig = -1;

        for (int i = 0 ; i <= 9 ; i++)
        {
            if (mask & (1 << i))
                tb++, mxdig = max(mxdig, i);
        }

        return tb == mxdig;
    }

    ll &R = dp[pos][mask][ok][other];

    if(casio[pos][mask][ok][other]==cur)
        return R;

    casio[pos][mask][ok][other] = cur;


    if(ok && ~R)
        return R;

    int dgt = 9;

    if (!ok)
    {
        dgt = v[pos];
    }

    R = 0;

    for (int i = 0 ; i <= dgt; i++)
    {

        int temp = mask;

        if (other)
            temp |= (1 << i);
        else
        {
            if (i)
            {
                other = 1;
                temp |= (1 << i);
            }
        }

        if (i < dgt || ok)
            R += foo(pos - 1, temp , true, other);
        else
            R += foo(pos - 1, temp , false, other);
    }

    return R;
}

void pro()
{


    ll x;
    cin >> x;

    for(int i=0 ; i<20 ; i++)
    {
        v[i] = x%10;
        x/=10;
    }

    cur++;

    ll ans = foo(18, 0, 0, 0);   
    cout << ans << endl;
}

int32_t main()
{

    ios_base :: sync_with_stdio(false) ; cin.tie(NULL) ; cout.tie(NULL) ;


    memset(dp, -1, sizeof(dp));

    int t ;
    cin >> t ;
    for (int tc = 1; tc <= t; tc++)
    {
        //cout << "Case " << tc << ": " ;

        pro() ;
    }

    return 0;
}


//https://toph.co/p/noora-number