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

        if(n==1)
        {
        	cout<<1<<endl;
        	cout<<1<<" "<<2<<endl;
        	return ;
        }

        cout<<(n+1)/2<<endl;

        int temp = n/2;
        int lans = 2;
        for(int i=temp+1 ; i<=n - (n%2) ; i++)
        {
              cout<<i*3<<" "<<lans<<endl;
              lans+=3;
        }

        if(n%2)
        {
        	cout<<1<<" "<<3*n<<endl; 
        }
        
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