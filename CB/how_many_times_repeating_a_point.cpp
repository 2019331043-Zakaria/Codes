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
#define  MAX         2000002 

typedef long long ll;
using namespace std;

ll a[MAX];
ll res[MAX],start[MAX],stop[MAX];
int cnt;

int main()
{

         ios::sync_with_stdio(false);
         cin.tie(0);
         
         int n,m;
         cin>>n>>m;
         
         for(int i=1; i<=n; i++)
            cin>>a[i];
         
         int x,y;

         for(int i=1; i<=m; i++)
         {
             cin>>x>>y;
             start[x]++;
             stop[y]++;
         }
         vector<ll> v;


         for(int i=1; i<=n ; i++)
          {
             cnt+=start[i];
             v.push_back(cnt); //cnt = ith segment repeat;
            
             cnt-=stop[i];
          }
         
          
          
         
        
          
     return 0;


}
