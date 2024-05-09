/*
* @Author: Zakaria
* @Date:   2023-02-01 21:51:29
* @Last Modified time: 2023-02-01 23:36:01
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

string s, t;
int n, k;

ll foo(string temp)
{
	 int vis[30];
	 memset(vis, 0, sizeof(vis));

	 for(auto i:temp)
	 	vis[i-'a'] = 1;
     
     string pans = s;

     for(int i=0 ; i<n ; i++)
     {
     	 if(vis[pans[i]])
     	 pans[i] = t[i];
     }

     cout<<pans<<endl;
     cout<<t<<endl;


	 ll ans = 0 ;
	 ll cnt = 0;

	

	 return ans;
}
void Solve()
{


	cin >> n >> k;

	cin >> s >> t;

	

	set<char>st;

	for (auto i : s)
		st.insert(i);

	vector<char>v;
	for (auto i : st)
		v.push_back(i);

	

	ll ans = 0;

	for (int i = 0; i < (1 <<  v.size()); i++)
	{
		string temp="";

		for (int j = 0; j < v.size(); j++)
			if (i & (1 << j))
				temp += v[j];
		if(temp.size()>k)
			continue;
		
		cout<<temp<<" =>"<<endl;
		
		ans = max(ans, foo(temp));
	}

	cout<<ans<<endl;
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