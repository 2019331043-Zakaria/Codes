/*
* @Author: Zakaria 
* @Date:   2022-11-21 21:18:01
* @Last Modified time: 2022-11-21 22:03:30
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
        
       ll n, c, d;
       cin>>n>>c>>d;
       ll a[n+1];

       ll sum = 0;

       for(int i=1 ; i<=n ; i++)
       	cin>>a[i];

       sort(a+1, a+n+1);

       reverse(a+1, a+n+1);

       for(int i=1 ; i<=min(d, n) ; i++)
         sum+=a[i];

       if(sum>=c)
       {
       	  cout<<"Infinity"<<endl;
       	  return ;
       }

       if(a[1]*d<c)
       {
       	  cout<<"Impossible"<<endl;
       	  return ;
       }

       int low = 0, high = d;
       int mid;

       int ans = 0;

       while(low<=high)
       {
       	   mid = (low+high)/2;

       	   ll sum = 0;
       	   int m[d+1];

       	   for(int i=1 ; i<=d ; i++)
       	   	m[i] = 0;

       	   for(int i=1 ; i<=n ; i++)
       	   {
       	   	   if(m[i])
       	   	   	break;
               int temp = i;
               while(temp<=d)
               	sum+=a[i], m[temp] = 1, temp+=(mid+1) ;
       	   }

       	   if(sum>=c)
       	   {
       	   	  ans = mid;
       	   	  low = mid+1;
       	   }
       	   else
       	   	  high = mid - 1;
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