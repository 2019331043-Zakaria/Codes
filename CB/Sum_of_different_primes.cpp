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

#define sz 10000010
bool siv[sz];
vector<long long >primes;

void seive()
{
    long long  limit = sqrt(sz+1);

    for (long long  i=3; i<=limit; i+=2)
        if(!siv[i])
            for (long  j = i*i; j<sz; j+=i+i)
                siv[j] = 1;
    primes.push_back(2);
    for (long long i=3; i<sz; i+=2)
        if(!siv[i]) primes.push_back(i);
}


int n, k;
vector<int>fact;

int dp[300][1200][20];

int foo(int index, int cursum, int taken)
{
    
    if(cursum==0 && taken==0)
        return 1;

    if(index>=fact.size() || cursum<0 || taken<0)
        return 0;

    int &R = dp[index][cursum][taken];

    if(R!=-1)
        return R;

    return R = foo(index+1, cursum, taken) + foo(index+1, cursum - fact[index], taken-1);
}

void Solve()
{
    seive();
    while (1)
    {
        cin>>n>>k;

        if (n == 0 && k == 0)
            return ;

        memset(dp, -1, sizeof(dp));
        fact.clear();
        int index = 0;
        while(primes[index]<=n)
            fact.push_back(primes[index++]);

        // for(auto i:fact)
        //     cout<<i<<" ";
        // cout<<endl;

        memset(dp, -1, sizeof(dp));

        cout<<foo(0, n, k)<<endl;
    }
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt = 1;

    // cin>>tt;

    while (tt--)
    {

        Solve();
    }

    return 0;

}