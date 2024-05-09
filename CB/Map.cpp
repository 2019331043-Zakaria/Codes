#include<bits/stdc++.h>
#define pi acos(-1)
typedef long long ll;
using namespace std;


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
       int j=0,k=0;
       int temp=(n-1)/2;

      for(int i=0;i<n/2;i++)
      {
         if(a[i]-a[-1]>0)
            {
                    cout<<-1*max(a[i],a[i-1])<<" ";

            }
      }
      for(int i=n/2+2;i<n;i++)
      {
          if(a[i]-a[i-1]<0)
          {
              cout<<max(a[i],a[i-1])*-1<<" ";
          }
      }
      cout<<endl;

    }
    return 0;
}

