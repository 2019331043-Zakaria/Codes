/*
* @Author: Zakaria 
* @Date:   2022-10-23 13:57:23
* @Last Modified time: 2022-10-23 14:08:46
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
        int temp=n/2;

        vector<int>v;


        for(int i=temp ; i>=1 ; i--)
        {
        	 int value=i;
        	while(value<=n)
        	{
        		cout<<value<<" ";
        		value+=temp;
        	}
        }

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