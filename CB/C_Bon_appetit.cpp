/*
* @Author: Zakaria 
* @Date:   2023-01-25 20:47:01
* @Last Modified time: 2023-01-25 21:11:28
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

void Solve()
{
        
      int n, m;
      cin>>n>>m;

      int a[n];

      map<int, int>cnt;

      for(int i=0 ; i<n ; i++)
      {
      	  cin>>a[i];
      	  cnt[a[i]]++;
      }

      priority_queue<int>people;

      for(auto i:cnt)
      	people.push(i.s);

      vector<int>table;

      for(int i=0 ; i<m ; i++)
      {
      	 int x;
      	 cin>>x;
      	 table.push_back(x);
      }

      sort(table.rbegin(), table.rend());
 
     

      ll ans = 0;

      for(auto i:table)
      {
      	
      	  if(people.size()==0)
      	  {
      	  	 break;
      	  }
      	  int val = people.top();
      	  people.pop();
      	  ans+=min(i, val);
      	  val-=min(i, val);
      	  if(val)
      	   people.push(val);
      }

      cout<<ans<<endl;
  //    cout<<endl;
      
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