/*
* @Author: Zakaria 
* @Date:   2022-10-24 21:09:23
* @Last Modified time: 2022-10-24 21:40:47
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

int n, q;
ll a[N], XorCum[N], CumSum[N];

pair<int, int>find(int index)
{
       
       int low = index, high = n;
       int mid ;
       int ans = 1e9;
      
       while(low<=high)
       {
             mid = (low+high)/2;

             ll temp = CumSum[mid] - CumSum[index-1] - (XorCum[mid]^XorCum[index-1]);
             
             if(temp == CumSum[n] - XorCum[n])
             {  
                 ans = mid;
                 high = mid-1;
             }
             else
             	low = mid+1;

       }

     

       return {ans - index , index};

}

void Solve()
{
        
       
        cin>>n>>q;

        

        for(int i = 1 ; i<=n ; i++)
        	cin>>a[i], CumSum[i] = CumSum[i-1] + a[i], XorCum[i] = XorCum[i-1]^a[i];

        int l, r;
        cin>>l>>r;
        

        vector< pair<int, int> > ans;
        
        

        for(int i=l ; i<=r ; i++)
        {
             ans.push_back(find(i));
        }

        sort(ans.begin(), ans.end());

        cout<<ans[0].s<<" "<<ans[0].s+ans[0].f<<endl;


      
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