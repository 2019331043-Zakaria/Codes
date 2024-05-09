#include<bits/stdc++.h>
#define testcase int t; cin>>t; while(t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define mod 10000007
typedef long long ll;
using namespace std;
ll bigmod(ll a,ll b,ll n)
{
    ll  res=1;
    a=a%n;
    if(a==0)
        return 0;
    while(b>0)
    {

           if(b%2)
            res=(res*a)%n;
            b=b>>1;
            a=(a*a)%n;
    }
    return res;
}

int main()
{

    testcase
    {
        int n;
        cin>>n;
        int m=101;
        static mx=100000;
        int a[n],b[m];
        memset(b,0,sizeof(b));
        for(int i=0;i<n;i++)
        {
            cin>>a[i];

        }
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                b[a[i]+a[j]]++;
            }
        }
        sort(b,b+m);
        reverse(b,b+m);
        mx=max()

    }

     return 0;
}

