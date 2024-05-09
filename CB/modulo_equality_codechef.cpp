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
       
       test
       {
           
            int n;
            cin>>n;
            ll a[n];

            map<int,int>m;
            bool flag0=0;
            bool flag1=0;
            bool flag2=0;

            ll mn=LLONG_MAX;

            for(int i=0 ;i<n ;i++)
            {
              cin>>a[i];
              mn=min(mn,a[i]);
              if(a[i]==1)
                     flag1=1;
              if(a[i]==0)
                     flag0=1;
              if(a[i]==2)
                     flag2=1;
              m[a[i]]++;
            }

            if(flag0)
              cout<<n-m[0]<<endl;
            else
            {
                bool flag=0;
                for(int i=0 ;i<n; i++)
                {
                     if(a[i]!=mn && a[i]<mn*2+1)
                            flag=1;
                }
                if(flag)
                     cout<<n<<endl;
                else
                     cout<<n-m[mn]<<endl;
            }


            


       }
       
       
       
     
  return 0;  
      
        
}
