/*
* @Author: Zakaria 
* @Date:   2023-01-05 20:42:02
* @Last Modified time: 2023-01-05 20:47:43
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
        
       int n, k;
       cin>>n>>k;

       map<int, int>pos;

       for(int i=1 ; i<=n ; i++)
       {
       	  int x;
       	  cin>>x;
       	  pos[x] = i;
       }

       int last = -1;

       int temp = 0;

       for(int i=1 ; i<=n ; i++)
       {
       	  if(pos[i]>last)
       	  {
       	  	 temp++;
       	  	 last = pos[i];
       	  }
       	  else
       	  	break;
       }

       int rem = n - temp;

       cout<<(rem+k-1)/k<<endl;
      
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