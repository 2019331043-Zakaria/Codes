/*
* @Author: Zakaria 
* @Date:   2023-02-03 20:36:40
* @Last Modified time: 2023-02-03 20:38:56
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

       map<char, int>m;

       for(auto i:s)
       	m[i]++;


       int ans = 0;

       set<int>st;

       for(auto i:s)
       {
       	  st.insert(i);
       	  m[i]--;
       	  int temp = 0;
       	  for(char c = 'a' ; c<='z' ; c++)
       	  if(m[c])
       	  	temp++;

       	  ans=max(ans, (int)st.size() + temp);
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