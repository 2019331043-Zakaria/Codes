/*
* @Author: Zakaria 
* @Date:   2022-10-01 18:16:58
* @Last Modified time: 2022-10-01 18:21:46
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
const int N = 3e5+6;

int n;
int a[N];

bool check(int mid)
{
        
        int less=0, up=0;
        int lessextra=0;
        
        map<int, int>m;

        for(int i=1 ; i<=n ; i++)
        {
        	if(a[i]<=mid)
        		m[a[i]]++;
        	else
        		up++;
        }

        for(auto i:m)
        	less++, lessextra+=i.s-1;

        if(less==mid)
        	return 1;

        int lage=mid - less;

        if((lessextra+up)/2>=lage)
        	return 1;
        else
        	return 0;

}

void Solve()
{
        cin>>n;

        for(int i=1 ; i<=n ; i++)
        	cin>>a[i];

        int low=1, high=n;
        int ans=0;


        while(low<=high)
        {
        	int mid=(low+high)/2;

        	if(check(mid))
        		ans=mid, low = mid+1;
        	else
        		high = mid - 1 ;
        }

        cout<<ans<<endl;
        
        
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