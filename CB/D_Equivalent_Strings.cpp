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

string foo(string s)
{

     if(s.size()%2)
        return s;
     string pans = foo(s.substr(0, s.size()/2));

     string lans = foo(s.substr(s.size()/2, s.size()));

     if(pans>=lans)
        return lans+pans;
     else
        return pans+lans;
}

void Solve()
{
        
        string s, t;
        cin>>s>>t;

        s = foo(s);

        t = foo(t);

        if(s==t)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
      
      
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