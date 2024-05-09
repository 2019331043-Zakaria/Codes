/*
* @Author: Zakaria 
* @Date:   2022-12-12 20:48:16
* @Last Modified time: 2022-12-12 21:45:15
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

int n;
string s, t;
int vis[2][N];

void Solve()
{
        
      
       cin>>n;
       for(int i=1 ; i<=n ; i++)
       	vis[0][i]=0, vis[1][i]=0;

       cin>>s>>t;

       s = '*' + s + '*';
       t = '*' + t + '*';
       
       {


           int last = 0;

           for(int i=1 ; i<=n ; i++)
           {
           	  if(s[i]=='B')
           	  {
           	  	 last = i;
           	  }
           }

           int up = 0;

           for(int i=last ; i>=0 ; )
           {
            
           	  if(up==0)
           	  {
           	  	  if(t[i]=='B' && vis[1][i]==0)
           	  	  {
                   
                     vis[0][i]=1;
           	  	  	 up = 1;
           	  	  }
           	  	  else if(s[i-1]=='B' && vis[0][i-1]==0)
           	  	  {
                     vis[0][i]=1;
           	  	  	 i--;

           	  	  }
           	  	  else
           	  	  {
                    vis[0][i]=1;
                    break;
                  }
           	  }
           	  else
           	  {
           	  	  if(s[i]=='B' && vis[0][i]==0)
           	  	  {
                  
           	  	  	up = 0;
                    vis[1][i]=1;
           	  	  }
           	  	  else if(t[i-1]=='B' && vis[1][i-1]==0)
           	  	  {

                     vis[1][i]=1;
           	  	  	 i--;
           	  	  }
           	  	  else
           	  	  {
                    vis[1][i]=1;
                    break;
                  }
           	  }
           }

           bool ok=1;

           for(int i=1 ; i<=n ; i++)
           {
           	   if(s[i]=='B')
           	   {
           	   	  if(vis[0][i]==0)
           	   	  {
           	   	  	 ok=0;
           	   	  }
           	   }
           	   if(t[i]=='B')
           	   {
           	   	  if(vis[1][i]==0)
           	   	  {
           	   	  	 ok=0;
           	   	  }
           	   }
           }

           if(ok)
           {
           	  cout<<"YES"<<endl;
           	  return ;
           }

        }

        for(int i=1 ; i<=n ; i++)
            vis[0][i]=0, vis[1][i]=0;

        {
                int last = 0;

               for(int i=1 ; i<=n ; i++)
               {
                  if(t[i]=='B')
                  {
                     last = i;
                  }
               }

               int up = 1;

               for(int i=last ; i>=0 ; )
               {
                
                  if(up==0)
                  {
                      if(t[i]=='B' && vis[1][i]==0)
                      {
                       
                         vis[0][i]=1;
                         up = 1;
                      }
                      else if(s[i-1]=='B' && vis[0][i-1]==0)
                      {
                         vis[0][i]=1;
                         i--;

                      }
                      else
                      {
                        vis[0][i]=1;
                        break;
                      }
                  }
                  else
                  {
                      if(s[i]=='B' && vis[0][i]==0)
                      {
                      
                        up = 0;
                        vis[1][i]=1;
                      }
                      else if(t[i-1]=='B' && vis[1][i-1]==0)
                      {

                         vis[1][i]=1;
                         i--;
                      }
                      else
                      {
                        vis[1][i]=1;
                        break;
                      }
                  }
               }

               bool ok=1;

               for(int i=1 ; i<=n ; i++)
               {
                   if(s[i]=='B')
                   {
                      if(vis[0][i]==0)
                      {
                         ok=0;
                      }
                   }
                   if(t[i]=='B')
                   {
                      if(vis[1][i]==0)
                      {
                         ok=0;
                      }
                   }
               }

               if(ok)
               {
                  cout<<"YES"<<endl;
                  return ;
               }
        }

        cout<<"NO"<<endl;



   
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