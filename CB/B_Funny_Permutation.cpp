/*
* @Author: Zakaria 
* @Date:   2022-10-11 20:44:47
* @Last Modified time: 2022-10-11 20:53:50
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

        if(n==3)
        {
        	cout<<-1<<endl;
        	return ;
        }

        vector<int>v;

        if(n%2==0)
        {
        	

        	for(int i=1 ; i<=n ; i+=2)
        	{
        		v.push_back(i+1);
        		v.push_back(i);
        	}
        }
        else
        {
        	v.push_back(n);
        	v.push_back(n-1);

        	for(int i=1 ; i<n-1 ; i++)
        		v.push_back(i);
        }

         for(auto i:v)
         cout<<i<<" ";

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