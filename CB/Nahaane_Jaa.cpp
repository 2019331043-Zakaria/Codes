/*
* @Author: Zakaria 
* @Date:   2022-11-16 21:30:31
* @Last Modified time: 2022-11-16 23:29:38
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
        
        int n, k;
        cin>>n>>k;

        int temp = n/k;

        vector<int>v;

        for(int i=1 ; i<=k ; i++)
        	v.push_back(i);

     
        vector<int>ans;

        int baki = n%k;

        for(int i=1 ; i<=temp ; i++)
        {
        	for(auto k:v)
        		ans.push_back(k);
           
        }
        
        int value = k+1;

        int pans = ans.size();


        while(baki>0)
        {
        	  
        	int low =  0 , high = n/k, mid;
        	int canbe = 0;

        	while(low<=high)
        	{
        		mid = (low+high)/2;
                
                int add = 0;

               for(int i=0 ; i<pans ; i++)
               {
                  if((i+add)%k==0 && pans - i >=k)
                  {
                  	add++;
                  }
               
               }
               


               if(add>=mid)
                 canbe = mid, low = mid + 1;
               else
               	 high = mid - 1;

        	}
             

        	baki-=canbe;
        	value++;

        	pans+=canbe;

         }

         cout<<value-1<<endl;
         ans.clear();
         v.clear();

         for(int i=1 ; i<value ; i++)
         	v.push_back(i);

        temp = n/ (value-1);

        for(int i=1 ; i<=temp ; i++)
        {
        	for(auto i:v)
        		cout<<i<<" ";

        }

        for(int i=0 ; i<n%(value-1) ; i++)
        	cout<<v[i]<<" ";

        cout<<endl;




        

          

       
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