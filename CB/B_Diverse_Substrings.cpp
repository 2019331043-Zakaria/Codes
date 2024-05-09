/*
* @Author: Zakaria 
* @Date:   2022-11-12 20:37:28
* @Last Modified time: 2022-11-12 21:15:19
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
const int N = 2e5+6;

int cnt[N][11];
int n;
string s;



void Solve()
{
        
        
        cin>>n;
        cin>>s;

        s='*'+s;



        for(int i=0 ; i<=n ; i++)
        {
        	for(int j=0 ; j<=9 ; j++)
        		cnt[i][j] = 0;
        }

        for(int i=1 ; i<=n ; i++)
        {
        	for(int j=0 ; j<=9 ; j++)
        		cnt[i][j] = cnt[i-1][j];

        	cnt[i][s[i]-'0']++;

        }

        ll ans = 0;



        for(int i=1 ; i<=n ; i++)
        {
        	for(int j=0 ; j<=100 ; j++)
        	{
        		if(i+j>n)
        			break;
        		int pans = i+j;
        		int dist = 0;
        		int mxcnt = 0;

        		for(int digit = 0 ; digit<=9 ; digit++)
        		{
        			mxcnt = max(mxcnt, cnt[pans][digit] - cnt[i-1][digit]);

        			if(cnt[pans][digit] - cnt[i-1][digit]>0)
        				dist++;
        		}

        		if(mxcnt<=dist)
        			ans++;


        	}
        }

        cout<<ans<<endl;

      
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;
        
        cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 