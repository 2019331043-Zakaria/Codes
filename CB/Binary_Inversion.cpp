/*
* @Author: Zakaria 
* @Date:   2023-04-18 00:05:28
* @Last Modified time: 2023-04-18 00:19:53
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

struct element
{
	ll one, zero, inv, index;
};


bool comp(element p, element q)
{
	if(p.zero==q.zero)
	{
		if(p.one==q.one)
			return p.inv<q.inv;
		else
			return p.one<q.one;
	}

	return p.zero>q.zero;
}


void Solve()
{
        
      int n, m;
      cin>>n>>m;

      vector<element>v;
      string s[n];
      for(int i=0 ; i<n ; i++)
      {
      	 
      	 cin>>s[i];

      	 ll one = 0, zero = 0, inv = 0;

      	 for(auto k:s[i])
      	 {
      	 	if(k=='0')
      	 		zero++, inv+=one;
      	 	else
      	 		one++;

      	 }

      	 v.push_back({one, zero, inv, i});
      }

      
      sort(v.begin(), v.end(), comp);

      string tot="";

      for(auto i:v)
      {
      	 tot+=s[i.index];
      }

      ll ans = 0;
      ll one = 0, zero = 0;

      for(auto i:tot)
      {
      	if(i=='0')
      		zero++, ans+=one;
      	else
      		one++;
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