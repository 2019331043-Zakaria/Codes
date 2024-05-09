#include<bits/stdc++.h>
#define pb       push_back
#define mp       make_pair
#define memset   mem
#define sizeof   sof
#define mod      1000000007
#define sz       43000
typedef long long ll;
using namespace std;
int main()
{

     ios::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);

     int t;
     cin>>t;
     while(t--)
     {
         int n,x,y;
         cin>>n>>x>>y;
         int temp=y-x;
         if(temp+1==n)
         {
             for(int i=0;i<n;i++)
                cout<<x++<<" ";
             cout<<endl;
         }
         else{
             int cnt=0;
             int p=temp;
             for(int i=2;i<temp;i++)
             {
                 if(temp%i==0)
                   {
                       if((temp/i)+1<=n)
                       {
                          p=i;
                          break;

                       }
                   }
             }

         int q=1;
         int u=x,v=y;
         cout<<x<<" ";
         for(int i=0;q<=n;i++)
          {
              if(u<=y)
             {
                 cout<<u+p<<" ";
                 u=u+p;
                 q++;
             }
           else
            break;
          }

              while(q!=n)
              {
                  if(x-p>=0)
                  {
                      cout<<x-p<<" ";
                      x=x-p;
                      q++;
                  }
                  else
                    break;
              }



              while(q!=n)
              {
                  cout<<y+p<<" ";
                  y=y+p;
                  q++;
              }


            cout<<endl;

     }
     }


	 return 0;

}
