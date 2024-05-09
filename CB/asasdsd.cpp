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
#include <iomanip>
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
#define  mod         998244353
#define  sof         sizeof
#define  endl        '\n'
#define  MAX         2000002 

typedef long long ll;
using namespace std;


int main()
{
    
      ios::sync_with_stdio(false);
      cin.tie(0); 
      


      int n;
      cin>>n;
      
      ll x,y;
      cin>>x>>y;

      ll ans=min(x,y)+1;
      ll last=ans;
      n--;
     
      ll a,b;
      while(n--)
      {

          cin>>a>>b;
          swap(y,a);
          if(y<a || b<x)
            ans;
          else
          {
               ll temp=min(y,b);
               ll pans=max(x,a);
               pans=max(pans,last);
            
               if(pans>temp)
                    ans;
               else 
               {
                    ans+=(temp-pans+1);
                    last=temp+1;
               }
          }
          
          x=y,y=b;

      }
        
        cout<<ans<<endl;
      
    
return 0;           
              
}
