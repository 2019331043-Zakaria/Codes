#include<bits/stdc++.h>
using namespace std;
#define n 100000002
typedef long long ll;
bool v[n];
vector<int>a;
void seive()
{
      int root=sqrt(n);
      for(ll i=2;i<=n;i++)
         {
           v[i]=1;
         }
         for(ll i=2;i<=root;i++)

         {
             if(v[i]==1)
             {
                 for(ll j=2;i*j<=n;j++)
                 {
                     v[i*j]=0;
                 }

             }
         }
         for(ll i=2;i<=n;i++)
         {
             if(v[i])
                a.push_back(i);

         }


  }

int main()
{

    seive();

    ll t;
    cin>>t;
    for(ll i=1;i<=t;i++)
    {
         ll p;
         cin>>p;
        ll cnt=0;
       for(ll i=0;a[i]<=n-a[i];i++)
       {
           if(v[n-a[i]])
            cnt++;
       }
       cout<<cnt<<endl;

    }







    return 0;
}
