/*
* @Author: Zakaria 
* @Date:   2022-09-29 09:48:25
* @Last Modified time: 2022-09-29 10:14:56
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
int Table[N][20], a[N];
int ans[N];
int n;

void Build(int n)
{
  
     for(int i=1 ; i<=n ; i++)
      Table[i][0]=a[i];

     for(int k=1 ; k<20 ; k++)
     {
         for(int i=1 ; i+(1<<k)-1<=n ; i++)
          Table[i][k]=GCD(Table[i][k-1], Table[i+(1<<(k-1))][k-1]);
     }
   
}

int Query(int l, int r)
{
     int k = log2(r-l+1);
     return GCD(Table[l][k], Table[r-(1<<k)+1][k]);
}

int RightMost(int val, int index)
{
	    int low=0, high=n-index;
        int r=index;
	    while(low<=high)
	    {
	    	  int mid = (high+low)/2;

	    	  if(Query(index, index+mid)==val)
	    	  	r = index+mid , low = mid+1;
	    	  else
	    	  	high = mid-1;
	    }

	    return r;
}

int LeftMost(int val, int index)
{
	   int low=0, high=index-1;
	   int l=index;

	   while(low<=high)
	   {
	   	    int mid = (high+low)/2;

	   	    if(Query(index - mid, index)==val)
              l=index-mid, low = mid + 1;
            else
              high = mid - 1;
	   }

	   return l;
}
void Solve()
{
        
        cin>>n;

        for(int i=1 ; i<=n ; i++)
        	cin>>a[i];

        Build(n);


        
        int mx=0;
        
        for(int i=1 ; i<=n ; i++)
        {
             pair<int, int>p = {LeftMost(a[i], i), RightMost(a[i], i)};
           
             ans[p.f] = max(ans[p.f], p.s - p.f);

             mx=max(mx, ans[p.f]); 
        }

        vector<int>res;

        for(int i=1 ; i<=n ; i++)
        {
        	 if(ans[i]==mx)
        	 	res.push_back(i);
        }


        cout<<res.size()<<" "<<mx<<endl;
        for(auto i:res)
        	cout<<i<<" ";
        cout<<endl;

      
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;
        
       // cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 