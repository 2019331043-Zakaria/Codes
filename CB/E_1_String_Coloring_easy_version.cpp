/*
* @Author: Zakaria 
* @Date:   2022-09-16 09:37:33
* @Last Modified time: 2022-09-16 10:08:27
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

        vector<pair<char, int> > sub1, sub2;

        sub1.push_back({'$', -1});
        sub2.push_back({'$', -1});


        for(int i=0;  i<n ; i++)
        {
        	if(s[i]>=sub1.back().f)
        		sub1.push_back({s[i], i});
        	else if(s[i]>=sub2.back().f)
        		sub2.push_back({s[i], i});
        	else
        	{
        		cout<<"NO"<<endl;
        		return ;
        	}
        }

        
        for(int i=1 ; i<sub1.size() ; i++)
        	s[sub1[i].s]='0';

        for(int i=1 ; i<sub2.size() ; i++)
        	s[sub2[i].s]='1';
        
        cout<<"YES"<<endl;
        cout<<s<<endl;

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