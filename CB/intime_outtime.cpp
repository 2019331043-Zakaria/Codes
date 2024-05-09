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
#include <iomanip>
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

vector<int>node[100];
int visit[100],out_time[100],in_time[100];
int timer;
void dfs(int x)
{
      visit[x]=1;
      in_time[x]=++timer;
      for(auto i:node[x])
      {
            if(!visit[i])
            {
                  dfs(i);
            }
      }
      out_time[x]=++timer;
     
}


int main()
{
     
      ios::sync_with_stdio(false);
      cin.tie(0); 
      
      int n,m;
      cin>>n>>m;

      int a,b;
      while(m--)
      {
            cin>>a>>b;
            node[a].push_back(b);
      }

      dfs(1);
      for(int i=1 ;i<=8 ;i++)
            cout<<out_time[i]<<" ";
      

     

return 0;           
              
}

