/*
* @Author: Zakaria
* @Date:   2023-03-05 17:41:28
* @Last Modified time: 2023-03-05 21:37:45
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

const int mod = 998244353;
const int N = 2e5 + 6;

int n;
int a[N];
bool primes[N];
ll fact[N];
ll ifact[N];
ll dp[5025][5025];
vector<pair<int , int> > v;
map<ll, ll>freq;

ll Bigmod(ll a, ll b, ll n)
{
	ll res = 1;
	if (b == 0)
		return 1;
	a = a % n;
	if (a == 0)
		return 0;
	while (b > 0)
	{

		if (b % 2)
			res = (res * a) % n;
		b = b / 2;
		a = (a * a) % n;
	}
	return res;
}

bool is_prime(ll x)
{
	if (x == 1)
		return 0;

	for (int i = 2 ; i * i <= x ; i++)
	{
		if (x % i == 0)
			return 0;
	}

	return 1;

}

void foo()
{
	fact[0] = 1;

	fact[1] = 1;
	for (int i = 2 ; i < N ; i++)
		fact[i] = (fact[i - 1] * i) % mod;

	for (int i = 0 ; i < N ; i++)
		ifact[i] = Bigmod(fact[i], mod - 2, mod);


}

ll foo(int index, int taken)
{

	if (taken > v.size())
		return 0;
	if (index == v.size())
	{
		if (taken == n)
			return fact[n];
		else
			return 0;
	}



	ll &R = dp[index][taken];

	if (R != -1)
		return R;

	if (primes[index])
	{
		ll pans = (foo(index + 1, taken + v[index].s - 1) *  ifact[v[index].s - 1]) % mod; // p^(e-1)

		ll lans = (foo(index + 1, taken + v[index].s) * ifact[v[index].s]) % mod;

		return R = (pans + lans) % mod;
	}
	else
	{
		return R = (foo(index + 1, taken + v[index].s) * ifact[v[index].s]) % mod;
	}

}


void Solve()
{

	foo();

	cin >> n;

	for (int i = 0 ; i < n + n ; i++)
	{
		cin >> a[i];
		freq[a[i]]++;
	}

	for (auto i : freq)
		v.push_back({i.f, i.s});

	for (int i = 0 ; i < v.size() ; i++)
		if (is_prime(v[i].f))
			primes[i] = 1;




	memset(dp, -1, sizeof(dp));

	cout << foo(0, 0) << endl;



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