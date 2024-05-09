/*
* @Author: Zakaria 
* @Date:   2023-01-01 20:12:37
* @Last Modified time: 2023-01-01 20:25:28
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

char a[12][12];

void Solve()
{
      for(int i=1 ; i<=10 ; i++)
      {
      	 for(int j=1 ; j<=10 ; j++)
      	 	a[i][j] = '*';
      }  

      for(int i=1 ; i<=10 ; i++)
      {
      	for(int j=1 ; j<=10 ; j++)
      		cin>>a[i][j];
      } 

      int n  = 10;

      for(int i=1 ; i<=n ; i++)
      {
      	 for(int j=1 ; j<=n ; j++)
      	 {
      	 	 int cnt = 0;
             int can = 0;
      	 	 for(int k=j ; k<=min(n, j+4) ; k++)
      	 	 {
      	 	 	cnt+=(a[i][k]=='X');
      	 	 	cnt-=(a[i][k]=='O');
      	 	 	can++;
      	 	 }

      	 	 if(cnt==4 && can==5)
      	 	 {
      	 	 	cout<<"YES"<<endl;
      	 	 	return ;
      	 	 }

      	 }
      }

      for(int j=1 ; j<=n ; j++)
      {
      	 for(int i=1 ; i<=n ; i++)
      	 {
      	 	 int cnt = 0;
             int can = 0;
      	 	 for(int k=i ; k<=min(n, i+4) ; k++)
      	 	 {
      	 	 	cnt+=(a[k][j]=='X');
      	 	 	cnt-=(a[k][j]=='O');
      	 	 	can++;
      	 	 }

      	 	 if(cnt==4 && can==5)
      	 	 {
      	 	 	cout<<"YES"<<endl;
      	 	 	return ;
      	 	 }

      	 }
      }


      for(int i=1 ; i<=n ; i++)
      {
      	for(int j=1 ; j<=n ; j++)
      	{
      		// go left :
            
            int cnt = 0;
            int can = 0;

            for(int k=0 ; k<5 ; k++)
            {
            	 int x = i+k;
            	 int y = j+k;
                 
            	 if(x<=n && y<=n)
            	 {
            	 	cnt+=(a[x][y]=='X');
      	 	     	cnt-=(a[x][y]=='O');
      	 	    	can++;
            	 }
            } 

            if(cnt==4 && can==5)
            {
            	cout<<"YES"<<endl;
            	return ;
            }
            
            cnt = 0;
            can = 0;


      		// go right :

      		for(int k=0 ; k<5 ; k++)
            {
            	 int x = i+k;
            	 int y = j-k;

            	 if(x>=1 && x<=n && y<=n && y>=1)
            	 {
            	 	cnt+=(a[x][y]=='X');
      	 	     	cnt-=(a[x][y]=='O');
      	 	    	can++;
            	 }
            } 

            if(cnt==4 && can==5)
            {
            	cout<<"YES"<<endl;
            	return ;
            }
      	}
      }

      cout<<"NO"<<endl;


      
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;
        
       // cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 