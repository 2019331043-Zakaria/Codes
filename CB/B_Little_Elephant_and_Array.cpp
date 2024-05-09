/*
* @Author: Zakaria 
* @Date:   2022-09-09 21:02:57
* @Last Modified time: 2022-09-09 21:02:57
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
#define  eps         1e-6
typedef long long ll;
using namespace std;

const int N = 1e5+6;

int freq[N];

vector<int>v[N]; 

void Solve()
{
      int n, m;
      cin>>n>>m;

      int a[N];

      vector<int>can;

      for(int i=1 ; i<=n ; i++)
      {
           cin>>a[i];

           if(a[i]<=n)
           {
               freq[a[i]]++;
               v[a[i]].push_back(i);
               if(freq[a[i]]==a[i])
               {
                    can.push_back(a[i]);
               }
           }
      }  


      while (m--)
      {
          int l,  r;
          cin>>l>>r;

          int cnt=0;

          for(auto i:can)
          {
               int x = upper_bound(v[i].begin(), v[i].end(), r) - lower_bound(v[i].begin(), v[i].end(), l);
               
               if(x==i)
               cnt++;
          }

          cout<<cnt<<endl;
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