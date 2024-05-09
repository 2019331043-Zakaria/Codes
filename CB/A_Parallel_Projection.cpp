/*
* @Author: Zakaria 
* @Date:   2023-01-15 18:07:47
* @Last Modified time: 2023-01-15 18:14:11
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
        
      ll w, d, h;
      cin>>w>>d>>h;

      ll a, b, f, g;
      cin>>a>>b>>f>>g;

      ll front = 0;

      front+=h;

      front+=g;
      front+=b;
      front+=abs(a-f);

      ll back = 0;

      back+=h;
      back+=d - g;
      back+=d - b;
      back+=abs(a-f);

      ll left = 0;
      left+=h;

      left+=a;
      left+=f;
      left+=abs(g-b);

      ll right = 0;
      right+=h;

      right+=w - a;
      right+=w - f;
      right+=abs(g-b);

      cout<<min({front, back, left, right})<<endl;
      
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