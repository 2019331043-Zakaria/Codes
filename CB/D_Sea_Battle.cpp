/*
* @Author: Zakaria 
* @Date:   2022-11-10 22:04:08
* @Last Modified time: 2022-11-10 23:18:06
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
        
        ll n, a, l, k;
        cin>>n>>a>>l>>k;

        string s;
        cin>>s;

        vector<int>v;
        int cnt = 0;

        for(int i=1 ; i<=n ; i++)
        {
        	 if(s[i - 1] =='1')
        	 {
        	 	cnt = 0 ;
        	 }
        	 else
        	 {
        	 	cnt++;
        	 	if(cnt==l)
        	 		v.push_back(i), cnt = 0;
        	 }
        }

       

        cout<<v.size() - a + 1<<endl;

        for(int i=0 ; i<v.size() - a + 1 ; i++)
        	cout<<v[i]<<" ";
        cout<<endl;
      
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