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

vector<int>node[N];

void Solve()
{
        
       int n, m;
       cin>>n>>m;

       map<vector<pair<int, int> > , int>vis;

       for(int i=1 ; i<=n ; i++)
       {
       	   vector<int>v;

       	   for(int j = 0 ;j<m ; j++)
       	   {
       	   	  int x;
       	   	  cin>>x;
       	   	  v.push_back(x);
       	   }

       	   node[i] = v;

       	   vector<pair<int, int> > temp;

       	   for(int j=0 ; j<m ; j++)
       	   {
       	   	  temp.push_back({v[j], j+1});
       	   	  
       	   	 /* for(auto i:temp)
       	   	  	cout<<i.f<<" "<<i.s<<endl;
       	   	  cout<<endl;*/
       	   	 
       	   }

       	   sort(temp.begin(), temp.end());
       	   while(temp.size())
       	   	vis[temp] = 1, temp.pop_back();

       	 
       }

       for(int i=1 ; i<=n ; i++)
       {
       	  vector<int>v;
       	  v = node[i];

       	  vector<pair<int, int> > temp;
       	  for(int j=0 ; j<m ; j++)
       	  	temp.push_back({j+1, v[j]});

       	  

       	  bool ok = 0;
       	  while(temp.size())
       	  {
       	  	 /* for(auto i:temp)
       	  	  	cout<<i.f<<" "<<i.s<<endl;

       	  	  cout<<endl;*/
       	  	  if(vis[temp])
       	  	  {
       	  	  	 ok = 1;
       	  	  	 cout<<temp.size()<<" ";
       	  	  	 break;
       	  	  }

       	  	  temp.pop_back();
       	  	  sort(temp.begin(), temp.end());
       	  }

       	  if(ok==0)
       	  	cout<<0<<" ";
       }
       cout<<endl;


      
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