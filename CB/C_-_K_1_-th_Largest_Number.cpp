/*
* @Author: Zakaria 
* @Date:   2022-10-15 18:05:10
* @Last Modified time: 2022-10-15 18:12:33
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
        
        int a[n];
        set<int>st;
        for(int i=0 ; i<n ; i++)
        	cin>>a[i], st.insert(a[i]);

        vector<int>v;

        for(auto i:st)
        	v.push_back(i);

      /*  for(auto i:st)
        	cout<<i<<" ";

        cout<<endl;*/

        map<int, int>pos;

        for(int i=0 ; i<v.size() ; i++)
        {
            pos[v[i]]=i;
        }

        map<int, int>ans;


        for(int i=0 ; i<n ; i++)
        {
        //	cout<<a[i]<<" "<<v.size() - pos[a[i]]-1<<endl;
        	ans[v.size() - pos[a[i]]-1]++;
        }

        for(int i=0 ; i<n ; i++)
        	cout<<ans[i]<<endl;

      
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