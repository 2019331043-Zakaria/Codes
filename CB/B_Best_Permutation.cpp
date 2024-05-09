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

        vector<int>v;
        int temp=n;

        n-=3;

        for(int i=n ; i>=2;  i--)
         v.push_back(i);

        v.push_back(temp-2);
        v.push_back(1);
        v.push_back(temp-1);
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

/*3 2 4 1 5 6 */