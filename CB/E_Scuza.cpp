/*
* @Author: Zakaria 
* @Date:   2022-10-13 21:11:16
* @Last Modified time: 2022-10-13 21:18:01
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

int n,q;

ll cum[N], a[N];

ll cumMAX[N];

int find(ll x)
{
	   int low=1, high=n, mid;
	   int ans=0;

	   while(low<=high)
	   {
	   	   mid=(low+high)/2;

	   	   if(cumMAX[mid]<=x)
            ans=mid, low=mid+1;
           else
           	high=mid-1;
	   }

	   return ans;
}

void Solve()
{
        
       
       cin>>n>>q;

       cum[0]=0;
       ll pans=0;
       for(int i=1 ; i<=n ; i++)
       	cin>>a[i], cum[i]=cum[i-1]+a[i], pans=max(pans, a[i]), cumMAX[i]=pans;
       
       for(int i=1  ; i<=q; i++)
       {
       	   ll x;
       	   cin>>x;
           cout<<cum[find(x)]<<" ";
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