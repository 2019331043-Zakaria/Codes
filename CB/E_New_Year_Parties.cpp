/*
* @Author: Zakaria 
* @Date:   2022-12-07 22:58:34
* @Last Modified time: 2022-12-08 00:55:08
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

int a[N];
int vis[N], visited[N];
set<int>st;
map<int, int>m;
int n;


void Solve()
{
        
      cin>>n;

      for(int i=1 ; i<=n ; i++)
      	cin>>a[i], st.insert(a[i]), m[a[i]]++;
    
      
      

      int mx = 0;

      for(int i=0 ; i<=n+1 ; i++)
      {
      	 if(m[i-1])
      	 {
      	 	mx++;
      	 	m[i-1]--;
      	 }
      	 else if(m[i])
      	 {
      	 	mx++;
      	 	m[i]--;
      	 }
      	 else if(m[i+1])
      	 {
      	 	mx++;
      	 	m[i+1]--;
      	 }
      }

      m.clear();
      for(int i=1 ; i<=n ; i++)
      	m[a[i]]++;



      int mn = 0;

      for(int i=1 ; i<=n ; )
      {
           if(m[i])
           	mn++, i+=3;
           else
           	i++;
      }
      
      cout<<mn<<" "<<mx<<endl;

      


      
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;
        
     //   cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 