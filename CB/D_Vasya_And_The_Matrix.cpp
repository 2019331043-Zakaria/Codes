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
        
       int n, m;
       cin>>n>>m;

       vector<ll>row, column;
       ll totxor=0;

       for(int i=0 ; i<n ; i++)
       {
          ll x;
          cin>>x;
          row.push_back(x);
          totxor^=x;
       }

       for(int i=0 ; i<m ; i++)
       {
          ll x;
          cin>>x;
          column.push_back(x);
          totxor^=x;
       }

       if(totxor)
       {         
          cout<<"NO"<<endl;
          return ;
       }

       cout<<"YES"<<endl;
       
       ll ans[n+1][m+1];
      
       reverse(row.begin(), row.end());
       reverse(column.begin(), column.end());
       for(int i=1 ; i<n ; i++)
       {
           for(int j=1 ; j<m ; j++)
               ans[i][j]=0;

           ans[i][m]=row.back();
          // cout<<row.back()<<endl;
           row.pop_back();
           
       }
   
       ll pans=row.back();

       for(int i=1 ; i<m ; i++)
          ans[n][i] = column.back(), pans^=column.back(), column.pop_back();
       ans[n][m]=pans;
       for(int i=1 ; i<=n ; i++)
       {
          for(int j=1 ; j<=m ; j++)
               cout<<ans[i][j]<<" ";
          cout<<endl;
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