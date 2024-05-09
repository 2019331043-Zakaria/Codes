#include<bits/stdc++.h>
#define n 100000000
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

//      ll n,a,b;
//      cin>>n;
       ll cnt=0,j=0;
      for(ll i=1;i<=n;i++)
      {
           if(prime(i))
           {
               cnt++;
               if(cnt==(j*100)+1){
                cout<<i<<endl;
                j++;
               }
           }

      }


 return 0;
}
