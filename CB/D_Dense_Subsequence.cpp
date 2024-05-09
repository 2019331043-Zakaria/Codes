/*
* @Author: Zakaria 
* @Date:   2022-09-05 09:43:01
* @Last Modified time: 2022-09-05 09:48:39
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
#define  MAX         200002
#define  eps         1e-6
typedef long long ll;
using namespace std;

const int N = 1e5+6;

void Solve()
{
        
        int m;
        cin>>m;

        string s;
        cin>>s;

        int cnt=1;

        map<char, set<int> > mp;

        for(int i=0 ; i<s.size() ; i++)
        {

        	 if(i<=m)
        	  ;
        	 else
        	 	cnt++;
        	 mp[s[i]].insert(cnt);
        }

        for(auto i:mp)
        {
        	 cout<<i.f<<" => ";

        	 for(auto c:i.s)
        	 	cout<<c<<" ";
        	 cout<<endl;
        }
        
      
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