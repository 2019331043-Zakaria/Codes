/*
* @Author: Zakaria 
* @Date:   2023-03-19 18:09:11
* @Last Modified time: 2023-03-19 18:13:13
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
       
       int n, m;
       cin>>n>>m;

       int a[n];

       for(int i=0 ; i<n ; i++)
       cin>>a[i];


       int b[m];

       for(int i=0 ; i<m ; i++)
       cin>>b[i];


       vector<int>v;

       int i = 0, j = 0;
       map<int, int>ansa, ansb;

       while(i<n && j<m)
       {
       	  if(a[i]<b[j])
       	  	ansa[i] = v.size()+1, v.push_back(a[i]), i++;
       	  else
       	  	ansb[j] = v.size()+1, v.push_back(b[j]), j++;
       } 

       while(i<n)
       {
       	  ansa[i] = v.size()+1;
       	  v.push_back(a[i]);
       	  i++;
       }

       while(j<m)
       {
       	  ansb[j] = v.size()+1;
       	  v.push_back(a[j]);
       	  j++;
       }

       for(int i=1 ; i<=n ; i++)
       	cout<<ansa[i-1]<<" ";
       cout<<endl;

       for(int i=0 ; i<m ; i++)
       	cout<<ansb[i]<<" ";
       cout<<endl;
      
      
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;
        
     //   cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 