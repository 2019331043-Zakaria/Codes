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
#define  MAX         1000002 

typedef long long ll;
using namespace std;

int n,m;
vector<int>node[10005];
int vis[10005];
int timer=1;
int in[10005],out[10005];

void dfs(int p)
{
	 vis[p]=1;
	 in[p]=timer++;
	 for(auto i:node[p])
	 {
	 	 if(!vis[i])
	 	 {
	 	 	 dfs(i);
	 	 }
	 }
	 out[p]=timer++;
}

int main()
{
    
      ios::sync_with_stdio(false);
      cin.tie(0); 
      
      cin>>n>>m;
      int a,b;
      for(int i=0;i<m;i++)
      {
      	 cin>>a>>b;
      	 node[a].push_back(b);
      	 node[b].push_back(a);
      }
      
      dfs(1);

      int q;
      
      cin>>q;
      while(q--)
      {
      	 int x,y;
      	 cin>>x>>y;
      	 if(in[x]<in[y] && out[x]>out[y])
      	 {
      	 	 cout<<y<<" lies in subtree "<<x<<endl;
      	 }
      	 else
      	 cout<<y<<" is not lies in subtree "<<x<<endl;

      }

      
      
 
return 0;           
    
              
}
