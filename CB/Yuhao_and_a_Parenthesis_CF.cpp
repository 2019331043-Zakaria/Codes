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
      string s[n];

      for(int i=0; i<n; i++)
        cin>>s[i];

     
      map<pair<int,int>, int> equal;
      vector<int>left_lagbe, right_lagbe;

      int l=0,r=0;

      for(int i=0;i<n;i++)
      {

           string temp=s[i];
           l=0;r=0;
           for(auto j:temp)
           {
              if(j=='(')
                l++;
              else if(j==')')
              {
                  if(l>0)
                    l--;
                  else
                   r++;
              }
           }

           left_lagbe.push_back(r);
           right_lagbe.push_back(l);
           if(l==0 && r==0)
            equal[{0,0}]++;
           else if(l==0 && r)
            equal[{r,0}]++;
           else if(r==0 && l)
            equal[{0, l}]++;
     
      }

        
       int ans=0;
       int x=0,y=0;
       for(int i=0; i<n ;i++)
       {
          x=left_lagbe[i];
          y=right_lagbe[i];
          
        
          if(x && y)
            continue;
          else if(x==0 && y==0)
          {
              if(equal[{0,0}]>=2)
              {
                 ans++;
                 equal[{0,0}]--;
                 equal[{0,0}]--;
              }
          }
          else if(x && !y)
          {
             if(equal[{x,0}]>=1 && equal[{0,x}]>=1)
             {
               ans++;
               equal[{x,0}]--;
               equal[{0,x}]--;
             }
          }
          else if(y && !x)
          {
              if(equal[{y,0}]>=1 && equal[{0,y}]>=1)
             {
               ans++;
               equal[{y,0}]--;
               equal[{0,y}]--;
             }
          }
         
      //   cout<<ans<<endl;

       }

       cout<<ans<<endl;
      
     
    
  return 0;  
      
      
        
}

