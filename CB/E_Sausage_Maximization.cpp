/*
* @Author: Zakaria 
* @Date:   2022-11-14 09:20:06
* @Last Modified time: 2022-11-15 18:18:17
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
const int N = 1e5+4;;

int Trie[41*N][2];
int root = 1;
int cnt[41*N];
int cur = 1;
ll a[N];
ll cum[N];

void Update(ll x, ll value)
{

		int start = root;
		cnt[start] += value;

		for(int i = 40 ; i>=0 ; i--)
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
    
		for(int i = 40 ; i>=0 ; i--)
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
    
		for(int i = 40 ; i>=0 ; i--)
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

        Update(0, 1);   

        ll ans = 0;     

        for(int i = 1; i<=n ; i++)
        {
        	cin>>a[i];
        	
        	cum[i] = a[i]^cum[i-1];
            ans = max(ans, cum[i]);
        	Update(cum[i], 1);
        }
        
        ll tempXor = 0;

        for(int i = n ; i>=1 ; i--)
        {
             Update(cum[i], -1);
             tempXor^=a[i];
             ans = max(ans, tempXor);
             ans = max(ans, MaxQuery(tempXor));
        }

        cout<<ans<<endl;

        

        
      
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;
        
        //cin>>tt;

        int test = 0;
        
        while(tt--)
        {
           // cout<<"Case "<<++test<<": ";
            Solve();
        }
 
        return 0;
        
} 