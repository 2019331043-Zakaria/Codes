/*
* @Author: Zakaria
* @Date:   2023-03-12 21:52:45
* @Last Modified time: 2023-03-12 22:35:21
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

vector<ll>v;


void Solve()
{
	ll n, x, p;
	cin >> n >> x >> p;

	ll temp = 0;

	if (x)
		temp = n - x;

	if(temp==0)
		temp = n;

	ll pans = n + temp;

	int cnt = 1;
	for(auto i:v)
	{
		if(cnt>p)
			break;

		if(i==temp || i%pans==0)
		{
			
			cout<<"YES"<<endl;
			return ;
		}
		cnt++;
	}

	cout<<"NO"<<endl;



}

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(0);

	for(ll i = 1; i<=10000 ; i++)
	{
		ll temp = i*(i+1);
		temp/=2;
		v.push_back(temp);
	}
	int tt = 1;

	cin >> tt;

	while (tt--)
	{

		Solve();
	}

	return 0;

}