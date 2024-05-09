/*
* @Author: Zakaria 
* @Date:   2022-10-13 21:20:32
* @Last Modified time: 2022-10-14 10:32:05
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
        
        int n;
        cin>>n;

        ll a[n+1];

        map<int, vector<int> > m;
        
        ll Arrayor = 0;


        for(int i=1 ; i<=n ; i++)
        {
        	cin>>a[i];
            Arrayor|=a[i];
        }

        int vis[n+1];
        memset(vis, 0, sizeof(vis));
        
        ll temp=0;



        while(temp!=Arrayor)
        {
               
               ll pans=temp;
               int index=-1;
               ll mx=temp;

               for(int i=1 ; i<=n ; i++)
               {
                   if(vis[i])
                    continue;
                   if((pans|a[i])>mx)
                   {
                        mx=pans|a[i];
                        index=i;
                   }
               }

             
               if(index!=-1)
               {

                   cout<<a[index]<<" ";
                   vis[index]=1;
                   temp=mx;
               }
               else
                break;
        }

        for(int i=1 ; i<=n ; i++)
        {
             if(vis[i]==0)
                cout<<a[i]<<" ";
        }

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