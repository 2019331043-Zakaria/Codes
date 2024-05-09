/*
* @Author: Zakaria 
* @Date:   2022-11-14 09:20:06
* @Last Modified time: 2022-11-14 14:27:27
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
const int N = 5e5+4;;

int trie[30*N][2];
int root = 1;
int cnt[30*N];
int cur = 1;

void Update(int x, int value)
{

		int start = root;
		cnt[start] += value;

		for(int i = 29 ; i>=0 ; i--)
		{
			bool bit = x & (1LL<<i);

			if(trie[start][bit] == 0)
			{
				trie[start][bit] = ++cur;
			}

			start = trie[start][bit];
			cnt[start] += value;
		}
}

int Query(int x)
{

		int start = root;

		int ans = 0;
    
		for(int i = 29 ; i>=0 ; i--)
		{

			bool bit = x & (1LL<<i);
			
			if(trie[start][1^bit] == 0 || cnt[trie[start][1^bit]] == 0)
			{
			 
			   ans = ans;
			}
			else
			{
				   
				   ans += (1LL<<i);
				   bit ^= 1;
			}

			start = trie[start][bit];
		}

		return ans;     

}
void Solve()
{
        
        int n;
        cin>>n;

        Update(0, 1);

        while(n--)
        {
        	char c;
        	int x;
        	cin>>c>>x;

        	if(c=='+')
        		Update(x, 1);
        	else if(c=='-')
        		Update(x, -1);
        	else
        		cout<<Query(x)<<endl;

        }
      
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;
        
       // cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 