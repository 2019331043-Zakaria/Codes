/*
* @Author: Zakaria 
* @Date:   2022-04-01 01:08:32
* @Last Modified time: 2022-04-12 01:24:26
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
#define  MAX         200002
typedef long long ll;
using namespace std;

void Solve()
{
       
          int n;
          cin>>n;

          int a[n+1];

          stack<pair<int,int> >st;


          for(int i=1 ; i<=n ; i++)
          {
              cin>>a[i];
              while(st.size()  && st.top().f>=a[i])
                st.pop();

              if(st.size())
                cout<<st.top().s<<" ";
              else
                cout<<0<<" ";

              st.push({a[i],i});
          }


          

          
          
         
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
