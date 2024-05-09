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
        int n, k;
        cin>>n>>k;

        string s;
        cin>>s;

        int low=n, high=-1;

        for(int i=0 ; i<n ; i++)
        {
             if(s[i]=='1')
             low=min(low, i), high=max(high, i);
        }

        if(low==n)
        {      
              
              int cum[n];

              int cnt=0;

              for(int i=0 ; i<n ; i++)
              {
                  if(s[i]=='?')
                  cnt++;
                  else
                  cnt=0;

                  cum[i]=cnt;
              }

              for(auto i:cum)
              {
                 if(i>k)
                 {
                     cout<<"No"<<endl;
                     return ;
                 }
              }

              int p=0;

              for(auto i:cum)
              {
                  if(i==k)
                  p++;
              }

              if(p==1)
              cout<<"Yes"<<endl;
              else
              cout<<"No"<<endl;

              return ;
               
              
        }

        for(int i=low ; i<=high ; i++)
        {
              if(s[i]=='0')
              {
                  cout<<"No"<<endl;
                  return ;
              }
        }

        if(high - low + 1>k)
        {
             cout<<"No"<<endl;
             return ;
        }

        int r = 0, l = 0;

        for(int i=high + 1 ; i<n ; i++)
        {
              if(s[i]=='?')
              r++;
              else
              break;
        }
        for(int i = low - 1; i>=0 ; i--)
        {
              if(s[i]=='?')
              l++;
              else
              break;
        }

        if(l && r)
        {
               if(l+r+high-low+1==k)
               cout<<"Yes"<<endl;
               else
               cout<<"No"<<endl;
        }
        else
        {
              if(high-low+1 + max(l, r)>=k)
              cout<<"Yes"<<endl;
              else
              cout<<"No"<<endl;
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