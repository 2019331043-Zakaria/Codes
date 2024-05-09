/*
* @Author: Zakaria
* @Date:   2023-04-11 23:12:03
* @Last Modified time: 2023-04-11 23:34:09
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

string s;
ll dp[12][15][2][2]; //pos, numberofzero, ok, othersnumber age paisi


ll foo(int pos, int zero, bool ok, bool others)
{
    
    if(pos==s.size())
    {
    	return zero;
    }

	ll &R = dp[pos][zero][ok][others];

	if(R!=-1)
		return R;

	ll res = 0;

	int maxdigit = 9;

	if(!ok)
		maxdigit = s[pos] - '0';

	for(int i=0 ; i<=maxdigit ; i++)
	{
		
		if(i<maxdigit || ok)
			res+=foo(pos+1, (i==0 && others) + zero, true, others|i);
		else
			res+=foo(pos+1, (i==0 && others) + zero, false, others|i);
	}

	return R = res;
}

void Solve()
{

	ll l, r;
	cin>>l>>r;

	ll ans = 0;

	s = to_string(r);
	memset(dp, -1, sizeof(dp));
	ans+=foo(0, 0, 0, 0);

	s = to_string(l);
	memset(dp, -1, sizeof(dp));
	ans-=foo(0, 0, 0, 0);

	for(auto i:s)
		ans+=(i=='0');

	cout<<ans<<endl;

}

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt = 1;

	cin >> tt;

	int cs = 1;

	while (tt--)
	{
		cout<<"Case "<<cs++<<": ";
		Solve();
	}

	return 0;

}