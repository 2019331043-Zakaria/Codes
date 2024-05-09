#include<bits/stdc++.h>
#define n 1000
#define test int t; cin>>t; while(t--)
#define fast ios::sync_with_stdio(false);
typedef long long ll;
using namespace std;
char v[n];
int main()
{

        ll temp=sqrt(n);
       for(ll i=2;i<temp;i++)
       {
           if(!(v[i]))
              {
                  for(ll j=i*i;j<=n;j+=i)
                    v[j]=1;
              }
       }
        cout<<2<<endl;
          int cnt=1;
       for(ll i=3;i<=1000;i++)
       {
           if(!(v[i]))
           {

                  cout<<i<<endl;
           }
       }

    return 0;
}
