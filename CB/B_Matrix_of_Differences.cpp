/*
* @Author: Zakaria 
* @Date:   2023-01-08 20:44:19
* @Last Modified time: 2023-01-08 22:44:39
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
const int N = 2e2+6;

int a[N][N];
int n;


void printa()
{
	 for(int i=1 ; i<=n ; i++)
	 {
	 	for(int j=1 ; j<=n ; j++)
	 		cout<<a[i][j]<<" ";
	 	cout<<endl;
	 }

	
}

void Solve()
{
        
        
        cin>>n;

        int sum=1;
        for(int i=1 ; i<=n ; i++)
        {
        	for(int j=1 ; j<=n ; j++)
        		a[i][j] = 0;
        }
       

       // printa();

      //  sum = 1;

        int suml = 1, sumr = n*n;
        
        /*for(int k=1 ; k<=(n+1)/2 ; k++)
        {

	        for(int i=1 ; i<=n ; i++)
	        {
	        	for(int j=1 ; j<=n ; j++)
	        	{
                     if(a[i][j])
                     	continue;

                     int leftrow = i;
                     int rightrow = n - i + 1;
                     int upcol = j;
                     int downcol = n - j + 1;

                     if(leftrow==k || rightrow==k || upcol ==k || downcol==k)
                     {
                     	 if((i+j)%2==0)
                     	 { 
                             a[i][j] = suml++;
                     	 }
                     	 else
                     	 {
                     	 	a[i][j] = sumr--;
                     	 }
                     }
	        	}
	        }

         }
*/

      for(int k=1 ; k<=(n+1)/2 ; k++)
      {

        for(int j=1 ; j<=n ; j++)
        {
        	if(a[k][j])
        		continue;

        	if((k+j)%2==0)
        		a[k][j] = suml++;
        	else
        		a[k][j] = sumr--;
        }

        for(int i=1 ; i<=n ; i++)
        {
        	if(a[i][n-k+1])
        		continue;

        	if((i+n)%2==0)
        		a[i][n-k+1] = suml++;
        	else
        		a[i][n-k+1] = sumr--;

        }

        for(int j = n ; j>=1 ; j--)
        {
        	 if(a[n-k+1][j])
        	 	continue;

        	 if((n-k+1+j)%2==0)
        		a[n-k+1][j] = suml++;
        	else
        		a[n-k+1][j] = sumr--;


        }

        for(int i=n ; i>=1 ; i--)
        {
        	if(a[i][k])
        		continue;

        	if((i+k)%2==0)
        		a[i][k] = suml++;
        	else
        		a[i][k] = sumr--;

        }

        /*for(int i=1 ; i<=n ; i++)
        {
        	for(int j=1 ; j<=n ; j++)
        	{
        		if(a[i][j])
        			continue;

        		if((i+j)%2==0)
        			a[i][j] = suml++;
        		else
        			a[i][j] = sumr--;
        	}
        }*/

      }




        printa();

        set<int>st;

        for(int i=1 ; i<=n ; i++)
        {
        	for(int j=1 ; j<=n ; j++)
        	{
        		if(i-1>0)
        		{
        			st.insert(abs(a[i][j] - a[i-1][j]));
        		}

        		if(j-1>0)
        		{
        			st.insert(abs(a[i][j] - a[i][j-1]));
        		}
        	}
        }

        cout<<st.size()<<endl;

        

      
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