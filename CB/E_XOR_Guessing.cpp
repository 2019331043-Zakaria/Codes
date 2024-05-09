/*
* @Author: Zakaria 
* @Date:   2022-12-05 19:01:50
* @Last Modified time: 2022-12-05 19:22:28
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

int Query(vector<int>v)
{
	 cout<<"? ";
     for(int i=0;i<100;i++)
     {
        if(i) cout<<' ';
        cout<<v[i];
     }
     cout<<endl<<flush;

	 int x;
	 cin>>x;
	 return x;
}

void Solve()
{
        
       vector<int>v;

       for(int i=1 ; i<=100 ; i++)
       {
       	  v.push_back(i);
       }

       int pans1 = Query(v);

       v.clear();
       int temp=1000;

       while(v.size()!=100)
       {
           v.push_back(temp);
           temp+=100;
       }

       int pans2 = Query(v);

       for(int i=0 ; i<=16383 ; i++)
       {
       	   bool ok1=0;
       	   for(int j=1 ; j<=100 ; j++)
       	   {
       	   	  if(i^j==pans1)
       	   	  	ok1=1;
       	   }

       	   bool ok2 = 0;
       	   for(int j=200 ; j<=299 ; j++)
       	   {
       	   	  if(i^j==pans2)
       	   	  	ok2=1;
       	   }

       	   if(ok1 && ok2)
       	   {
       	   	  cout<<"! "<<i<<endl<<flush;
       	   	  return ;

       	   }


       }
      
}
 
int main()
{
         
       
        
        int tt=1;
        
      //  cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 