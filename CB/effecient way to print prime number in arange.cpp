#include<bits/stdc++.h>
#define test int t; cin>>t; while(t--)
#define fast ios::sync_with_stdio(false);
typedef long long ll;
using namespace std;
bool prime(ll ans)
{
    if(ans<=1)
        return 0;
        if(ans==2)
            return 1;
   else if(ans%2==0)
        return 0;
     else
     {

          ll temp=sqrt(ans)+1;

          for(ll j=3;j<=temp;j+=2)
          {
              if(ans%j==0)
                return 0;
          }
          return 1;


     }

}

int main()
{
  fast
   test
   {
      ll n,a,b;
      cin>>a>>b;
       cout<<endl;
      for(ll i=a;i<=b;i++)
      {
          if(prime(i))
           cout<<i<<endl;
      }

   }
 return 0;
}

