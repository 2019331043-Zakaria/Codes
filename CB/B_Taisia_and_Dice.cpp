/*
* @Author: Zakaria 
* @Date:   2023-01-27 20:40:04
* @Last Modified time: 2023-01-27 20:47:40
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
        
      int n, s, r;
      cin>>n>>s>>r;

      int temp = s - r;

      int val = r/(n-1);

      int baki = r%(n-1);

      vector<int>v;

      for(int i=1 ; i<n ; i++)
      	v.push_back(val);

      for(int i=0 ; i<baki ; i++)
      	v[i]++;

      v.push_back(temp);

      for(auto i:v)
      	cout<<i<<" ";

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