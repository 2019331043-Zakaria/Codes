/*
* @Author: Zakaria 
* @Date:   2022-10-29 19:07:37
* @Last Modified time: 2022-10-29 19:41:34
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
        
        char a[11][11];

        for(int i=1 ; i<=9 ; i++)
        {
        	for(int j=1 ; j<=9 ; j++)
        		cin>>a[i][j];
        }
        
        int cnt = 0;

        int ans = 0;

        for(int i=1 ; i<=9 ; i++)
        {
        	for(int j=1 ; j<=9 ; j++)
        	{
        		 for(int rightlen = 1 ; rightlen<=9-j ; rightlen++)
        		 {
        		 	  for(int downlen = 1 ; downlen<=9-i ; downlen++)
        		 	  {
        		 	  	
        		 	  	if(rightlen!=downlen)
        		 	  		continue;

        		 	  	/*cout<<i<<" "<<j<<endl;
                        
                        cout<<i<<" "<<j + rightlen<<endl;

        		 	  	cout<<i + downlen <<" "<<j<<endl;

        		 	  	cout<<i + downlen <<" "<<j + rightlen<<endl;

        		 	    cout<<endl;*/

        		 	    if(a[i][j]=='#' && a[i][j+rightlen]=='#' && a[i+downlen][j]=='#' && a[i+downlen][j+rightlen]=='#')
        		 	    {
        		 	    	int ok = 0;

        		 	    	for(int k = i+1 ; k<i+downlen ; k++)
        		 	    	{
                               if(a[k][j]=='#')
                               	ok++;
        		 	    	}
        		 	    	

        		 	    	
        		 	    	for(int k = i+1 ; k<i+downlen ; k++)
        		 	    	{
                               if(a[k][j+rightlen]=='#')
                               	ok++;
        		 	    	}
        		 	    	

        		 	    	for(int k = j+1 ; k<j+rightlen ; k++)
        		 	    	{
                               if(a[i][k]=='#')
                               	ok++;
        		 	    	}
        		 	    	
        		 	    	for(int k = j+1 ; k<j+rightlen ; k++)
        		 	    	{
                               if(a[i+downlen][k]=='#')
                               	ok++;
        		 	    	}

        		 	    	if(ok==0)
        		 	    		ans++,cout<<"YES";
        		 	    }
        		 	    	
        		 	    else
        		 	    {
        		 	    	int pans = 0;

        		 	    	int ok=0;
                            
        		 	    	for(int k = i+1 ; k<i+downlen ; k++)
        		 	    	{
                               if(a[k][j]=='#')
                               	ok++;
        		 	    	}
        		 	    	pans+=(ok==1);

        		 	    	ok = 0;
        		 	    	for(int k = i+1 ; k<i+downlen ; k++)
        		 	    	{
                               if(a[k][j+rightlen]=='#')
                               	ok++;
        		 	    	}
        		 	    	pans+=(ok==1);
        		 	    	ok = 0;

        		 	    	for(int k = j+1 ; k<j+rightlen ; k++)
        		 	    	{
                               if(a[i][k]=='#')
                               	ok++;
        		 	    	}
        		 	    	pans+=(ok==1);
        		 	    	ok = 0;
        		 	    	for(int k = j+1 ; k<j+rightlen ; k++)
        		 	    	{
                               if(a[i+downlen][k]=='#')
                               	ok++;
        		 	    	}
        		 	    	pans+=(ok==1);

        		 	    	if(pans==4)
        		 	    	{
        		 	    		ans++;
        		 	    		
        		 	        }

        		 	    }
                      
        		 	  }


        		 }

        	}
        }

        cout<<ans<<endl;
        
      
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