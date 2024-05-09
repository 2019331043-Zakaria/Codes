/*
* @Author: Zakaria
* @Date:   2023-03-27 03:06:23
* @Last Modified time: 2023-03-27 03:13:12
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
      
      

      int n;
      cin>>n;

      int low = 0, high = v.size()-1;
      int ans = -1;

      while(low<=high)
      {
      	  int mid = (low+high)/2;

      	  if(v[mid]<=n)
      	  {
      	  	 ans = mid;
      	  	 low = mid + 1;
      	  }
      	  else
      	  	high = mid - 1;
      }

      cout<<ans+1<<endl;

}

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(0);

	
	for (int i = 1 ; i <= 9 ; i++)
	{
		ll temp = 0;

		for (int k = 1 ; k <= 10 ; k++)
		{
			temp *= 10LL;
			temp += i;

			v.push_back(temp);
		}
	}

	sort(v.begin(), v.end());

	int tt = 1;

	cin >> tt;

	while (tt--)
	{

		Solve();
	}

	return 0;

}