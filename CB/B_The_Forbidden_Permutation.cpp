/*
* @Author: Zakaria 
* @Date:   2023-02-01 20:39:49
* @Last Modified time: 2023-02-01 21:49:26
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

void Solve()
{
        

        int n, m, d;
        cin>>n>>m>>d;

        int a[n+1];
        map<int, int> bos;
        for(int i=1 ; i<=n ; i++)
        	cin>>a[i], bos[a[i]] = i;

        vector<int>v;

        int pos[m+1];

        for(int i=1 ; i<=m ; i++)
        	cin>>pos[i], v.push_back(bos[pos[i]]);

        for(int i=0 ; i<m-1 ; i++)
        {
        	if(v[i+1]>v[i] && v[i+1]<=v[i]+d)
        		continue;
        	cout<<0<<endl;
        	return ;
        }

        /*for(auto i:v)
        	cout<<i<<" ";
        cout<<endl;
*/
        int ans = n;

        for(int i=0 ; i<m-1 ; i++)
        {
        	ans = min(ans, v[i+1] - v[i]);

        	int left = v[i+1] - d - 1;

        	if(left>=1)
        	{
        		ans = min(ans, v[i] - left);
        	}

        	int right = v[i] + d + 1;

        	if(right<=n)
        	{
        		ans = min(ans, right - v[i+1]);
        	}

        	int diff = v[i+1] - v[i];

        	int lage = d + 1 - diff;
        	int toleft = v[i] - 1;
        	int toright = n - v[i+1];

        	int mn = min(toleft, toright);

        	int off = lage/2;

        	int result = 0;

        	lage-=2*min(mn, off);
        	result+=2*min(mn, off);

        	toleft-=min(mn, off);
        	toright-=min(mn, off);

        	if(lage<=0)
        	{
        		ans = min(ans, result);
        	}

        	if(toleft+toright>=lage)
        	{
        		ans = min(ans, result + lage);
        	}

        }

        cout<<ans<<endl;

     //   cout<<ans<<endl;


      
      
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