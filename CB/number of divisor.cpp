#include<bits/stdc++.h>
#define test int t; cin>>t; while(t--)
#define fast ios::sync_with_stdio(false);
#define pi 3.14159265358979323846264338327950288419716939937510
#define pb push_back
typedef long long ll;
ll a[100000000]={0};
using namespace std;
int main()
{

      fast
        ll n;
        cin>>n;


        for(int i=1;i<=n;i++)
        {
            for(int j=1;i*j<=n;j++)
                {
                    a[i*j]++;
                }
        }

      cout<<a[n];
return 0;

}
