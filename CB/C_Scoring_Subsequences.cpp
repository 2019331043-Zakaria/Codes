/*
* @Author: Zakaria 
* @Date:   2023-03-05 00:05:50
* @Last Modified time: 2023-03-05 01:25:24
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

int a[N];
int n;

void Solve()
{
        
      cin>>n;

      for(int i=1 ; i<=n ; i++)
      	cin>>a[i];


      int l = 1;
      int op = 0;
      for(int i=1 ; i<=n ; i++)
      {
      	 while(i-l+1>a[l])
      	 	l++, op++;
      	 op++;
      	 cout<<i-l+1<<" ";
      }

      cout<<endl;

      cout<<op<<endl;
      
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