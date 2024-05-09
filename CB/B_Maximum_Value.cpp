/*
* @Author: Zakaria
* @Date:   2023-03-24 02:54:00
* @Last Modified time: 2023-03-24 14:03:04
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
const int N = 2e6 + 6;

int n;
int a[N];
int cum[N];

void Solve()
{

	cin >> n;
	set<int>st;

	for (int i = 0 ; i < n ; i++)
	{
		cin >> a[i];
		st.insert(a[i]);
	}

	vector<int>v;
	for(auto i:st)
		v.push_back(i), cum[i]++;

	for (int i = 1 ; i < N ; i++)
		cum[i] += cum[i - 1];


	
	int ans = 0;

	for (auto i:v)
	{
		
		for(int p = i ; p<=1000000 ; p+=i)
		{
			int low = 0, high = i - 1;
            
			while(low<=high)
			{
				int mid = (low+high)/2;

				if(cum[p+i-1] - cum[p+mid-1])
				{
					ans = max(ans, mid);
					low = mid + 1;
				}
				else
					high = mid - 1;
			}		
		}
	}

	cout<<ans<<endl;



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