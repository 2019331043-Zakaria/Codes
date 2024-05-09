/*
* @Author: Zakaria 
* @Date:   2023-01-10 17:51:43
* @Last Modified time: 2023-01-10 18:17:29
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

          map<int, vector<int> >m;
          set<int>st;

          for(int i=1 ; i<=n ; i++)
          {
          	 int k;
          	 cin>>k;
             while(k--)
             {
             	 int pos;
             	 cin>>pos;
             	 m[pos].push_back(i);
             	 st.insert(pos);
             }

          }

          if(n<=1)
          {
          	 cout<<"NO"<<endl;
          	 return ;
          }

          set<int>pans;

          for(auto i:st)
          {
              if(m[i].size()==1)
              {
              	 pans.insert(m[i].back());
              }
          }

          if(pans.size()==n)
          {
          	cout<<"NO"<<endl;
          }
          else
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