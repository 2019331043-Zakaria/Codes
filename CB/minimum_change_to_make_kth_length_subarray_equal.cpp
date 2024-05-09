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
      
           ll n,k;
           cin>>n>>k;
           ll a[n];
           vector<int>v[n+1];
           for(int i=0;i<n;i++)
            {
              cin>>a[i];
              v[i%k].push_back(a[i]);
            }
            ll ans=0;
            for(int i=0;i<k;i++)
            {
               map<int,int>temp;
               int pans=0;
               for(auto j:v[i])
               {
                   temp[j]++;
                   pans=max(pans,temp[j]);
               }
               ans+=(v[i].size()-pans);
            }

            cout<<ans<<endl;


      
      

     return 0;
}