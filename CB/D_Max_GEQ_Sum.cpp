/*
* @Author: Zakaria 
* @Date:   2022-10-15 10:13:08
* @Last Modified time: 2022-10-15 10:53:20
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

ll Table[N][20], a[N];
int n;

void Build(int n)
{
  
     for(int i=1 ; i<=n ; i++)
      Table[i][0]=a[i];

     for(int k=1 ; k<20 ; k++)
     {
         for(int i=1 ; i+(1<<k)-1<=n ; i++)
          Table[i][k]=max(Table[i][k-1], Table[i+(1<<(k-1))][k-1]);
     }
   
}

ll Query(int l, int r)
{
     int k = log2(r-l+1);
     return max(Table[l][k], Table[r-(1<<k)+1][k]);
}

int find_left(int index)
{
	   int low=1, high=index;
       int ans=index;
	   while(low<=high)
	   {
	   	    int mid = (low+high)/2;
	   	    if(Query(mid, index) == a[index])
	   	      ans = mid, high = mid -1;
	   	    else
	   	       low = mid+1;
	   }

	   return ans;
}

int find_right(int index)
{
	   int low = index, high = n;

	   int ans=index;

	   while(low<=high)
	   {
	   	    int mid = (low+high)/2;

	   	    if(Query(index, mid) == a[index])
	   	    	ans=mid, low = mid + 1;
	   	    else
	   	    	high = mid - 1;
	   }

	   return ans;
}

void Solve()
{
        
        
        cin>>n;
        
        for(int i=1 ; i<=n ; i++)
        	cin>>a[i];
        
        Build(n);

        vector<pair<int, int> > v;

        for(int i=1 ; i<=n ; i++)
        {
        	 int left = find_left(i);
        	 int right = find_right(i);
        	 v.push_back({left, right});                 	 
        }




        ll ForwardCum[n+1];
        
        ForwardCum[0]=0;

        for(int i=1 ; i<=n ; i++)
        	ForwardCum[i] = ForwardCum[i-1] + a[i];

        ll ReverseCum[n+1];

        ReverseCum[n] = a[n];

        for(int i=n-1 ; i>=1 ; i--)
        	ReverseCum[i] = ReverseCum[i+1] + a[i];


        for(int i=1 ; i<=n ; i++)
        	a[i] = ForwardCum[i];

        Build(n);

        for(int i = 1 ; i<=n ; i++)
        {
        	int index = i;
        	int right = v[i-1].s;

        	ll sum = Query(index, right);

        	if(sum - ForwardCum[index]>0)
        	{
        		cout<<"NO"<<endl;
        		return ;
        	}
        }

        for(int i=1 ; i<=n ; i++)
        	a[i] = ReverseCum[i];

        Build(n);

        for(int i = 1; i<=n ; i++)
        {
        	int index = i;
        	int left = v[i-1].f;

        	ll sum = Query(left, index);

        	if(sum - ReverseCum[index]>0)
        	{
        		cout<<"NO"<<endl;
        		return ;
        	}
        }

        cout<<"YES"<<endl;

        
      
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