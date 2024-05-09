/*
* @Author: Zakaria 
* @Date:   2023-03-25 13:53:03
* @Last Modified time: 2023-03-25 14:08:29
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

char a[105][105];

void Solve()
{
        
      int n, m, k;
      cin>>n>>m>>k;

      int cnt = 0;
      for(int i=1 ; i<=n ; i++)
      {
      	bool ok = i%2;
      	for(int j=1 ; j<=m ; j++)
      	{
      		if(ok == j%2)
      			a[i][j] = '.', cnt++;
      		else
      			a[i][j] = '#';
      	}
      }

     

      if(cnt<k)
      {
      	 cout<<"Impossible"<<endl;
      	 return ;
      }

      for(int i=1 ; i<=n ; i++)
      {
      	for(int j=1 ; j<=m ; j++)
      	{
      		if(!k)
      		{
      			a[i][j] = '#';
      			continue;
      		}

      		if(a[i][j]=='.')
      			k--;
      	}
      }

      for(int i=1 ; i<=n ; i++)
      {
      	for(int j=1 ; j<=m ; j++)
      		cout<<a[i][j];
      	cout<<endl;
      }
      
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        // freopen("kotlin.in", "r", stdin);
        // freopen("kotlin.out", "w", stdout);
        
        int tt=1;
        
        //cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 