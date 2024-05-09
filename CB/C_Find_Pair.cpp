/*
* @Author: Zakaria
* @Date:   2023-04-14 14:01:06
* @Last Modified time: 2023-04-14 15:38:30
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

	ll n, k;
	cin >> n >> k;

	ll a[n + 1];

	for (int i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
	}

	sort(a + 1, a + n + 1);

	vector<int>v;
	int cnt = 1;
	for (int i = 2 ; i <= n ; i++)
	{
		if (a[i] == a[i - 1])
			cnt++;
		else
		{
			v.push_back(cnt);
			cnt = 1;
		}
	}

	v.push_back(cnt);

	// for(auto i:v)
	// 	cout<<i<<" ";
	// cout<<endl;

	int index = 0;

	for (auto i : v)
	{
		index++;
		int lastindex = index + i - 1;

		ll freq = i;

		int firstindex = lastindex - freq + 1;
		//cout<<firstindex<<" "<<lastindex<<endl;
		//cout<<k<<endl;

		ll len ;

		// before
		len = firstindex - 1;

		int low = 1, high = firstindex - 1;
		int target = firstindex;

		while (low <= high)
		{
			int mid = (low + high) / 2;

			if (k <= mid * freq)
			{
				target = mid;
				high = mid - 1;
			}
			else
				low = mid + 1;
		}

		if (target < firstindex)
		{
			cout << a[firstindex] << " " << a[target] << endl;
			return ;
		}

		k -= (freq * len);

		// middle
		len = lastindex - firstindex + 1;

		for (int j = firstindex ; j <= lastindex ; j++)
		{
			if (k <= len)
			{
				cout << a[j] << " " << a[j] << endl;
				return ;
			}
			k -= len;
		}


		//after
		len = n - lastindex;

		/*cout<<k<<endl;
		cout<<len<<endl;
		*/
		low = lastindex + 1, high = n;
		target = n + 1;

		while (low <= high)
		{
			int mid = (low + high) / 2;

			int temp =  mid - lastindex;

			if (k <= freq * temp)
			{
				target = mid;
				high = mid - 1;
			}
			else
				low = mid + 1;
		}


		if (target <= n)
		{

			cout << a[lastindex] << " " << a[target] << endl;
			return ;
		}

		k -= (freq * len);

		index = lastindex;


	}
}

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt = 1;

	//    cin>>tt;

	while (tt--)
	{

		Solve();
	}

	return 0;

}