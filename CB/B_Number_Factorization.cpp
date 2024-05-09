/*
* @Author: Zakaria 
* @Date:   2023-01-29 20:38:48
* @Last Modified time: 2023-01-29 22:44:12
*/
#include <bits/stdc++.h>
#define  pb          push_back
#define  f           first
#define  s           second
#define  pi          acos(-1.0)
#define  LCM(a,b)    a*b/__gcd(a,b)
#define  GCD(a,b)    __gcd(a,b)
#define  sof         sizeof
#define  endl        '\n'
#define  eps         1e-6
typedef long long ll;
using namespace std;

const int mod = 1e9+7;
const int N = 2e5+6;

#define sz 31625
bool siv[sz];
vector<long long >primes;

void seive()
{
    long long  limit = sqrt(sz+1);

    for (long long  i=3; i<=limit; i+=2)
        if(!siv[i])
            for (long  j = i*i; j<sz; j+=i+i)
                siv[j] = 1;
    primes.push_back(2);
    for (long long i=3; i<sz; i+=2)
        if(!siv[i]) primes.push_back(i);
}


void Solve()
{

	   
        
       int n;
       cin>>n;

       ll copy = n;

       vector<int>divisor;

       for(auto i:primes)
       {
       	   while(n%i==0)
       	   	divisor.push_back(i), n/=i;
       }

       if(n>1)
       	divisor.push_back(n);

       map<ll, ll>m;

       for(auto i:divisor)
       	m[i]++;
       
       ll ans = 0;

       while(1)
       {
       	   ll temp = 1;
       	   for(auto i:m)
       	   {
       	   	   //cout<<i.f<<" ";
               temp*=i.f;
               m[i.f]--;
       	   }


       	   ll cnt = 0;

       	   while(copy%temp==0)
       	   {
       	   	  cnt++;
       	   	  copy/=temp;
       	   }

       	   ans+=(temp*cnt);

       	   vector<ll>pans;
       	   for(auto i:m)
       	   {
       	   	  if(i.s==0)
       	   	  	pans.push_back(i.f);
       	   }

       	   for(auto i:pans)
       	   	m.erase(i);

       	   if(m.size()==0)
       	   break;
       }

       cout<<ans<<endl;

      
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;
        
        cin>>tt;
        
        seive();

        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 