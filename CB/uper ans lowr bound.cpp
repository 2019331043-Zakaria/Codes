#include<bits/stdc++.h>
#define test int t; cin>>t; while(t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
using namespace std;
int main()
{
     int n,cnt=0,x=1,flag=0,temp;
     cin>>n;

    while(x<=n)
    {
        for(int i=1;i<=41;i++)
        {
            for(int j=1;j<=41;j++)
            {
                for(int k=1;k<=41;k++)
                {
                    temp=i*i+j*j+k*k+i*j+i*k+j*k;
                    if(temp==x)
                    {
                       if(i==j&&j==k)
                        cnt++;
                       else if(i!=j&&j!=k)
                        cnt=cnt+6;
                       else
                        cnt=cnt+3;
                       cout<<cnt<<endl;
                       cnt=0;
                       x++;

                    }
                   else
                   {
                       cout<<0<<endl;

                   }
                }
                break;
            }
            break;
        }
        x++;

    }

    return 0;
}
