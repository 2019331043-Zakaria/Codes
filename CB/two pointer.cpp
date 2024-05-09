#include<bits/stdc++.h>
#define test int t; cin>>t; while(t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
typedef long long ll;
using namespace std;
int main()
{
    ll n,k;
    cin>>n>>k;
    ll a[n+1];
    a[0]=0;
    for(int i=1;i<=n;i++){
       {
           cin>>a[i];
          a[i]=a[i-1]+a[i];

       }


    }
    int mx=0;
    int p=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]-a[p]>k)
        {
            p++;
        }
        mx=max(mx,i-p);
    }
    cout<<mx<<endl;


  return 0;
}
