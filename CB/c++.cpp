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
        if(n%2==0)
        {
            for(int i=1;i<=n;i++)
            {
                int cnt=0;
                for(int j=1,k=1;j<=n;j++,k++)
                {
                    if(i==j)
                    {
                        if((k*i)%2==0)
                            cout<<k*i<<" ";
                    }

                }
            }
        }

    }
    return 0;
}
