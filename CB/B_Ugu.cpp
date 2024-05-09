/*
* @Author: Zakaria 
* @Date:   2022-10-23 16:17:32
* @Last Modified time: 2022-10-24 21:08:18
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

        string pans="";
        pans+=s[0];

        for(int i=1 ; i<n ; i++)
        {
            if(pans.back()==s[i])
            	continue;
            else
            	pans+=s[i];
        }

        if(is_sorted(s.begin(), s.end()))
        {
            cout<<0<<endl;
            return ;
        }

        if(pans[0]=='0')
        	cout<<pans.size()-2<<endl;
        else
        	cout<<pans.size()-1<<endl;
      
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