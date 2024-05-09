/*
* @Author: Zakaria 
* @Date:   2023-03-19 21:00:22
* @Last Modified time: 2023-03-19 21:11:02
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

        map<char, vector<int> > m;

        for(int i=0 ; i<n ; i++)
        {
        	m[s[i]].push_back(i);
        }

        for(auto i:m)
        {
        	bool odd = 0, even = 0;
        	 for(auto k:i.s)
        	 {
        	 	if(k%2)
        	 		odd = 1;
        	 	else
        	 		even = 1;
        	 }

        	 if(odd && even)
        	 {
        	 	 cout<<"NO"<<endl;
        	 	 return ;
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