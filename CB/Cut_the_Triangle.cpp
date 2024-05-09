/*
* @Author: Zakaria 
* @Date:   2022-12-16 20:35:19
* @Last Modified time: 2022-12-16 20:41:49
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
        set<int>a, b;

        int x, y;
        cin>>x>>y;

        a.insert(x);
        b.insert(y);

         cin>>x>>y;

        a.insert(x);
        b.insert(y);

         cin>>x>>y;

        a.insert(x);
        b.insert(y);

        if(a.size()<=2 && b.size()<=2)
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