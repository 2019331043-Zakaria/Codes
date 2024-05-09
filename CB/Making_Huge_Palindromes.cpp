/*
* @Author: Zakaria
* @Date:   2023-01-31 14:43:29
* @Last Modified time: 2023-01-31 15:12:33
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


ll Hash1[N], Pow1[N];
ll Hash2[N];

ll Base1 = 1231;
ll Mod1 = 1e9 + 7;

void PowerGenerate1(ll n)
{
	Pow1[0] = 1;
	for (int i = 1 ; i <= n ; i++)
	{
		Pow1[i] = (Pow1[i - 1] * Base1) % Mod1;
	}

}
void FrontHash(string text)
{
	Hash1[0] = 0;

	for (int i = 1 ; i <= text.size() ; i++) //1 base indexing for string
	{
		Hash1[i] = (Hash1[i - 1] * Base1 + (text[i - 1] - 'a' + 1) ) % Mod1;
		Hash1[i] += Mod1;
		Hash1[i] %= Mod1;
	}

}

void ReverseHash(string text)
{
	reverse(text.begin(), text.end());

	Hash2[0] = 0;

	for (int i = 1 ; i <= text.size() ; i++) //1 base indexing for string
	{
		Hash2[i] = (Hash2[i - 1] * Base1 + (text[i - 1] - 'a' + 1) ) % Mod1;
		Hash2[i] += Mod1;
		Hash2[i] %= Mod1;
	}
}

ll GetHash1(int Left , int Right)
{
	ll HashValue = Hash1[Right] - (Hash1[Left - 1] * Pow1[Right - Left + 1]) % Mod1 ; //Here pow is base^(right-lest+1)%mod
	HashValue += Mod1;
	HashValue %= Mod1;

	return HashValue;

}
ll GetHash2(int Left , int Right)
{
	ll HashValue = Hash2[Right] - (Hash2[Left - 1] * Pow1[Right - Left + 1]) % Mod1 ; //Here pow is base^(right-lest+1)%mod
	HashValue += Mod1;
	HashValue %= Mod1;

	return HashValue;

}



void Solve()
{

	string s;
	cin >> s;

	int n = s.size();

	PowerGenerate1(n);

	FrontHash(s);
	ReverseHash(s);
	
	
	for(int i=1 ; i<=n ; i++)
	{
		if(GetHash1(i, n) == GetHash2(1, n-i+1))
		{
			cout<<n+i-1<<endl;
			return ;
		}
	}
	

}

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt = 1;
	int t = 1;
    cin>>tt;

	while (tt--)
	{
        cout<<"Case "<<t++<<": ";
		Solve();
	}

	return 0;

}