/*
* @Author: Zakaria 
* @Date:   2023-01-04 00:50:55
* @Last Modified time: 2023-01-04 02:28:11
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

int Table[N][20], a[N], b[N], c[N];

void Build(int n)
{
  
     for(int i=1 ; i<=n ; i++)
      Table[i][0]=b[i];

     for(int k=1 ; k<20 ; k++)
     {
         for(int i=1 ; i+(1<<k)-1<=n ; i++)
          Table[i][k]=max(Table[i][k-1], Table[i+(1<<(k-1))][k-1]);
     }
   
}

int Query(int l, int r)
{
     int k = log2(r-l+1);
     return max(Table[l][k], Table[r-(1<<k)+1][k]);
}


void Solve()
{
        
        ll n;
        cin>>n;

        map<ll, vector<int>  > pos;

        for(int i=1 ; i<=n ; i++)
        	cin>>a[i];
        
        map<ll, ll>cnt;


       
        for(int i=1 ; i<=n ; i++)
        {
        	cin>>b[i];

        	if(a[i]!=b[i])
        		pos[b[i]].push_back(i);
        }

       

        ll m;
        cin>>m;
        for(int i=1 ;i<=m ; i++)
        	cin>>c[i], cnt[c[i]]++;

        for(int i=1 ; i<=n ; i++)
        {
        	if(a[i]<b[i])
        	{
        		cout<<"NO"<<endl;
        		return ;
        	}
        }

        Build(n);
        
        
        for(auto i : pos)
        {
        	int val = i.f;
        	vector<int>temp = i.s;
        	int res = 1;

        	for(int i=1 ; i<temp.size() ; i++)
        	{
        		if(Query(temp[i-1], temp[i])>val)
        		{
        			res++;
        		}
        	}

        	if(res>cnt[val])
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