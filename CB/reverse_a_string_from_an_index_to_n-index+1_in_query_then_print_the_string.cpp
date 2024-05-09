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
      
       string s;
       cin>>s;

       int k;
       cin>>k;
       
       int n = s.size();
       s='*'+s;

       int vis[n+1];
       
       vector<int>v(k);

       memset(vis,0,sizeof(vis));

       for(int i=0 ; i<k ;i++)
            cin>> v[i],vis[v[i]]++;

       int rep[n+1];
       memset(rep,0,sizeof(rep));

       for(int i=1; i<=n ;i++)
       {
         rep[i]+=rep[i-1];
         rep[i]+=vis[i];
       }
     

       for(int i=1; i<=n/2; i++)
          if(rep[i]%2)
            swap(s[i],s[n-i+1]);
       
      
       s.erase(s.begin());

       cout<<s<<endl;


     





     
            
return 0;           
              
}