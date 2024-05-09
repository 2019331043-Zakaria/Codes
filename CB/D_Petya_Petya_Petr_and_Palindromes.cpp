/*
* @Author: Zakaria
* @Date:   2023-04-03 22:31:15
* @Last Modified time: 2023-04-04 01:53:13
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

vector<int>all[N][2];

void Solve()
{

	int n, k;
	cin >> n >> k;

	int a[n + 1];

	for (int i = 1 ; i <= n ; i++)
		cin >> a[i];

	for (int i = 1 ; i <= n ; i++)
	{
		all[a[i]][i%2].push_back(i);
	}

	// cout<<"for "<<1<<endl;
	// for (auto i : all[1])
	// 	cout << i << " ";
	// cout << endl;

	// cout<<"for "<<2<<endl;
	// for(auto i:all[2])
	// 	cout<<i<<" ";
	// cout<<endl;


	ll ans = 0;

	int l = 1, r = k;

	while (r <= n)
	{

		//	cout << l << " " << r << endl;

		int kotdur = r;

		int low = 0, high = l - 1;

		while (low <= high)
		{
			int mid = (low + high) / 2;

			if (r - 2 * mid >= l)
			{
				low = mid + 1;
				kotdur = r - 2 * mid;
			}
			else
			{
				high = mid - 1;
			}
		}



	//	cout << l << " => " << kotdur << " " << r << endl;

		
		int low1 = lower_bound(all[a[l]][r%2].begin() , all[a[l]][r%2].end() , kotdur) - all[a[l]][r%2].begin();
		int low2 = upper_bound(all[a[l]][r%2].begin() , all[a[l]][r%2].end() , r) - all[a[l]][r%2].begin();


		int ache = low2 - low1;

		int tot = (r - kotdur) / 2 + 1;

		//	cout << tot - ache << endl;

		ans += tot - ache;

		l++;
		r++;
	}

	//cout<<ans<<endl;

	r = n - 1;

	while (l <= r)
	{

        
		int kotdur = r;

	//	cout<<"for "<<l<<endl;

		int low = 0 , high = min((k-1) / 2, min(l - 1, n - l));
		
		int init = high;
	//	cout<<low<<" "<<high<<endl;

		int canbe = k+1;
		
		while (low <= high)
		{
			int mid = (low + high) / 2;
			int ache = n - l;
			int thakalagbe = k - (mid + 1);
			if(ache>=thakalagbe)
			{
				canbe = mid;
				canbe = mid;
				high = mid - 1;
			}
			else
			{
				low = mid + 1;
			}
		}

		
	//	cout<<canbe<<endl;

        kotdur = r - ((init) - canbe)*2;
        
    //    cout << l << " => " << kotdur << " " << r << endl;

		
		int low1 = lower_bound(all[a[l]][r%2].begin() , all[a[l]][r%2].end() , kotdur) - all[a[l]][r%2].begin();
		int low2 = upper_bound(all[a[l]][r%2].begin() , all[a[l]][r%2].end() , r) - all[a[l]][r%2].begin();

		// for(auto i:v)
		// 	cout<<i<<" ";
		// cout<<endl;


		
		int ache = low2 - low1;

		int tot = (r - kotdur) / 2 + 1;

		//	cout << tot - ache << endl;

		ans += tot - ache;


		l++, r--;
	}

	cout << ans << endl;


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