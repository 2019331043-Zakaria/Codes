/*
* @Author: Zakaria 
* @Date:   2022-11-14 09:20:06
* @Last Modified time: 2023-08-31 20:10:25
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

const int mod = 1e9+7;
const int N = 5e4+4;;

int Trie[35*N][2];
int root = 1;
int cnt[35*N];
int cur = 1;

void Update(ll x, ll value)
{

		int start = root;
		cnt[start] += value;

		for(int i = 32 ; i>=0 ; i--)
		{
			bool bit = x & (1LL<<i);

			if(Trie[start][bit] == 0)
			{
				Trie[start][bit] = ++cur;
			}

			start = Trie[start][bit];
			cnt[start] += value;
		}
}

ll MaxQuery(ll x)
{

		int start = root;

		ll ans = 0;
    
		for(int i = 32 ; i>=0 ; i--)
		{

			bool bit = x & (1LL<<i);
			
			if(Trie[start][1^bit] == 0 || cnt[Trie[start][1^bit]] == 0)
			{
			 
			   ans = ans;
			}
			else
			{
				   
				   ans += (1LL<<i);
				   bit ^= 1;
			}

			start = Trie[start][bit];
		}

		return ans;     

}
ll MinQuery(ll x)
{

		int start = root;

		ll ans = 0;
    
		for(int i = 32 ; i>=0 ; i--)
		{

			bool bit = x & (1LL<<i);
			
			if(Trie[start][bit])
			{
			 
			   ans = ans;
			}
			else
			{
				   
				   ans += (1LL<<i);
				   bit ^= 1;
			}

			start = Trie[start][bit];
		}

		return ans;     

}
void Solve()
{
        
        int n;
        cin>>n;

        ll a[n];
        ll cum[n];
        ll Presum = 0;
        for(int i=0 ; i<n ; i++)
        	cin>>a[i], Presum^=a[i], cum[i] = Presum;

        memset(Trie, 0, sizeof(Trie));
        memset(cnt, 0, sizeof(cnt));
        cur = 1;

        ll MaxAns = 0;
        
        Update(0, 1);

        for(auto i : cum)
        {
            MaxAns = max(MaxAns, MaxQuery(i));
            Update(i, 1);
        }

        memset(Trie, 0, sizeof(Trie));
        memset(cnt, 0, sizeof(cnt));
        cur = 1;

        ll MinAns = LLONG_MAX;

        Update(0, 1);

        for(auto i : cum)
        {
        	MinAns = min(MinAns, MinQuery(i));
        	Update(i, 1);
        }
        cout<<MaxAns<<" "<<MinAns<<endl;
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;
        
        cin>>tt;

        int test = 0;
        
        while(tt--)
        {
            cout<<"Case "<<++test<<": ";
            Solve();
        }
 
        return 0;
        
} 