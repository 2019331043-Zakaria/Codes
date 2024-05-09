/*
* @Author: Zakaria
* @Date:   2023-01-14 15:02:35
* @Last Modified time: 2023-08-11 02:57:20
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

ll Next_smaller[N + 2];
ll Prev_smaller[N + 2];

void NEXTSMALLER()
{
	
	stack<int>st;
	for (int i = 1; i <= n; i++)
	{
		if (st.empty())
		{
			st.push(i);
		}
		else
		{
			while (!st.empty() && a[st.top()] > a[i])
			{
				Next_smaller[st.top()] = i;
				st.pop();
			}
			st.push(i);
		}
	}
	while (!st.empty())
	{
		Next_smaller[st.top()] = n + 1;
		st.pop();
	}
}

void PREVSMALLER()
{
	stack<int>st;
	for (int i = n; i >= 1; i--)
	{
		if (st.empty())
		{
			st.push(i);
		}
		else
		{
			while (!st.empty() && a[st.top()] > a[i])
			{
				Prev_smaller[st.top()] = i;
				st.pop();
			}
			st.push(i);
		}
	}
	while (!st.empty())
	{
		Prev_smaller[st.top()] = 0;
		st.pop();
	}
}
void Solve()
{


	




}

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt = 1;

	// cin>>tt;

	while (tt--)
	{

		Solve();
	}

	return 0;

}