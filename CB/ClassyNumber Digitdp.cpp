/*
* @Author: Zakaria 
* @Date:   2022-08-24 07:55:54
* @Last Modified time: 2022-08-25 00:46:18
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
#define  MAX         200002
#define  eps         1e-6
typedef long long ll;
using namespace std;

const int N=20;

int a[N];

ll dp[N][N][2];

ll getNUM(int pos, int n,  int nonzero, bool ok)
{
       
       if(pos>n)
       {
           if(nonzero<=3)
       	        return 1;
           else
                return 0;
       }
       
       if(nonzero>3)
        return 0;

       ll &R=dp[pos][nonzero][ok];
       
       if(R!=-1)
       	return R;

       int maxdigit = 9;
       if(!ok)
       maxdigit = a[pos];  

       ll res=0;

       for(int i=0 ; i<=maxdigit ; i++)
       {
       	    if(i<maxdigit || ok)
       	    {
                if(i==0)
                res+=getNUM(pos+1, n, nonzero, true);
                else
                res+=getNUM(pos+1, n, nonzero+1, true);
            }
       	    else
       	    {
                 if(i==0)
                 res+=getNUM(pos+1, n, nonzero, false);
                 else
                 res+=getNUM(pos+1, n, nonzero+1, false);
            }
       }

       return R = res;

}

void Solve()
{
        
        string l, r;
        cin>>l>>r;
        
        int n=r.size();
        r='*'+r;

        for(int i=1 ; i<=n ; i++)
        {
        	a[i]=r[i]-'0';
        }
        
        memset(dp, -1, sizeof(dp));

        ll sumr = getNUM(1, n, 0, 0);

        n = l.size();
        l = '*' + l;


        for(int i=1 ; i<=n ; i++)
        {
        	a[i] = l[i]-'0';
        }

        memset(dp, -1, sizeof(dp));

        ll suml = getNUM(1, n , 0, 0);
        ll ans=0;

        int nonzero=0;
        for(int i=1 ; i<=n ; i++)
                if(l[i]!='0')
                        nonzero++;
        if(nonzero<=3)
                ans++;

        ans+=sumr;
        ans-=suml;

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