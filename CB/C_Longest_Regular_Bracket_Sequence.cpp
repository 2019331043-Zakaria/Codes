/*
* @Author: Zakaria 
* @Date:   2022-11-26 14:42:54
* @Last Modified time: 2022-11-26 15:08:00
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
        
        string s;
        cin>>s;

        int n = s.size();

        s='*'+s;
        int close = 0 , open = 0;
        int done = 0;
        
        vector<pair<int, int> > v;
        map<int, int>m;
        
        map<int, int>check;
        for(int i=1 ; i<=n+1 ; i++)
        	check[i] = i-1;

        stack<int>q;


        for(int i=n ; i>=1 ; i--)
        {
             if(s[i]==')')
             q.push(i);
             else
             {
             	
             	if(q.size())
             	{
             		
             		check[i] = check[q.top()+1];
             		v.push_back({i, check[i]});
             		q.pop();
             	}

             }
        }

        

        int ans = 0;
        m[0]=1;
        for(auto i:v)
        {
        	ans = max(ans, i.s - i.f + 1);
            m[i.s - i.f + 1]++;
        }

        cout<<ans<<" "<<m[ans]<<endl;

      
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;
        
     //   cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 