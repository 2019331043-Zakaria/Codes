     
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

int main()
{
      
      ios::sync_with_stdio(false);
      cin.tie(0);
      
     
         int n;
         cin>>n;
         ll ans=0,x;
         map<ll,ll>m;
         ll a[n];

         for(int i=1;i<=n;i++)
         {
            cin>>a[i];
            ans+=(m[a[i]]*(n-i+1));
            m[a[i]]+=i;
         }

         cout<<ans<<endl;
     
       

      
return 0;
          
}