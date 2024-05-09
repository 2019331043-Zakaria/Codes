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
#define  mod         1000000007
#define  test        int t; cin>>t ;while(t--)
#define  sof         sizeof
#define  endl        '\n'
typedef long long ll;
using namespace std;
vector<pair<ll,ll> > v;

bool Check(ll x)
{
     ll sum=0;
     for(auto i:v)
     {
        if(i.f>x)
          sum+=i.s;
     }

     return sum<=x;
}

int main()
{

      ios::sync_with_stdio(false);
      cin.tie(0); 
      
     
      test
      {
           int n;
           cin>>n;
           
           ll a[n],b[n];
           v.clear();

           for(int i=0; i<n; i++)
           {
             cin>>a[i];
           }
            for(int i=0; i<n; i++)
           {
             cin>>b[i];

             v.push_back({a[i],b[i]});
           }


          ll low=0,high=1e9+7;
          
          ll ans;

          ll mid;
          

          while(low<high)
          {
              mid=(low+high)/2;
              if(Check(mid))
              {
                 ans=mid;
                 high=mid;
              }
              else
              {
                 low=mid+1;
              }
          }

          cout<<ans<<endl;
      }
      

  return 0;  
      
        
}

