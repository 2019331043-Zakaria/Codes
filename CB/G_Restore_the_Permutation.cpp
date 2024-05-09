/*
* @Author: Zakaria 
* @Date:   2022-11-18 22:22:07
* @Last Modified time: 2022-11-19 15:38:35
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

        map<int, int>m;

        vector<int>v;

        for(int i=0 ; i<n/2 ; i++)
        {
        	int x;
        	cin>>x;
        	m[x] = 1;
        	v.push_back(x);
        }

        if(m.size()!=n/2)
        {
        	cout<<-1<<endl;
        	return ;
        }

        set<int>st;

        for(int i=1 ; i<=2*n ; i++)
        {
        	if(m[i]==0)
        		st.insert(i);
        }
        
        vector<pair<int, int>  > ans;

     

        while(v.size())
        {
        	 int val = v.back();

        	
        	 auto it = st.lower_bound(val);
                
                 
        	 it--;

                  
        	 if(*it<val)
        	 {
        	 	 ans.push_back({*it, val});
        	 	 st.erase(it);
        	 }
        	 else
        	 {
        	 	cout<<-1<<endl;
        	 	return ;
        	 }

        	 v.pop_back();
        }

        while(ans.size())
        {
        	cout<<ans.back().f<<" "<<ans.back().s<<" ";
        	ans.pop_back();
        }

        cout<<endl;
      
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