/*
* @Author: Zakaria 
* @Date:   2023-01-03 12:18:53
* @Last Modified time: 2023-01-03 12:28:10
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
        
        int n = 7;

        set<int>st;

        for(int i=0 ; i<n ; i++)
        {
        	vector<int>v;

        	for(int j= 0 ;j<n ; j++)
        	{
        		if(j!=i)
        			v.push_back(j);
        	}

        	for(auto i:v)
        		cout<<i<<" ";
        	cout<<endl;

        	for(int k=1 ; k<v.size() ; k++)
        	{
        		if(v[k]&v[k-1])
        		{
        			cout<<"BAL"<<endl;
        			break;
        		}
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