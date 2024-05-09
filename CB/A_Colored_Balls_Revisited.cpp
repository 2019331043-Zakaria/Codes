/*
* @Author: Zakaria 
* @Date:   2022-09-08 20:35:35
* @Last Modified time: 2022-09-08 21:01:01
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

void Solve()
{
        
        int n;
        cin>>n;

        vector<pair<int, int> > v;

        for(int i=1 ; i<=n ; i++)
        {
        	 int x;
        	 cin>>x;
        	 v.push_back({x, i});
        }

        sort(v.begin(), v.end());
        
        cout<<v.back().s<<endl;
      
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;
        
      //  cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 

/*3 2 4 1 5 6 */