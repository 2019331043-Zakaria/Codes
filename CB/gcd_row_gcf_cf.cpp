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
       
       int n,m;
       cin>>n>>m;

       ll a[n],b[m];
       for(int i=0; i<n; i++)
              cin>>a[i];
       for(int i=0; i<m; i++)
              cin>>b[i];

       ll temp=0;

       for(int i=1; i<n; i++)
       {
           temp=abs(GCD(temp,a[i]-a[i-1]));
       }
       
       for(int i=0 ; i<m; i++)
       cout<<GCD(a[n-1]+b[i],temp)<<" ";
       
       
       //the logic is gcd(x,y)=gcd(x-y,y);
       //so gcd(A1+x,A2+x,...,An+x)=gcd()
     
  return 0;  
      
        
}
