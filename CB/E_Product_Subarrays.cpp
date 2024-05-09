/*
* @Author: Zakaria 
* @Date:   2022-12-30 00:09:16
* @Last Modified time: 2022-12-30 00:17:52
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

      int a[n+1];
      
      vector<int>neg, pos;

      for(int i=1 ; i<=n ; i++)
      {
      	 cin>>a[i];
      	 if(a[i]<0)
      	 	neg.push_back(i);
      	 if(a[i]>i)
      	 	pos.push_back(i);

      	 if(a[i]>0)
      	 	a[i] = 1;
      	 if(a[i]<0)
      	 	a[i] = -1;

      }

      for(int i=1 ; i<=n ; i++)
      	cout<<a[i]<<" ";
      cout<<endl;

      int zero[n+1];
      int temp = n+1;
      for(int i=n ; i>=1 ; i--)
      {
      	 if(a[i]==0)
      	 	temp = i;
      	 zero[i] = temp;
      }
      
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