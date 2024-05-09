/*
* @Author: Zakaria 
* @Date:   2022-11-05 18:57:08
* @Last Modified time: 2022-11-06 20:35:23
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
const int N = 2e6+6;



int n, m;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};



void Solve()
{
        
        cin>>n>>m;

        string s[n+1];

        for(int i=1 ; i<=n ; i++)
        {
        	string t;
        	cin>>t;
        	s[i] = '*';
        	s[i]+=t;
        }      


        int startx, starty;   

        for(int i=1 ; i<=n ; i++)
        {
        	for(int j=1 ; j<=m ; j++)
        	{
        		if(s[i][j]=='S')
        		{
        			startx = i;
        			starty = j;
        			break;
        		}
        	}
        }

        
        {
            
            

	        int vis[n+1][m+1];

	        memset(vis, 0, sizeof(vis));

	        queue<pair<int, int> > q;

	        q.push({startx-1, starty});

	        while(q.size())
	        {
	        	 pair<int, int>p = q.front();

	        	 q.pop();
	        	 
	        	 if(p.f<1 || p.f>n || p.s<1 || p.s>m)
	        	 	break;

	        	 if(s[p.f][p.s]=='#')
	        	 	break;

	        	 vis[p.f][p.s] = 1;

	        	 for(int i=0 ; i<4 ; i++)
	        	 {
	        	 	 int nextx = p.f + dx[i];
	        	 	 int nexty = p.s + dy[i];
	        	 	 if(nextx>=1 && nextx<=n && nexty>=1  && nexty<=m && vis[nextx][nexty]==0 && s[nextx][nexty]=='.')
	        	 	 {
	        	 	 	 
	        	 	 	 vis[nextx][nexty] = 1;
	        	 	 	 q.push({nextx, nexty});

	        	 	 }
	        	 }
	        }

	        if(vis[startx+1][starty] || vis[startx][starty+1] || vis[startx][starty-1])
	        {
	        	cout<<"Yes"<<endl;
	        	return ;
	        }

        }

        {

	        int vis[n+1][m+1];

	        memset(vis, 0, sizeof(vis));

	        queue<pair<int, int> > q;

	        q.push({startx+1, starty});

	        while(q.size())
	        {
	        	 pair<int, int>p = q.front();
	        	 q.pop();
	        	 
	        	 if(p.f<1 || p.f>n || p.s<1 || p.s>m)
	        	 	break;

	        	 if(s[p.f][p.s]=='#')
	        	 	break;

	        	 vis[p.f][p.s] = 1;

	        	 for(int i=0 ; i<4 ; i++)
	        	 {
	        	 	 int nextx = p.f + dx[i];
	        	 	 int nexty = p.s + dy[i];
	        	 	 if(nextx>=1 && nextx<=n && nexty>=1  && nexty<=m && vis[nextx][nexty]==0 && s[nextx][nexty]=='.')
	        	 	 {
	        	 	 	 
	        	 	 	 vis[nextx][nexty] = 1;
	        	 	 	 q.push({nextx, nexty});

	        	 	 }
	        	 }
	        }

	        if(vis[startx-1][starty] || vis[startx][starty+1] || vis[startx][starty-1])
	        {
	        	cout<<"Yes"<<endl;
	        	return ;
	        }

        }

        {

	        int vis[n+1][m+1];

	        memset(vis, 0, sizeof(vis));

	        queue<pair<int, int> > q;

	        q.push({startx, starty + 1});

	        while(q.size())
	        {
	        	 pair<int, int>p = q.front();
	        	 q.pop();
	        	 
	        	 if(p.f<1 || p.f>n || p.s<1 || p.s>m)
	        	 	break;

	        	 if(s[p.f][p.s]=='#')
	        	 	break;

	        	 vis[p.f][p.s] = 1;

	        	 for(int i=0 ; i<4 ; i++)
	        	 {
	        	 	 int nextx = p.f + dx[i];
	        	 	 int nexty = p.s + dy[i];
	        	 	 if(nextx>=1 && nextx<=n && nexty>=1  && nexty<=m && vis[nextx][nexty]==0 && s[nextx][nexty]=='.')
	        	 	 {
	        	 	 	 
	        	 	 	 vis[nextx][nexty] = 1;
	        	 	 	 q.push({nextx, nexty});

	        	 	 }
	        	 }
	        }

	        if(vis[startx][starty - 1] || vis[startx+1][starty] || vis[startx - 1][starty])
	        {
	        	cout<<"Yes"<<endl;
	        	return ;
	        }

        }

        {

	        int vis[n+1][m+1];

	        memset(vis, 0, sizeof(vis));

	        queue<pair<int, int> > q;

	        q.push({startx , starty - 1});

	        while(q.size())
	        {
	        	 pair<int, int>p = q.front();
	        	 q.pop();

	        	if(p.f<1 || p.f>n || p.s<1 || p.s>m)
	        	 	break;

	        	 if(s[p.f][p.s]=='#')
	        	 	break;
	        	 
	        	 vis[p.f][p.s] = 1;

	        	 for(int i=0 ; i<4 ; i++)
	        	 {
	        	 	 int nextx = p.f + dx[i];
	        	 	 int nexty = p.s + dy[i];
	        	 	 if(nextx>=1 && nextx<=n && nexty>=1  && nexty<=m && vis[nextx][nexty]==0 && s[nextx][nexty]=='.')
	        	 	 {
	        	 	 	 
	        	 	 	 vis[nextx][nexty] = 1;
	        	 	 	 q.push({nextx, nexty});

	        	 	 }
	        	 }
	        }

	        if(vis[startx][starty + 1] || vis[startx+1][starty] || vis[startx - 1][starty])
	        {
	        	cout<<"Yes"<<endl;
	        	return ;
	        }

        }

        cout<<"No"<<endl;
      
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;
        
     //   cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 