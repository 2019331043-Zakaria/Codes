/*
* @Author: Zakaria 
* @Date:   2023-01-05 15:07:27
* @Last Modified time: 2023-01-05 15:23:53
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

       string s;
       cin>>s;

       vector<int>black, white;
       
       s = '*' + s;

       for(int i=1 ; i<=n ; i++)
       {
       	  if(s[i]=='B')
       	  black.push_back(i);
       	  else
       	  white.push_back(i);   
       }

       if(black.size()==n || white.size()==n)
       {
       	  cout<<0<<endl;
       	  return ;
       }

       if(black.size()%2 && white.size()%2)
       {
       	  cout<<-1<<endl;
       	  return ;
       }

       if(black.size()%2==0)
       {
               
               vector<int>ans;

               for(int i=1 ; i<black.size() ; i+=2)
               {
               	   int left = black[i-1];
               	   int right = black[i];

               	   for(int j=right-1 ; j>=left ; j--)
               	   {
               	   	  ans.push_back(j);
               	   }
               }

               cout<<ans.size()<<endl;
               for(auto i:ans)
               	cout<<i<<" ";
               cout<<endl;
               return ;

       }
       black = white;

       if(black.size()%2==0)
       {
               
               vector<int>ans;

               for(int i=1 ; i<black.size() ; i+=2)
               {
               	   int left = black[i-1];
               	   int right = black[i];

               	   for(int j=right-1 ; j>=left ; j--)
               	   {
               	   	  ans.push_back(j);
               	   }
               }

               cout<<ans.size()<<endl;
               for(auto i:ans)
               	cout<<i<<" ";
               cout<<endl;
               return ;

       }
      
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;
        
    //    cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 