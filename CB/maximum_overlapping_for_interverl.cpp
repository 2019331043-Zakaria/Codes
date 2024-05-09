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
#define  MAX         200050 
#define  sz          100000
typedef long long ll;
using namespace std;

int main()
{
      ios::sync_with_stdio(false);
      cin.tie(0); 
      
      int n;
      cin>>n;
      int x,y;
      vector<pair<int,char> > v;
      int a[n];
      for(int i=0 ;i<n ;i++)
       {
            cin>>x>>y;
            v.push_back({x,'x'}); //left or start 
            v.push_back({y,'y'}); //right or end
            a[i]=x;
       }

       sort(v.begin(), v.end());
      
       int mx=0;
       int cnt=0;
       for(auto i:v)
       {
          if(i.s=='x') // add to cnt
            cnt++;
          else
            cnt--; // end of interval
          mx=max(mx,cnt);
       }

       cout<<mx<<endl;

       
      
            
return 0;           
              
}
