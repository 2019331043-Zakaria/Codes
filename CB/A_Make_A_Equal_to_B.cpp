/*
* @Author: Zakaria 
* @Date:   2022-10-10 20:36:08
* @Last Modified time: 2022-10-10 20:42:36
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

         int a[n];

         for(int i=0 ; i<n ; i++)
         	cin>>a[i];

         int b[n];
         
         int one=0, zero=0;
         for(int i=0 ; i<n ; i++)
         {
         	cin>>b[i];
         	if(b[i]==1)
         		one++;
         	else
         		zero++;
         }

         bool ok=0;

         for(int i=0 ; i<n ; i++)
         {
         	if(a[i]!=b[i])
         		ok=1;
         }

         if(ok==0)
         {
         	cout<<0<<endl;
         	return ;
         }

         int temp1=0;
         int temp0=0;

         for(auto i:a)
         {
         	if(i==1)
         		temp1++;
         	else
         		temp0++;
         }

         if(temp1==one && temp0==zero)
         {
         	cout<<1<<endl;
         	return ;
         }

         int ans=0;

         for(int i=0 ; i<n ; i++)
         {
         	if(a[i]!=b[i])
         		ans++;
         }

         cout<<min(ans, 1+min(abs(temp1-one), abs(temp0-zero)))<<endl;
      
      
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