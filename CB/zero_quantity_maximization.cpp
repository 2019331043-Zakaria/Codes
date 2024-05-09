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

map<pair<int,int>, int > pos, neg;
map<int,int>m;
int ans,temp;

int main()
{
     // given two array a and b find a choose a real number C , such that x=c*a[i]+b[i],where x=0;
      ios::sync_with_stdio(false);
      cin.tie(0); 
      
      int n;
      cin>>n;
      int a[n],b[n];
      for(int i=0 ;i<n ;i++)
            cin>>a[i];

      for(int i=0 ;i<n ;i++)
       {
            cin>>b[i];
            if(a[i]==0 && b[i]==0)
                  temp++;
       }
      

      for(int i=0 ;i<n;i++)
      {
         if(a[i])
         {
            if((a[i]>0 && b[i]>0) or (a[i]<0 && b[i]<0))
            {
                int G=__gcd(abs(a[i]),abs(b[i]));
                pos[{abs(a[i])/G,abs(b[i])/G}]++;
            }
            else
            {
                a[i]=abs(a[i]);
                b[i]=abs(b[i]);
                int G=__gcd(a[i],b[i]);
                neg[{a[i]/G,b[i]/G}]++;
            }
         }
      }

      for(auto i:pos)
            ans=max(ans,i.s);
      for(auto i:neg)
            ans=max(ans,i.s);

      cout<<ans+temp<<endl;
     

      
            
return 0;           
              
}
