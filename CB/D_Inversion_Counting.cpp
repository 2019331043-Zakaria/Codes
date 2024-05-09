/*
* @Author: Zakaria 
* @Date:   2022-12-08 22:04:14
* @Last Modified time: 2022-12-08 23:06:31
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

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree< int , null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key


const int mod = 1e9+7;
const int N = 2e5+6;

int n;
ll a[N];

void Solve()
{
        
      cin>>n;

      int Parity = 0;

      pbds st;

      for(int i=1 ; i<=n ; i++)
      {
      	 cin>>a[i];
      	 Parity^=(st.order_of_key(-a[i])&1);
      	 st.insert(-a[i]);
      }

      int q;
      cin>>q;

      while(q--)
      {
      	int l, r;
      	cin>>l>>r;
      	
      	ll temp = r - l + 1;
      	
      	temp = (temp*(temp-1))/2;  

        Parity^=(temp&1);

        if(Parity)
        	cout<<"odd"<<endl;
        else
        	cout<<"even"<<endl;
      }




      
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;
        
        //cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 