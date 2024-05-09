#include<bits/stdc++.h>
#define pb       push_back
#define mp       make_pair
#define mod      1000000007
#define first    ff
#define second   ss
#define pi       acos(-1.0)
typedef long long ll;
using namespace std;
int mother[100001],son[100001];
int vis[100001];
int main()
{      


     ios::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);
     
     int n,m;
     cin>>n>>m;
      while(m--)
      {
         int x,y;
         cin>>x>>y;
           mother[x]++;
          son[y]++;
      }

    int cnt=0;    
    for(int i=1;i<=n;i++)
    {  
       if(mother[i]>son[i]&&son[i])
        cnt++;
    }

   cout<<cnt<<endl;

    
      return 0;
 }       
