#include<bits/stdc++.h>
#define pb       push_back
#define pi       acos(-1.0)
#define mod      1000000007
#define test     int t; cin>>t ;while(t--)
typedef long long ll;
using namespace std;                                                           
const ll inf=LLONG_MAX;
int n,m,x,y,ans1,ans2,e,f,temp1,temp2;

char a[1003][1003];
int vis[1003][1003];
int dis[1003][1003];

vector<vector<pair<int,int>>> mother( 1003, vector<pair<int,int>>( 1003 ) );


int dx[]={-1, 1, 0 , 0};
int dy[]={0, 0,  1, -1};

bool isvisit(int e,int f)
{
    if(e<1||e>n||f<1||f>m||vis[e][f]||a[e][f]=='#')
      return 0;

      return 1;
}


void bfs(int p,int q)
{

    vis[p][q]=1;
    dis[p][q]=0;
    queue<pair<int,int> >pq;
    pq.push({p,q});
    
    mother[p][q]={p,q};

  
    while(!pq.empty())
    {

        int curx=pq.front().first;
        int cury=pq.front().second;
      
        pq.pop();
        
        for(int i=0;i<4;i++)
        {
            if(isvisit(dx[i]+curx,dy[i]+cury))
              {
                   

                   mother[dx[i]+curx][dy[i]+cury]={curx,cury};

                   dis[dx[i]+curx][dy[i]+cury]=dis[curx][cury]+1;

                   pq.push({dx[i]+curx,dy[i]+cury});

                   vis[dx[i]+curx][dy[i]+cury]=1;
                    
              }

        }

    }


}


void printparrent(int k,int l)
{
      
      if(k==x&&l==y)
        return ;
      printparrent(mother[k][l].first,mother[k][l].second);
      
      if(k==temp1&&l>temp2)
          cout<<"R";
      if(k==temp1&&l<temp2)
        cout<<"L";
      if(k<temp1&&l==temp2)
        cout<<"U";
      if(k>temp1&&l==temp2)
        cout<<"D";

      temp2=l,temp1=k;

      

}


int main()
{
      
    ios::sync_with_stdio(false);
    cin.tie(0);
     
      
     
     cin>>n>>m;

     for(int i=1;i<=n;i++)
     {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
            if(a[i][j]=='A')
              x=i,y=j;
            if(a[i][j]=='B')
              ans1=i,ans2=j;

        }
 
     }
   
     bfs(x,y);
      
      temp1=x,temp2=y;
     
     if(vis[ans1][ans2]){
         
         cout<<"YES\n";

         cout<<dis[ans1][ans2]<<endl;

         printparrent(ans1,ans2);
   }

   else 
    cout<<"NO\n";


           
      
     return 0;
        
       
}