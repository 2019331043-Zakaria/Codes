/*
* @Author: Zakaria 
* @Date:   2022-10-05 20:38:44
* @Last Modified time: 2022-10-05 21:14:44
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
       
       set<int>st;
       
       int mx=INT_MIN;
       for(int i=1 ; i<=n ; i++)
       	cin>>a[i], st.insert(a[i]), mx=max(mx, a[i]);

       if(st.size()!=n)
       {
       	   cout<<-1<<endl;
       	   return ;
       }

       int pos=1;

       for(int i=1 ; i<=n ; i++)
       {
          if(a[i]==mx)
          	pos=i;
       }


       std::vector<int> left, right;

       for(int i=1 ; i<pos ; i++)
       	left.push_back(a[i]);

       for(int i=pos ; i<=n ; i++)
       	right.push_back(a[i]);

       if(left.size() && right.size())
       {
       	  cout<<left.size()<<endl;
       	  for(auto i:left)
       	  	cout<<i<<" ";
       	  cout<<endl;

       	  cout<<right.size()<<endl;
       	  for(auto i:right)
       	  	cout<<i<<" ";
       	  cout<<endl;
       }
       else
       	cout<<-1<<endl;

      
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