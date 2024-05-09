#include<bits/stdc++.h>
#define pb       push_back
#define mp       make_pair
#define memset   mem
#define sizeof   sof
#define mod      1000000007
#define sz       20000002
typedef long long ll;
using namespace std;
/*
bool prime(ll n)
{

        if(n==2)
            return 1;
       else if(!(n%2)||n<=1)
          return 0;
      else
      {

          ll temp=sqrt(n)+1;

          for(ll j=3;j<temp;j+=2)
          {
              if(!(n%j))
                return 0;
          }
          return 1;
     }

}
*/
int a[sz];
vector<int>prime;
void seive(ll n)
{
     ll temp=sqrt(n);
     for(ll i=3;i<=temp;i+=2)
     {
         if(!(a[i]))
         {
              for(ll j=i*i;j<sz;j+=i+i)
              {
                 a[j]=1;
              }
         }
     }

}

int main()
{
      ios::sync_with_stdio(false);
      cin.tie(NULL); 
      cout.tie(NULL);
      seive(sz);
      for(ll i=3;i<sz;i+=2)
      {
         if(!a[i]&&!a[i+2])
         {
            prime.push_back(i);
         }
      }
      ll x;
      while(cin>>x)
      {
         cout<<"("<<prime[x-1]<<", "<<prime[x-1]+2<<")"<<endl;
      }


   
 return 0;
}


