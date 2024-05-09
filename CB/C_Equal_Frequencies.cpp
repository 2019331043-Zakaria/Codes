/*
* @Author: Zakaria
* @Date:   2023-01-15 19:11:52
* @Last Modified time: 2023-01-15 22:22:01
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

	int n;
	cin >> n;

	string s;
	cin >> s;


	int temp = min(n, 26);

	vector<pair<int, string> > v;


	for (int i = 3 ; i >= 3 ; i--)
	{
		if (n % i == 0 && i<=n)
		{

			map<char, int>charcount;

			map<char, vector<int> > position;

			for (int i = 0 ; i < n ; i++)
			{
				position[s[i]].push_back(i);
			}

			for (auto i : s)
				charcount[i]++;

		
			string result = s;

			int used  = i;
			int freq = n / i;
			int done= 0;


//---------------------------------------------------------


			//cout << used << " " << freq << endl;

			int tot = 0;

			vector<pair<int, char> > pans;
			vector<char>nai;

			for (char c = 'a' ; c <= 'z' ; c++)
			{
				pans.push_back({charcount[c], c});
			}
			
			vector<int>out;

			for (auto k : pans)
			{
				if (k.f > freq)
				{

					while (position[k.s].size() > freq)
					{
						out.push_back(position[k.s].back());
						position[k.s].pop_back();
					}
				}
				
			}



			pans.clear();

			for(char c = 'a' ; c<='z' ; c++)
			{
				if(position[c].size()<freq )
					pans.push_back({position[c].size(), c});
				else
					done++;
			}

		
			sort(pans.rbegin(), pans.rend());

			for(auto i:pans)
			{
				while(position[i.s].size()<freq && out.size())
				{
					position[i.s].push_back(out.back());
					out.pop_back();
				}
			}

			
			pans.clear();

			int bal = 0;

//   all<freq


			for(char c = 'a' ; c<='z' ; c++)
			{
				if(position[c].size()<freq)
				{
					pans.push_back({position[c].size(), c});
					if(position[c].size())
						bal++;
				}
				else
					done++;
			}

			if(done!=used)
			{
				int baki = used - done;
				vector<int>offset;

				sort(pans.rbegin(), pans.rend());

				
			}

			

			for (char c = 'a' ; c <= 'z' ; c++)
			{
				for (auto k : position[c])
					result[k] = c;
			}

			int ans = 0;

			

			for (int i = 0 ; i < n ; i++)
			{
				if (s[i] != result[i])
					ans++;
			}

			v.push_back({ans, result});

		}
	}

	sort(v.begin(), v.end());

	cout<<v[0].f<<endl<<v[0].s<<endl;

	/*for (auto i : v)
		cout << i.f << " " << i.s << endl;*/
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