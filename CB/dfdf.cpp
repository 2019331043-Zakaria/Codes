#include<bits/stdc++.h>
#define pb       push_back
#define pi       acos(-1.0)
#define test     int t; cin>>t; while(t--)
typedef long long ll;
using namespace std;
int main()
{

        ios::sync_with_stdio(false);
        cin.tie(0);

        test
        {

             int row[503][503];
             int n,m;
             cin>>n>>m;

           for(int i=1;i<=n;i++)
           {
              for(int j=1;j<=m;j++)
                cin>>row[i][j];
           }
             int temp=n*m+4;
             int vis[temp];
             for(int i=1;i<=temp;i++)
                vis[i]=1;

            int x;
            set<int>st;
            for(int i=1;i<=m;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    cin>>x;
                    st.insert(x);

                }
            }

           for(auto y:st)
           {
               if(vis[y])
               {
                   int flag=0;
                   for(int i=1;i<=n;i++)
                   {
                       for(int j=1;j<=m;j++)
                       {
                           if(y==row[i][j])
                           {
                               for(int k=1;k<=m;k++)
                               {
                                   int flag=1;
                                  cout<<row[i][k]<<" ";
                                  vis[row[i][k]]=0;
                               }
                               cout<<endl;
                               break;
                           }
                       }
                       if(flag)
                        break;
                   }
               }
           }



        }


     return 0;


}
