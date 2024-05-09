/*
* @Author: Zakaria 
* @Date:   2023-02-19 11:38:15
* @Last Modified time: 2023-02-19 12:01:07
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

int pos1[N], pos2[N];


void Solve()
{
       
       ll n;
       cin>>n;

       for(int i=1 ; i<=n ; i++)
       {
       	  int x;
       	  cin>>x;
       	  pos1[x] = i;
       }        

       for(int i=1 ; i<=n ; i++)
       {
       	  int x;
       	  cin>>x;
       	  pos2[x] = i;
       }

       ll l = 0, r = 0;

       l = min(pos1[1], pos2[1]);
       r = max(pos1[1], pos2[1]);

     

       ll ans = 1;

       ll len = l-1;

       ans+=(len*(len+1))/2;
       len = r - l - 1;
       ans+=(len*(len+1))/2;
       len = n - r;
       ans+=(len*(len+1))/2;

      

       for(int i=2 ; i<=n ; i++)
       {
       	   ll left = min(pos1[i], pos2[i]);
       	   ll right = max(pos2[i], pos1[i]);

       	   ll toleft = left;
       	   ll toright = right;

       	   // cout<<l<<" "<<r<<endl;
       	   // cout<<toleft<<" "<<toright<<endl;
       	   
       	   if(toleft<l && toright>r)
       	   {
       	   	 //  cout<<"here1"<<endl;
               ll temp = (l - toleft) * (toright - r);

             //  cout<<temp<<endl;
               ans+=temp;
       	   }
       	   else if(toright<l)
       	   {
       	   	 //  cout<<"here2"<<endl;
       	   	   ll temp = (l - toright) * (n - r + 1);
       	   	 //  cout<<temp<<endl;
       	   	   ans+=temp;
       	   }
       	   else if(toleft>r)
       	   {
       	   	//   cout<<"here3"<<endl;
       	   	   ll temp = (toleft - r) * (l);
       	   	//   cout<<temp<<endl;
       	   	   ans+=temp;
       	   }

       	   l = min(l, toleft);
       	   r = max(r, toright);
       	//   cout<<ans<<endl;

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