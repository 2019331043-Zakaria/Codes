/*
* @Author: Zakaria
* @Date:   2023-02-27 22:04:05
* @Last Modified time: 2023-02-27 22:57:17
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

	string s;
	cin >> s;

	int n = s.size();

	// if (n <= 4)
	// {

	// 	sort(s.begin(), s.end());
		
	// 	string ans = "zzzzzzzzzzzz";

	// 	do {

	// 		string  t = s;
	// 		reverse(t.begin(), t.end());

	// 		// cout<<s<<endl;
	// 		// cout<<t<<endl;
	// 		// cout<<endl;

	// 		ans = min(ans, max(s, t));


	// 	} while (next_permutation(s.begin(), s.end()));

	// 	cout << ans << endl;

	// 	return ;
	// }

	
	map<char, int> freq;

	for (auto i : s)
		freq[i]++;

	string a = "", b = "";

	for (char i = 'a' ; i <= 'z' ; i++)
	{
		if (freq[i]% 2)
		{
			int temp = freq[i];

			temp/=2;

			while(temp--)
			{

				a+=i;
				b+=i;
			}
			a+=i;

			// cout<<a<<endl;
			// cout<<b<<endl;
			// cout<<"here "<<endl;
			int ok = 0;

			for(char k = i+1 ; k<='z' ; k++)
			{
				if(freq[k])
					ok++;
			}

			if(ok==1)
			{
				
				for(char k = i+1 ; k<='z' ; k++)
				{
					int temp = freq[k];
					if(temp==0)
						continue;

					for(int p=1 ; p<=(temp+1)/2 ; p++)
						b+=k;
					
					b+=a.back();
					a.pop_back();

					for(int p=1 ; p<=temp/2 ; p++)
						a+=k;
				}

				break;
			}
			for(char k = i+1 ; k<='z' ; k++)
			{

				//cout<<freq[k]<<endl;
			//	cout<<"bal "<<k<<endl;
				int temp = freq[k];
				while(temp--)
					b+=k;
			}

			break;
		}
		else
		{
			int temp = freq[i];

			temp/=2;

			while(temp--)
			{
				a+=i;
				b+=i;
			}
		}
	}

	cout<<b;
	reverse(a.begin(), a.end());
	cout<<a<<endl;

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