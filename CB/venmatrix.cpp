#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
   int t;
   cin>>t;
   while(t--)
  {
        int n;
        cin>>n;
        int a[n][n];

       if(n%2==0)
       {
          if(n%4==0)
        {
                int cnt=1;
         for(int i=0;i<n;i++)
         {

             for(int j=0;j<n;j++)
             {

                 a[i][j]=cnt++;
             }

         }
          }
       else
       {
              int cnt=1;
           for(int i=0;i<n;i++)
           {
               for(int j=0;j<n;j++)
               {
                  if(i==0)
                  {
                      if(j==0)
                      {
                          a[i][j]=n;
                          cnt++;
                      }
                      else if(j==n-1)
                      {
                          a[i][j]=1;
                          cnt++;
                      }
                      else
                      {
                          a[i][j]=cnt;
                          cnt++;
                      }
                  }
                  else
                  {
                      a[i][j]=cnt;
                      cnt++;
                  }
               }
           }

       }

       }

   else
   {

          int cnt=1;
         for(int i=0;i<n;i++)
         {

             for(int j=0;j<n;j++)
             {

                 a[i][j]=cnt++;
             }

         }

   }
if(n%2==0){
        for(int i=0;i<n;i++)
         {

             for(int j=0;j<n;j++)
             {


                cout<<a[i][j]<<" ";


             }
             cout<<endl;

         }

  }
  else
  {
      for(int i=0;i<n;i++)
         {

             for(int j=0;j<n;j++)
             {

               if(i==0&&(j==0||j==n-1))
                {
                    swap(a[i][j],a[i][j+1]);
                       a[0][n-1]=n;
                }

                cout<<a[i][j]<<" ";


             }
             cout<<endl;

         }
  }






  }
    return 0;
}
