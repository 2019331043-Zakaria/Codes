#include<bits/stdc++.h>
#define pb       push_back
#define pi       acos(-1.0)
#define mod      1000000007
#define test     int t; cin>>t ;while(t--)
typedef long long ll;
using namespace std;                                                           
const ll inf=LLONG_MAX;

char a[9][9];
int vis[9][9];
int dis[9][9];
int dx[]={-1, -2 , -2 , -1, 1, 2, 2, 1};
int dy[]={2, 1, -1, -2 ,-2 ,-1 ,1 ,2 };

bool isvisit(int e,int f)
{
    if(e<1||e>8||f<1||f>8||vis[e][f])
      return 0;
    return 1;

}


void bfs(int p,int q)
{   
     
     vis[p][q]=1;
     queue<pair<int,int> > pq;
     
     pq.push({p,q});
     
     dis[p][q]=0;

    while(!pq.empty())
    {
         int curx=pq.front().first;
         int cury=pq.front().second;
         pq.pop();

         for(int i=0;i<8;i++)
         {
             if(isvisit(curx+dx[i],cury+dy[i]))
             {
                 
                  pq.push({curx+dx[i],cury+dy[i]});
                  
                  vis[curx+dx[i]][cury+dy[i]]=1;

                  dis[curx+dx[i]][cury+dy[i]]=dis[curx][cury]+1;


             }

         }    

    }



      

}



int main()
{
      
    ios::sync_with_stdio(false);
    cin.tie(0);
     


     test
     {
        
          
          char x;
          int y;
          cin>>x>>y;


          
        bfs(int(x)-96,y);

        cin>>x>>y;

        cout<<dis[int(x)-96][y]<<endl;



        for(int i=0;i<=8;i++)
        {

           for(int j=1;j<=8;j++)
            dis[i][j]=0,vis[i][j]=0;

        }
     
      
      }
     return 0;
        
       
}