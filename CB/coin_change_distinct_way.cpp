#include <bits/stdc++.h>
using namespace std;

typedef long long ll ;

ll dp[1000005];
 
 
int main()
{
 
        ios::sync_with_stdio(false);
        cin.tie(0); 
 
        
        int n,k;
        cin>>n>>k;
        
        ll c[k];
        for(int i=0;i<k;i++)
        cin>>c[i];
 
        
         dp[0]=1;
         
 
 
        for(int i=0;i<k;i++)
        {    
 
            for(int j=c[i];j<=n;j++)
            {
                
                dp[j]+=dp[j-c[i]];
            }

            for(int i=1;i<=n;i++)
              cout<<dp[i]<<" ";
            cout<<endl;
 
 
         
        }
 
         cout<<dp[n];

 
     return 0;           
                   
}