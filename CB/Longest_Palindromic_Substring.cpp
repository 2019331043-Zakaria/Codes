/*
* @Author: Zakaria
* @Date:   2023-01-14 11:59:02
* @Last Modified time: 2023-01-14 12:19:01
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

int n;
string s;
int dp[5000][5000];

int foo(int l, int r)
{


	if(l<0)
		return 0;
	if(r==n)
		return 0;

	if(l>r)
		return 0;

	if(l==r)
		return 1;

	int &R = dp[l][r];
   
    
	if(R!=-1)
		return R;

    R = 0;

	if(s[l]==s[r])
	{
		if(foo(l+1, r-1))
		R = max(R, 2 + foo(l+1, r-1));
	}
	
	R = max(R, foo(l+1, r));
	R = max(R, foo(l, r-1));

	return R;
}

void Solve()
{


	cin >> s;
    n = s.size();


	for (int i = 0 ; i <= n ; i++)
		for (int j = 0 ; j <= n ; j++)
			dp[i][j] = -1;


	cout<<foo(0, n-1)<<endl;



}

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt = 1;

	cin >> tt;

	while (tt--)
	{

		Solve();
	}

	return 0;

}