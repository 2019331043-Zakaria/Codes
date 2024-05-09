/*
* @Author: Zakaria 
* @Date:   2022-11-05 18:04:12
* @Last Modified time: 2022-11-05 18:17:28
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

         int a[n+1];

         vector<int>v;

         for(int i=1 ; i<=n ; i++)
         {
            cin>>a[i];
            v.push_back(a[i]);
         }

         int cnt = 0;

         do{

            cnt++;
            if(cnt==2)
            {
              for(auto i:v)
                cout<<i<<" ";
               cout<<endl;
              return ;
            }


         }while(prev_permutation(v.begin(), v.end()));
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;
        
     //   cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 