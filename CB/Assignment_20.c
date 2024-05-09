#include <stdio.h>
typedef long long ll;
using namespace std;                                                           
const ll inf=LLONG_MAX;
ll n,m,p,q,k,w;
ll node[504][504];
ll dis[503][504];
ll vis[504][504];
void warshall(ll n)
{
 
    for(int k=1;k<=n;k++)
    {
          for(int i=1;i<=n;i++)
          {
             for(int j=1;j<=n;j++)
             {
                
                 dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
             }
          }
    }
}
 
 
 
int main()
{
      
       
       scanf("%ld %ld %ld",&n,&m,&k);
       
      for(int i=1;i<=n;i++)
      {
         for(int j=1;j<=n;j++)
         {
              dis[i][j]=inf;
         }
         dis[i][i]=0;

      }
 
        while(m--)
        {
             cin>>p>>q>>w;
               scanf("%ld %ld %ld",&p,&q,&w);
             
             dis[p][q]=min(dis[p][q],w);
             dis[q][p]=min(dis[q][p],w); 
 
        }
 
      
     
      warshall(n);
 
     while(k--)
     {
         cin>>p>>q;
         scanf("%ld %ld",&p,&q);
         if(p==q)
            printf("0\n");
         else if(dis[p][q]>=inf||dis[p][q]<0)
            printf("-1\n");
        else
          printf("%lld\n",dis[p][q]);
     }

     
 
      
     return 0;
 }
    