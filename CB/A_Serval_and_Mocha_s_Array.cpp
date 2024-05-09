/*
* @Author: Zakaria 
* @Date:   2023-02-25 20:20:21
* @Last Modified time: 2023-02-25 20:26:38
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
        
      int n;
      cin>>n;

      int G = 0;

      int a[n];

      for(int i=0 ; i<n ; i++)
      {
      	  int x;
      	  cin>>x;
      	  a[i] = x;
      	  G = GCD(G, x);
      }

      if(G<=2)
      {
      	  for(int i=0 ; i<n ; i++)
      	  {
      	  	 for(int j=i+1 ; j<n ; j++)
      	  	 {
      	  	 	if(GCD(a[i], a[j])<=2)
      	  	 	{
      	  	 		cout<<"YES"<<endl;
      	  	 		return ;
      	  	 	}
      	  	 }
      	  }

      	  cout<<"NO"<<endl;
      }
      else
      	cout<<"NO"<<endl;
      
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