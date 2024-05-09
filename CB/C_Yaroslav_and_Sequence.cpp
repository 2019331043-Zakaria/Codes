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

const int N = 2e5+6;

void Solve()
{

       int n;
       cin>>n;

       vector<ll>v;

       for(int i=0 ; i<n+n-1 ; i++)
       {
            ll x;
            cin>>x;
            v.push_back(x);
       }
       
       sort(v.begin(), v.end());

       if(n%2)
       {
            ll sum=0;
            for(auto i:v)
            sum+=abs(i);

            cout<<sum<<endl;
       }
       else
       {
          
            int neg=0;
            for(auto i:v)
            {
                if(i<0)
                neg++;
            }
            
            ll sum=0;

            for(auto i:v) 
            sum+=abs(i);

            for(int i=0 ; i<v.size() ; i++)
             v[i]=abs(v[i]);
            
            sort(v.begin(), v.end());

            if(neg%2)
             sum-=v[0], sum-=v[0];
            
            cout<<sum<<endl;
            

       }
         
      
      
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;
        
       // cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 