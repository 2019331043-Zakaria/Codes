/*
* @Author: Zakaria 
* @Date:   2022-09-12 14:09:16
* @Last Modified time: 2022-09-12 15:32:13
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

int vis[N];

void Solve()
{
        
        int n, k;
        cin>>n>>k;

        for(int i=3; i<=n ; i++)
        {
        	  int mid = (i+1)/2;

        	  int remnode = n - i;

        	  int dis = i - 1 - max(mid-1, i-mid);

        	  ll total=dis*(k-2);

        	  if(total>=remnode)
        	  {
	        	  	 cout<<i-1<<endl;
	        	  	 
	        	  	 for(int node = 1; node<i ; node++)
	        	  	 	cout<<node<<" "<<node+1<<endl, vis[node]++, vis[node+1]++;

	                 
	                 int temp=i+1;
	                 k-=2;
                     
                     vector<int>offset;


	                 for(int i=1 ; i<=k ; i++)
	                 {
	                      int rem=(remnode)/k;
	                      int tempmid=mid;

	                      while(rem-- && temp<=n)
	                      {
	                         cout<<tempmid<<" "<<temp<<endl;
	                         vis[tempmid]++, vis[temp]++;
	                         tempmid=temp;
	                         temp++;
	                      }

	                      offset.push_back(temp-1);
	                 }

	                 while(temp<=n)
	                 {
	                 	  cout<<temp<<" "<<offset.back()<<endl;
	                 	  vis[temp]++;
	                 	  vis[offset.back()]++;
	                 	  offset.pop_back();
	                 	  temp++;
	                 }
                     
                    

	        	  	 return ;
        	  }
        }

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