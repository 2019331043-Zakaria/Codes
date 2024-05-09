/*
* @Author: Zakaria 
* @Date:   2022-10-22 15:01:39
* @Last Modified time: 2022-10-22 15:24:13
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
const int N = 2e5 + 9;

int Table[N][20], a[N];

map<int, ll>ans;

void Build(int n)
{
  
     for(int i=1 ; i<=n ; i++)
      Table[i][0]=a[i];

     for(int k=1 ; k<20 ; k++)
     {
         for(int i=1 ; i+(1<<k)-1<=n ; i++)
          Table[i][k] = GCD(Table[i][k-1], Table[i+(1<<(k-1))][k-1]);
     }
   
}

int Query(int l, int r)
{
     int k = log2(r-l+1);
     return GCD(Table[l][k], Table[r-(1<<k)+1][k]);
}


void Solve()
{
        
        int n;
        cin>>n;

        for(int i=1 ; i<=n ; i++)
        	cin>>a[i];

        Build(n);

      

        for(int i=1 ; i<=n ; i++)
        {
        	int index = i;
        	

        	while(index<=n)
        	{
        		int low = index, high = n, mid;
                int FindIndex = index;
                int CurGCD = Query(i, index);

        		while(low<=high)
        		{
        			mid = (low+high)/2;

        			if(Query(i, mid) == CurGCD)
        				FindIndex = mid, low = mid + 1;
        			else
        				high = mid - 1;
        		}

        		ans[CurGCD] += FindIndex - index + 1;
        		index = FindIndex + 1;
        	}
        }

        int q;
        cin>>q;

        while(q--)
        {
        	int x;
        	cin>>x;
        	cout<<ans[x]<<endl;
        }
      
      
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