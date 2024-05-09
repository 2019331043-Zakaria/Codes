#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <climits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <complex>
#include <cstring>

#define  pb          push_back
#define  f           first
#define  s           second
#define  pi          acos(-1.0)
#define  LCM(a,b)    a*b/__gcd(a,b)
#define  GCD(a,b)    __gcd(a,b)
#define  test        int t; cin>>t ;while(t--)
#define  sof         sizeof
#define  endl        '\n'
#define  MAX         1000002 

const long long mod = 1e9+7;
typedef long long ll;
using namespace std;


ll dp_hash[MAX];
ll inverse[MAX];
ll sum;

ll bigmod(ll p,ll n) //p^n
{    
    ll res=1;

     while(n)
     {
        if(n&1)
          res=(res*p)%mod;
          n >>= 1;// n/=2

          p=(p*p)%mod;

     }

     return res;
}

void hashing(string s)
{
     ll n=s.size();
     ll temp=31;
     ll pow=1;
      
     dp_hash[0]=s[0]-'a'+1;
     inverse[0]=1;
   
     for(int i=1; i<n ;i++)
     {  
        pow=(pow*temp)%mod;

        inverse[i]=bigmod(pow,mod-2) ;

        dp_hash[i]=(dp_hash[i-1]+((s[i]-'a'+1)*pow)%mod ) % mod;

     }
}

void counting(string t)
{
         sum=t[0]-'a'+1;
         ll p=31;
         ll pow=1;
         
         for(int i=1;i<t.size() ;i++)
         {   
             pow=(pow*p)%mod;

             sum=(sum+ (t[i]-'a'+1)*pow ) % mod;      
         }
}

bool hash_value(int l , int r)
{
    ll res=dp_hash[r];
 
    if(l>0) res-=dp_hash[l-1];
    if(res<0)
      res+=mod;

    res=(res*inverse[l])%mod;

   

    if(res==sum)
      return 1;

    return 0;

}

int main()
{
         
      ios::sync_with_stdio(false);
      cin.tie(0); 
     int k=0;
     test
     {    
         
        
         memset(dp_hash,0,sizeof(dp_hash));
         memset(inverse,0,sizeof(inverse));
         string s,t;
         cin>>s>>t;
         
         hashing(s);
       
         counting(t);

        

         int l=0,r=t.size()-1;
         
         ll count=0;

         while(r<s.size())
         {
            count+=hash_value(l,r);
            ++r;
            ++l;
         }

         cout<<"Case "<<++k<<": "<<count<<endl;



        
      
     }

    return 0;           
    
              
}

