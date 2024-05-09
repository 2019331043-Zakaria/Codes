/*
* @Author: Zakaria 
* @Date:   2022-12-14 16:46:43
* @Last Modified time: 2022-12-14 17:17:52
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
const int N = 5e5+6;

int n, k;
int a[N];
int m[1000007];
int Check(int len)
{
	
	
    int dist = 0;

	for(int i=0 ; i<=n ; i++)
	{

		if(i<len)
		{

			if(m[a[i]]==0)
				dist++;

			m[a[i]]++;
		}
		else
		{
            int val = a[i - len];
            

           
            m[val]--;

            if(m[val]==0)
            	dist--;
            
            if(m[a[i]]==0)
            	dist++;
            m[a[i]]++;

            if(dist<=k)
            	return i;
		}
	}

	return -1; 

}


void Solve()
{
        
     cin>>n>>k;
     a[0] = 1000001;
     for(int i=1 ; i<=n ; i++)
     cin>>a[i];


     int low = 1, high = n, mid;
     int ans = 0;
     int left = -1;
     while(low<=high)
     {
     	mid = (low+high)/2;

     	for(int i=0 ; i<=1000004 ; i++)
		m[i] = 0;
    

        int index = Check(mid);

     	if(index!=-1)
     		ans = mid, low = mid + 1, left = index;
     	else
     		high = mid - 1;
     }       

  

     cout<<left - ans + 1<<" "<<left<<endl;

     
      
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