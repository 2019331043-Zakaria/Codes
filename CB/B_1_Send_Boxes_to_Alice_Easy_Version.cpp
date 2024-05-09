/*
* @Author: Zakaria 
* @Date:   2022-09-08 09:15:03
* @Last Modified time: 2022-09-08 10:37:03
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
#define  MAX         200002
#define  eps         1e-6
typedef long long ll;
using namespace std;

const int N = 1e5+6;
int a[N], cum[N];

vector<int>temp;


ll calc()
{
      

      int mid=temp[temp.size()/2];
      ll res=0;
      for(auto i:temp)
      {
      	  	res+=abs(mid-i);
      }

      return res;

}
ll foo(int x, int n)
{
	 

      int taken=0;
      int last=n+1;
      int cursum=0;
      ll ans=0;
      int box=0;

      for(int i=1 ; i<=n ; i++)
      {
           int value = cum[i] - taken;

           if(value)
           {
           	   
           	   cursum++;
           	   taken++;
           	   temp.push_back(i);
           	   if(cursum==x)
           	   {
           	   	  ans+=calc();
           	   	  cursum=0;
           	   	  temp.clear();
           	   }

           }   
      }



      return ans;

}

void Solve()
{
        
       int n;
       cin>>n;

       int sum=0;

       for(int i=1 ; i<=n ; i++)
       {
       	   cin>>a[i];
       	   sum+=a[i];
       	   cum[i]=sum;
       }

       if(sum==1)
       {
       	  cout<<-1<<endl;
       	  return ;
       }
       
       ll ans=foo(sum, n);

       for(int i=2 ; i*i<=sum ; i++)
       {
             if(sum%i)
             	continue;
             int val=i;
             ans=min(ans, foo(val, n));
             ans=min(ans, foo(sum/i, n));
       }
        
       if(ans!=1e9)
       cout<<ans<<endl;
       else
       	cout<<-1<<endl;
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