/*
* @Author: Zakaria 
* @Date:   2022-10-15 12:06:22
* @Last Modified time: 2022-10-15 12:32:44
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
        
       int n, x;
       cin>>n>>x;

       int a[n+1];
       int pos;

       for(int i=1 ; i<=n ; i++)
       {
       	   cin>>a[i];
       	   if(a[i]==x)
       	   	pos=i;
       }



       
       int great = 0 , less =0;
       map<int, int >m;

       for(int i=pos ; i<=n ; i++)
       {
       		if(a[i]>x)
       			great++;
       		else if(a[i]<x)
       			less++;
       		m[great - less]++;
       }
       
       great=0,less=0;
       ll ans = 0;
       for(int i=pos ; i>=1 ; i--)
       {
       		if(a[i]>x)
       			great++;
       		else if(a[i]<x)
       			less++;
            
            int temp = less - great ;

            ans+=m[temp];
            ans+=m[temp+1];
       		 		
       }

       cout<<ans<<endl;
      
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