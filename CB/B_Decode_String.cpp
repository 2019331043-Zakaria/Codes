/*
* @Author: Zakaria 
* @Date:   2022-09-12 20:40:41
* @Last Modified time: 2022-09-12 20:52:19
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

       map<int, char>m;

       for(int i=1 ; i<=26 ; i++)
       	m[i]='a'+i-1;
       

       string ans="";

       for(int i=n-1 ; i>=0 ; i--)
       {
       	   if(s[i]=='0')
       	   {
       	   	    int temp=s[i-2]-'0';
       	   	    temp*=10;
       	   	    temp+=s[i-1]-'0';
                i--;
                i--;
                ans+=m[temp];
       	   }
       	   else
       	   {
              ans+=m[s[i]-'0'];

       	   }
       	   
       }
       reverse(ans.begin(), ans.end());
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