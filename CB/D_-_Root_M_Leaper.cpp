/*
* @Author: Zakaria 
* @Date:   2022-10-08 18:34:57
* @Last Modified time: 2022-10-08 21:12:52
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
const int N = 500;

int a[N][N];
int n, m;
vector<pair<int, int> > v;
int dis[N][N], vis[N][N];
queue<pair<int, int> > q;

void foo(int x, int y, int dx, int dy)
{
	   if(x+dx<1 || x+dx>n || y+dy<1 || y+dy>n)
	   	return ;

	   if(vis[x+dx][y+dy]==0)
	   {
            q.push({x+dx, y+dy});
            vis[x+dx][y+dy]=1;
            dis[x+dx][y+dy]=min(dis[x+dx][y+dy], dis[x][y]+1);
	   }
}

void Solve()
{
        
	       cin>>n>>m;

	       for(int i=1 ; i<=n ; i++)
	       {
	       	  for(int j=1 ; j<=n ; j++)
	       	  	dis[i][j]=INT_MAX;
	       }
	       
	       map<int, int>is_perfect;

	       for(int i=1 ; i<=m ; i++)
	       	is_perfect[i]=-1;

	        for(int i=0 ; i*i<=m ; i++)
	            is_perfect[i*i]=i;
	      
	     
	      for(int j=0 ; j*j<=m ; j++)
	      {
	           if(is_perfect[m - j*j]!=-1)
	           {
	               v.push_back({j, is_perfect[m - j*j]});
	           }
	      }
	      
	      q.push({1, 1});
          vis[1][1]=1;
          dis[1][1]=0;

	      while(q.size())
	      {
	      	   int x=q.front().f;
	      	   int y=q.front().s;

	      	   q.pop();

	      	   for(auto i:v)
	      	   {
	      	   	    int dx = i.f;
	      	   	    int dy = i.s;
                    
                    foo(x, y, dx, dy);
                    foo(x, y, dx, -dy);
                    foo(x, y, -dx, dy);
                    foo(x, y, -dx, -dy);
	      	   }




	      }

	      for(int i=1 ; i<=n ; i++)
	      {
	      	for(int j=1 ; j<=n ; j++)
	      	{
	      		 if(dis[i][j]==INT_MAX)
	      		 	cout<<-1<<" ";
	      		 else
	      		 	cout<<dis[i][j]<<" ";
	      	}
	      	cout<<endl;
	      }

	      
        

      
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;
        
        //cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 