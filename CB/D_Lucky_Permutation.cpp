#include <bits/stdc++.h>
#define  pb          push_back
#define  f           first
#define  s           second
#define  pi          acos(-1.0)
#define  LCM(a,b)    a*b/__gcd(a,b)
#define  GCD(a,b)    __gcd(a,b)
#define  sof         sizeof
#define  endl        '\n'
#define  eps         1e-6
typedef long long ll;
using namespace std;

const int mod = 1e9+7;
const int N = 2e5+6;

int n;
int parent[N],Rank[N];

void init(int n)
{
          for(int i=1 ;i<=n ;i++)
            Rank[i]=1,parent[i]=i;
}

int find_parent(int v) {
    if (v == parent[v]) {
        return v;
        }
    return parent[v] = find_parent(parent[v]);
}
 
void union_sets(int a, int b) {
    a = find_parent(a);
    b = find_parent(b);
    if (a != b) {
        if (Rank[a] > Rank[b]) {
            swap (a, b);
                }
        parent[a] = b;
        Rank[b] += Rank[a];
    }
}

void Solve()
{
        
       cin>>n;

       init(n);

       int a[n+1];

       for(int i=1 ; i<=n ; i++)
       {
       	  cin>>a[i];

       	  union_sets(i, a[i]);
       }
       
       map<int, int>m;

       int tot = 0;

       for(int i=1 ; i<=n ; i++)
       {
       	   int par = find_parent(i);
       	   if(m[par])
       	   	continue;
       	   tot+=Rank[par]-1;
       	   m[par] = 1;
       }

      
       int ans = n+5;

       for(int i=1 ; i<n ; i++)
       {
       	  if(find_parent(i) == find_parent(i+1))
       	  {
             ans = min(ans, tot-1);
       	  }
       	  else
       	  {
       	  	 ans = min(ans, tot+1);
       	  }
       }

       cout<<ans<<endl;
      
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;
        
        cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 