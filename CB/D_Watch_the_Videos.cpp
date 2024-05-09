/*
* @Author: Zakaria 
* @Date:   2022-12-31 15:01:35
* @Last Modified time: 2022-12-31 15:08:35
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
        
       int n,m;
       cin>>n>>m;

       int a[n];
       ll sum = 0;

       for(int i=0 ; i<n ; i++)
       	cin>>a[i], sum+=a[i];

       sort(a, a+n);

       int temp = 1;
       int l = 0, r = n-1;

       while(l<r)
       {
           if(a[l]+a[r]<=m)
           {
           	  l++;
           	  r--;
           }
           else
           {
           	  temp++;
           	  r--;
           }
       }

       cout<<sum+temp<<endl;

      
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;
        
      //  cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 