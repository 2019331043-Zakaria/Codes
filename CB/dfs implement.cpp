#include<bits/stdc++.h>
#define test int t; cin>>t; while(t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define white 1
#define gray 2
#define black 3
typedef long long ll;
using namespace std;
int color[100];
int graph[100][100];
int city,bridge;
void dfsvisit(int x)
{

    color[x]=gray;
    for(int i=0;i<city;i++)
    {
        if(graph[x][i]==1)
        {
            if(color[i]==white)
                dfsvisit(i);
        }
    }
   color[x]=black;
}
void dfs()
{
    for(int i=0;i<city;i++)
        color[i]=white;
    for(int i=0;i<city;i++)
    {
        if(color[i]==white)
          dfsvisit(i);

    }

}
int main()
{

    cin>>city>>bridge;
    int v1,v2;
    for(int i=0;i<city;i++)
        {
            cin>>v1>>v1;
            graph[v1][v2]=1;
            graph[v2][v1]=1;
        }
    dfs();

    return 0;

}
