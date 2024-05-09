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

    ll x;
    while(scanf("%lld",&x)==1)
   {
        ll a,b,flag=0;
       if(x==1)
         printf("%lld is not the sum of two primes!\n",x);
       else if(x%2==1)
       {
           if(prime(x-2))
             printf("%lld is the sum of 2 and %lld.\n",x,x-2);
           else
             printf("%lld is not the sum of two primes!\n",x);
       }
       else
        {

             int flag=0;
             for(ll i=x/2-1;i>=2;i--)
             {
                 if(prime(i)&&prime(x-i))
                 {
                     printf("%lld is the sum of %lld and %lld.\n",x,i,x-i);
                     flag=1;
                     break;
                 }
             }
             if(flag==0)
                printf("%lld is not the sum of two primes!\n",x);


        }
   }
 return 0;
}
