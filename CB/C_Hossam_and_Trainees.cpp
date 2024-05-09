/*
* @Author: Zakaria 
* @Date:   2022-12-11 22:03:27
* @Last Modified time: 2022-12-11 23:14:24
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

vector<int> primes;

set<int> fact(int n) {

    set<int> factorization;
    
    for (long long d : primes) {
        if (d * d > n)
            break;
        while (n % d == 0) {
            factorization.insert(d);
            n /= d;
        }
    }
    if (n > 1)
        factorization.insert(n);
    return factorization;
}


#define sz 31625
bool siv[sz];
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

       ll a[n+1];

       set<ll>st;


       for(int i=1 ; i<=n ; i++)
       	cin>>a[i];
       
       map<ll, ll>m;


       for(int i=1 ; i<=n ; i++)
       {
       	   set<int>st;

       	   st = fact(a[i]);

       	   for(auto i:st)
       	   {
       	   	  if(m[i])
       	   	  {
       	   	  	 cout<<"YES"<<endl;
       	   	  	 return ;
       	   	  }
       	   	  m[i]++;
       	   }
       }

       cout<<"NO";

       cout<<endl;

       
     
       
      
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        seive();

        int tt=1;
        
        cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 