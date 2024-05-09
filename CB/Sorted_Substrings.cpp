/*
* @Author: Zakaria 
* @Date:   2022-10-26 20:35:26
* @Last Modified time: 2022-10-26 21:22:51
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

        if(is_sorted(s.begin(), s.end()))
        {
        	cout<<0<<endl;
        	return ;
        }

        string pans = "";

        pans+=s[0];

        for(int i=1 ; i<s.size() ; i++)
        {
        	if(pans.back()!=s[i])
        		pans+=s[i];
        	else
        		continue;
        }

        if(pans[0]=='1')
        {
            int cnt=0;

        	for(int i=0 ; i<pans.size()-1 ; i++)
        		if(pans[i]=='1')
        			cnt++;
        	cout<<cnt<<endl;
        }
        else
        {
        	int cnt=0;

        	for(int i=1 ; i<pans.size()-1 ; i++)
        		if(pans[i]=='1')
        			cnt++;

            cout<<cnt<<endl;
        }
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