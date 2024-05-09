/*
* @Author: Zakaria 
* @Date:   2022-10-11 20:35:29
* @Last Modified time: 2022-10-11 20:44:21
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
        
       string a, b;
       cin>>a>>b;
       
   

       if(a==b)
       {
       	  cout<<"="<<endl;
       }
       else
       {
       	    if(a.back()==b.back())
       	    {
                
                 	  int cnta=0, cntb=0;

                 	  for(auto i:a)
                 	  {
                 	  	 if(i=='X')
                 	  	 	cnta++;
                 	  }

                 	  for(auto i:b)
                 	  {
                 	  	  if(i=='X')
                 	  	  	cntb++;
                 	  }

                 	  if(a.back()=='L')
                 	  {
                 	  	  if(cnta>cntb)
                 	  	  	cout<<">"<<endl;
                 	  	  else if(cnta==cntb)
                 	  	  	cout<<"="<<endl;
                 	  	  else
                 	  	  	cout<<"<"<<endl;
                 	  }
                 	  else
                 	  {
                 	  	  if(cnta>cntb)
                 	  	  	cout<<"<"<<endl;
                 	  	  else if(cnta==cntb)
                 	  	  	cout<<"="<<endl;
                 	  	  else
                 	  	  	cout<<">"<<endl;
                 	  }
                 
       	    }
       	    else
       	    {
       	    	 if(a.back()=='L')
       	    	 {
       	    	 		cout<<'>'<<endl;
       	    	 }
       	    	 else if(a.back()=='S')
       	    	 {
       	    	 	 cout<<"<"<<endl;
       	    	 }
       	    	 else if(a.back()=='M')
       	    	 {
       	    	 	if(b.back()=='S')
       	    	 		cout<<">"<<endl;
       	    	 	else if(b.back()=='L')
       	    	 		cout<<"<"<<endl;
       	    	 }
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