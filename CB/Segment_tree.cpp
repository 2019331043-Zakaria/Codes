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
#define  MAX         100002 
#define  sz          100000
typedef long long ll;
using namespace std;

int a[MAX];
int tree[MAX*4];

void init(int node, int b, int e)
{
	  
	   if(b==e)
	   {
	   	  tree[node]=a[b];
	   	  return ;
	   }

	   int left=2*node;
	   int right=left+1;

	   int mid=(b+e)/2;

	   init(left, b, mid);
	   init(right, mid+1, e);

	   tree[node]=tree[left]+tree[right];
}

int query(int node, int b, int e, int i, int j)
{
	  if(i>e || j<b)
	  	return 0;
	  if(b>=i && e<=j)
	  	return tree[node];

	  int left=node*2;
	  int right=node*2 +1;

	  int mid=(b+e)/2;

	  int p1=query(left,  b,  mid, i, j);
	  int p2=query(right , mid+1, e, i, j);

	  return p1+p2;

}

void update(int node ,  int b, int e, int i, int newvalue)
{
    if(i>e || i<b)
    	return ;
    if(e==b && e==i)
    {
    	tree[node]=newvalue;
    	return ;
    }

    int left=2*node;
    int right=left+1;

    int mid=(e+b)/2;

    update(left, b, mid, i, newvalue);
    update(right, mid+1, e, i, newvalue);

    tree[node]=tree[left]+tree[right];


}

int main()
{
      ios::sync_with_stdio(false);
      cin.tie(0); 
       
      int n;
      cin>>n;

      for(int i=1;i<=n;i++)
      	cin>>a[i];

      init(1,1,n);
      
      cout<<query(1 ,1 , n, 1 , n );
      cout<<endl;
      update(1, 1, n, 3, 5);
      cout<<query(1, 1, n, 1, n );

             
return 0;           
              
}
