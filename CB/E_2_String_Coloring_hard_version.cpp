/*
* @Author: Zakaria 
* @Date:   2022-09-16 09:37:33
* @Last Modified time: 2022-09-17 02:11:54
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
        
        int n;
        cin>>n;

        string s;
        cin>>s;

        int color = 0;
        
        map<char, vector<int> > mp;

        int ans[n];

        int cnt=0;
        for(int i=0;  i<n ; i++)
        {
        	bool ok=0;

              for(char c = s[i] ; c>='a' ; c--)
              {
              	  if(mp[c].size())
                  { 
                    ans[i]=mp[c].back();   
                   	mp[c].pop_back();

                    mp[s[i]].push_back(ans[i]);
                    ok = 1;
                    break;
                  }

              }	
             if(!ok)
             {
                 ans[i]=++cnt;
                 mp[s[i]].push_back(cnt);
             }
        }

        cout<<cnt<<endl;
        for(auto i:ans)
        	cout<<i<<" ";

        
        
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;
        //cin>>tt;
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 