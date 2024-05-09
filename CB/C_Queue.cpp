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
        
       vector<pair<int, string > > v;

       int n;
       cin>>n;

       for(int i=0 ; i<n ; i++)
       {
           int x;
           string s;
           cin>>s>>x;

           v.push_back({x, s});
       }

       sort(v.begin(), v.end());

    
       map<string, int>m;
       for(auto i:v)
       	m[i.s]=1;

       int cnt=0;
       int ans=1e9;

       for(int i=0 ; i<n ; i++)
       {
          int temp = v[i].f - cnt;

          for(int j=i-1 ; j>=0 ; j--)
          {
              if(temp>0 && m[v[j].s]<=m[v[i].s])
                m[v[j].s]=ans, temp--;
          }
          
          cnt=max(cnt, v[i].f);

          if(temp)
          {
             cout<<-1<<endl;
             return ;
          }

          ans--;
       }

       for(auto i:v)
        cout<<i.s<<" "<<m[i.s]<<endl;

     

      
       
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;
        
    //    cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 