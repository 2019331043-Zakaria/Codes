/*
* @Author: Zakaria 
* @Date:   2022-12-29 14:02:04
* @Last Modified time: 2022-12-29 15:33:17
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
        
        int n, l, r;
        cin>>n>>l>>r;


        int pos[n+1];

        int a[n+1];
        int p[n+1];

        for(int i = 1 ; i<=n ; i++)
        	cin>>a[i];

        for(int i=1 ; i<=n ; i++)
        	cin>>p[i], pos[p[i]] = i;

        
        int ans[n+1];
        int temp = -1e9;

        for(int i=1 ; i<=n ; i++)
        {
            int loc = pos[i];
           
            int low = l, high = r, mid;
            int value = -1;

            while(low<=high)
            {
            	mid = (low+high)>>1;
            	if(mid - a[loc]>temp)
            		value = mid, high = mid - 1;
            	else
            		low = mid + 1;
            }

            if(value==-1)
            {
            	cout<<-1<<endl;
            	return ;
            }
            ans[loc] = value;
            temp = ans[loc] - a[loc];
        }

        for(int i=1 ; i<=n ; i++)
        	cout<<ans[i]<<" ";
        cout<<endl;



      
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;
        
     //   cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 