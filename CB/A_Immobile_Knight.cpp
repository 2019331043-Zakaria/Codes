/*
* @Author: Zakaria 
* @Date:   2022-09-29 20:35:15
* @Last Modified time: 2022-09-29 20:44:10
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

int dx[]={2, 2, 1, 1, -2, -2, -1, -1};
int dy[]={-1, 1, -2, 2, 1, -1, -2, 2};
int n, m;
bool ok(int x, int y)
{
     
     for(int i=0 ; i<8 ; i++)
     {
     	 if(x+dx[i]>=1 && x+dx[i]<=n && y+dy[i]>=1 && y+dy[i]<=m)
     	 {
     	 	

     	 	return 0;
     	 }
     }

     return 1;

}

void Solve()
{
        
       
       cin>>n>>m;

       for(int i=1 ; i<=n ; i++)
       {
       	  for(int j=1 ; j<=m ; j++)
       	  {

       	  	  if(ok(i,j))
       	  	  {
       	  	  	 cout<<i<<" "<<j<<endl;
       	  	  	 return ;
       	  	  }
       	  }
       }

       cout<<1<<" "<<1<<endl;
      
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