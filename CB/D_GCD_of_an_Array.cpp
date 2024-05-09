/*
* @Author: Zakaria
* @Date:   2023-02-22 20:20:20
* @Last Modified time: 2023-02-23 01:03:03
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

const int mod = 1e9 + 7;
const int N = 2e5 + 6;


#define sz 200010
bool siv[sz];
vector< int >primes;
int lps[sz];

void seive()
{
	long long  limit = sqrt(sz + 1);

	for (int  i = 3; i <= limit; i += 2)
		if (!siv[i])
			for (int  j = i * i; j < sz; j += i + i)
				siv[j] = 1;
	primes.push_back(2);
	for (int i = 3; i < sz; i += 2)
		if (!siv[i]) primes.push_back(i);


	for (int i = 1 ; i < sz ; i++)
		lps[i] = i;

	for (int i = 2 ; i < sz ; i += 2)
		lps[i] = 2;

	for (int  i = 3; i <= limit; i += 2)
		if (!siv[i])
			for (int  j = i * i; j < sz; j += i + i)
				siv[j] = 1, lps[j] = min(lps[j], i);
}

int freq[sz];

map<pair<ll, ll> , ll> kotobar;

map<ll,  multiset<ll> > st;

int sofar[sz];

vector<ll>factorization(int x)
{
	vector<ll>temp;

	while (x > 1)
	{
		temp.push_back(lps[x]);
		x /= lps[x];
	}

	return temp;

}


ll bigmod(ll a, ll b, ll n)
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


void Solve()
{

	seive();

	ll n, q;
	cin >> n >> q;
	ll a[n + 1];

	ll ans = 1;

	set<int>all;

	for (int i = 1 ; i <= n ; i++)
	{
		cin >> a[i];

		vector<ll>factor = factorization(a[i]);

		set<ll>distinct;

		for (auto i : factor)
			distinct.insert(i), all.insert(i);

		for (auto i : factor)
			freq[i]++;

		for (auto k : distinct)
			kotobar[ {i, k}] = freq[k];

		for (auto k : distinct)
			st[k].insert(kotobar[ {i, k}]);

		for (auto i : factor)
			freq[i] = 0;

	}


	for(auto i:all)
	{
		if(st[i].size()==n)
			sofar[i] = *st[i].begin(), ans*=bigmod(i, *st[i].begin(), mod), ans%=mod;
	}

	

	while (q--)
	{
		
		ll index, x;
		cin >> index >> x;
		
		vector<ll>factor = factorization(x);

		for (auto i : factor)
			freq[i]++;

		set<ll>distinct;

		for (auto i : factor)
			distinct.insert(i);

		for (auto k : distinct)
		{
			auto it = st[k].find(kotobar[ {index, k}]);

			if (it != st[k].end())
				st[k].erase(it);

			kotobar[ {index, k}] += freq[k];
			st[k].insert({kotobar[{index, k}]});
			if (st[k].size() == n)
			{
				int p = *st[k].begin();
				if(p>sofar[k])
				{
					ans *= bigmod(k, p - sofar[k] , mod), sofar[k] = p;
				}
				ans %= mod;
			}
		}

		
		for (auto i : factor)
			freq[i] = 0;

		cout<<ans<<endl;
	}


}

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt = 1;

	//   cin>>tt;

	while (tt--)
	{

		Solve();
	}

	return 0;

}