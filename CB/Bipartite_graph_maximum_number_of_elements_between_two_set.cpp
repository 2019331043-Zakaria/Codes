#include<bits/stdc++.h>
#define pb       push_back
#define pi       acos(-1.0)
#define test     int t; scanf("%d",&t) ;while(t--)
typedef long long ll;
using namespace std;
int col[100003],cheack[100003];
int a[100003],b[100003];
vector<int>node[100003];
void dfs(int p,int c)
{
    a[p]=1;
    b[p]=1;
    col[p]=c;

    for(int i=0;i<node[p].size();i++)
    {
        int temp=node[p][i];
         if(!a[temp])
         {
            dfs(temp,!c);

         }

    }


}
int main()
{      
     int j=0;
     test
     {

     int n;
     scanf("%d",&n);
     for(int i=0;i<=100002;i++)
        node[i].clear();
     int t=n;
     int x,y;
     int mx=0,mn=1e9;
     while(t--)
     {
            scanf("%d %d",&x,&y);
            cheack[x]++;
            cheack[y]++;
            mx=max(mx,max(x,y));
            mn=min(mn,min(x,y));
            node[x].push_back(y);
            node[y].push_back(x);
            
     }
           
           int ans=0;
      for(int i=mn;i<=mx;i++)
      {
        if(cheack[i])
        {
        if(!a[i])
        { 

            dfs(i,0);
            int temp1=0,temp2=0;
            for(int j=mn;j<=mx;j++)
            {
                 if(cheack[j])
                 {
                    if(b[j])
                    {
                         if(col[j])
                        temp1++;
                           else
                        temp2++;
                    }
                 }
            }
            memset(b,0,sizeof(b));

           
          ans+=max(temp2,temp1);
        }
    }
      }
   
    
       
       printf("Case %d: %d\n",++j,ans);
       memset(b,0,sizeof(b));
       memset(a,0,sizeof(a));
       memset(col,0,sizeof(col));
       memset(cheack,0,sizeof(cheack));

     }

     return 0;
}
