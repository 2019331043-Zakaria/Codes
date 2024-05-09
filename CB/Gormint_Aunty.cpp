/*
* @Author: Zakaria 
* @Date:   2022-11-16 21:30:31
* @Last Modified time: 2022-11-16 23:19:10
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

        int low = k, high = n;

        int mid ;
        int ans = n;

        

        while(low<=high)
        {
        	int mid = (low+high)/2;
            
            int temp = n/mid;
            int baki = n%mid;


            if(temp==0 || baki==0 || mid+1 > baki)
            	ans = mid, high = mid - 1;
            else
            	low = mid + 1;

        }

        cout<<ans<<endl;

       
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