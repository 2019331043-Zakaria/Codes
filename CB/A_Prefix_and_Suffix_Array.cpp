/*
* @Author: Zakaria 
* @Date:   2023-03-04 23:38:43
* @Last Modified time: 2023-03-04 23:52:16
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

       string s[3*n];
       vector<char>v;

       vector<string>all;

       for(int i=1 ; i<=n+n-2 ; i++)
       {
       	 
       	  cin>>s[i];

       }

       int tot = n+n-2;

       for(int i=1 ; i<n ; i++)
       {
       	   vector<string>v;
       	   for(int j=1 ; j<=tot ; j++)
       	   {
       	   	   if(s[j].size()==i)
       	   	   	v.push_back(s[j]);
       	   }

       	   string pans = v[0];
       	   string lans = v[1];

       	   string tempp = pans;
       	   string templ = lans;

       	   reverse(pans.begin(), pans.end());
       	   reverse(templ.begin(), templ.end());

       	   if(pans!=lans && templ!=tempp)
       	   {
       	   	  cout<<"NO"<<endl;
       	   	  return;
       	   }
       }

       cout<<"YES"<<endl;
      
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