/*
* @Author: Zakaria 
* @Date:   2023-01-01 12:04:06
* @Last Modified time: 2023-01-01 12:38:58
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
const int N = 1e7+6;

ll ans[N];
ll res[N];
void Solve()
{
        int n;
        cin>>n;

        if(res[n]==0)
        	cout<<-1<<endl;
        else
        	cout<<res[n]<<endl;

}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        

        for(int i=1 ; i<N ; i++)
        {
        	for(int j=i ; j<N ; j+=i)
        		ans[j]+=i;

        	if(ans[i]<N)
        	{
        		if(res[ans[i]]==0)
        			res[ans[i]] = i;
        	}
        }
        
        int tt=1;
        
        cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 