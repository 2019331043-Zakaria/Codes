/*
* @Author: Zakaria 
* @Date:   2022-10-29 16:27:42
* @Last Modified time: 2022-11-04 12:36:30
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
        
       ll n, m, k;
       cin>>n>>m>>k;

       vector<int>v;

       for(int i=1 ; i<=k ; i++)
       {
           int x;
           cin>>x;
           v.push_back(x);
       }

       reverse(v.begin(), v.end());

       set<int>st;
       int last = k;
       int empty = n*m - 2;

       
       while(v.size())
       {
            st.insert(v.back());
            v.pop_back();
            
            if(st.size()>=empty)
            {

                cout<<"TIDAK"<<endl;
                return ;
            }

            while( st.find(last)!=st.end())
            {
                st.erase(last);
                last--;
            }

       }
       
       if(st.size())
        cout<<"TIDAK"<<endl;
       else
        cout<<"YA"<<endl;
      
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