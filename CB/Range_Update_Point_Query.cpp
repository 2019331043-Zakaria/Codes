/*
* @Author: Zakaria 
* @Date:   2023-02-03 20:42:46
* @Last Modified time: 2023-02-04 01:51:14
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


int cal(int x)
{
	 int sum = 0;
	 while(x)
	 	sum+=x%10, x/=10;
	 return sum;
}

void Solve()
{
        
       int n , q;
       cin>>n>>q;

       set<int>st;

       int a[n+1];

       int pos[n+5];

       for(int i=1 ; i<=n ; i++)
       {
       	  cin>>a[i];
       	  st.insert(i);
       	  pos[i] = a[i];
       }


       while(q--)
       {
       	   int type;
       	   cin>>type;

       	   if(type==1)
       	   {
       	   	  int l, r;
       	   	  cin>>l>>r;
       	   	  
       	   	  auto it = st.lower_bound(l-1);
       	   	  
       	   	  vector<int>temp;

       	   	  while( it != st.end() && *it<=r)
       	   	  {

       	   	  	if(*it>=l && *it<=r)
       	   	  	{
       	   	  		  int index = *it;
       	   	  	 	  int val = pos[index];
 
       	   	  	 	  int sod = cal(val);
 
       	   	  	 	 
       	   	  	 	  pos[index] = sod;
 
       	   	  	 	  if(sod<10)
       	   	  	 	  temp.push_back(index);

       	   	  	}

       	   	  	it++;

       	   	  }
       	   	  for(auto i:temp)
       	   	  	st.erase(i);
       	   }
       	   else
       	   {
       	   	  int index;
       	   	  cin>>index;
       	   	 
       	   	  cout<<pos[index]<<endl;
       	   }
       }



      
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