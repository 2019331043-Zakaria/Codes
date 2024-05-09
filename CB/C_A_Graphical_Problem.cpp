/*
* @Author: Zakaria
* @Date:   2023-03-26 01:41:04
* @Last Modified time: 2023-03-26 02:21:25
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

void Solve()
{

	ll n;
	cin >> n;

	ll a[n+1];
	
	for(int i=1 ; i<=n ; i++)
		cin>>a[i];
	sort(a+1, a+n+1);


	ll tot = 0;
	ll cum[n+1];
	cum[0] = 0;
	for (int i = 1 ; i <=n ; i++)
	  cum[i] = a[i] + cum[i-1];
    
	ll mx = 0, mn = 1e18;
	ll temp = 0;
	
	for(int i=2 ; i<=n ; i++)
		temp+=a[i] - a[i-1];

	mn = min(mn, temp);
	
	mx+=a[n]-a[1];

	for(int i=2 ; i<n ; i++)
	  mx+=max(abs(a[i]-a[1]), abs(a[n]-a[i]));

	cout<<mn<<" "<<mx<<endl;
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