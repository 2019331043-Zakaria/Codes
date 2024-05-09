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
#define  MAX         300005 
#define  sz          100000
typedef long long ll;
using namespace std;


int main()
{ 
           ios::sync_with_stdio(false);
           cin.tie(0); 

           //https://stackoverflow.com/questions/46296588/distinct-n-numbers-so-that-sum-equals-to-n
            
            int n,N;
            cin>>n>>N;

           
            int sum=N-(n*(n+1))/2;

            
            bool flag=true;

            if(sum<0)
             flag=false;

            int res[n];

            for(int i=0;i<n;i++)
            {

                res[i]=i+1+sum/n;
            }     

           
            int x=sum%n;
            
            for(int i=n-1; i>=0 ;i--) //if x then add from the last
            {
               if(x)
               {
                 res[i]++;
                 x--;
               }
            }

            for(int i=0;i<n;i++)
              cout<<res[i]<<" ";

      
            
       
      
return 0;           
              
}
