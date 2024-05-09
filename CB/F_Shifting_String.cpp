/*
* @Author: Zakaria 
* @Date:   2023-01-01 11:17:10
* @Last Modified time: 2023-01-01 11:36:46
*/
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

int n,m;
int parent[N],Rank[N];
int p[N];
string s;
vector<int>node[N];

void init(int n)
{
          for(int i=1 ;i<=n ;i++)
            Rank[i]=1, parent[i]=i, node[i].clear();
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

ll foo(int index)
{
	string pans = s;
	vector<int>temp = node[index];
    int cnt = 0;

    do{

    	string news = pans;

    	for(auto i:temp)
    	{
    		pans[i] = news[p[i]];
    	}
    	
    	//pans = news;
    	news = pans;
    	cnt++;

    }while(pans!=s);

    return cnt;	
}


void Solve()
{
        
       cin>>n;
       cin>>s;

       s = '*' + s;

       init(n);

       for(int i = 1 ; i<=n ; i++)
       	cin>>p[i], union_sets(i, p[i]);


       for(int i = 1 ; i<=n ; i++)
       	node[find_parent(i)].push_back(i);

       ll ans = 1;

       for(int i=1 ; i<=n ; i++)
       {
       	  if(node[i].size()==0)
       	  	continue;
          ans = LCM(ans, foo(i));
       	  
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