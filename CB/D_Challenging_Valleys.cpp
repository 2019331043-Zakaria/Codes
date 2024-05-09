/*
* @Author: Zakaria 
* @Date:   2022-11-21 21:03:10
* @Last Modified time: 2022-11-21 21:12:36
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

       for(int i=1 ; i<=n ; i++)
       	cin>>a[i];

       vector<int>v;
       v.push_back(a[1]);
       for(int i=2 ; i<=n ; i++)
       {
       	  if(a[i]==v.back())
       	  	continue;
       	  v.push_back(a[i]);
       }

       if(v.size()<=2)
       {
       	 cout<<"YES"<<endl;
       	 return ;
       }

       int pans = 0;

       if(v.back()<v[v.size()-2])
       {
       	  pans++;
       }

       if(v[0]<v[1])
       {
       	  pans++;
       }
       
    


       for(int i=1 ; i<v.size()-1 ; i++)
       {
       	  if(v[i]<v[i-1] && v[i]<v[i+1])
       	  {
       	  	  pans++;
       	  }
       }
       if(pans==1)
       cout<<"YES"<<endl;
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