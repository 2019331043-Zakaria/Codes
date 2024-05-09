/*
* @Author: Zakaria 
* @Date:   2022-09-04 15:51:09
* @Last Modified time: 2022-09-04 16:27:15
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
#define  MAX         200002
#define  eps         1e-6
typedef long long ll;
using namespace std;

#define sz 10000010
bool siv[sz];
vector<long long >primes;
bool ok[sz];

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
        seive();
        
        for(auto i:primes)
         ok[i]=1;

        int n;
        cin>>n;

        ll a[n];
        vector<int>one, two;
        for(int i=0 ; i<n ; i++)
        {
             cin>>a[i];
             if(a[i]==1)
             one.push_back(1);
        }
        
        if(one.size()>=2)
        {
             for(auto i:a)
             {
                  if(i!=1)
                  {
                     if(ok[i+1])
                     {
                          one.push_back(i);
                          break;
                     }
                  }
             }

             cout<<one.size()<<endl;
             for(auto i:one)
             cout<<i<<" ";
             cout<<endl;
             return ;
        }

        for(int i=0 ; i<n ; i++)
        {
              for(int j=0 ; j<i ; j++)
              {
                 if(ok[a[i]+a[j]])
                 {
                     cout<<2<<endl;
                     cout<<a[i]<<" "<<a[j]<<endl;
                     return ;
                 }
              }
        }

       
        cout<<1<<endl;
        cout<<a[0]<<endl;

       
      
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;
        
       // cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 