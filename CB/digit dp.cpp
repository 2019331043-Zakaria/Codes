/*
* @Author: Zakaria 
* @Date:   2022-08-24 07:55:54
* @Last Modified time: 2023-06-08 14:11:40
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
 
ll dp[N][11][2][2];   // digit dp te amar number generate hoy emne : 0, 01, 02, 03, 04, 05.....066,0667
 
ll getsum(int pos, int dig,  int n, bool ok, bool other)
{
       cout<<pos<<" "<<dig<<endl;
       if(pos>n)
       {
       	   return 1;
       }
 
       ll &R = dp[pos][dig][ok][other];
       
       if(R!=-1)
       	return R;
 
       int maxdigit = 9;
       if(!ok)
       maxdigit = a[pos];  
 
       ll res=0;
 
       for(int i=0 ; i<=maxdigit ; i++)
       {
       	    
            if(dig == i && other)
            	continue;
            if(i>0)
                other=1;

       	    if(i<maxdigit || ok)
       	     res+=getsum(pos+1, i, n, true, other);
       	    else
       	     res+=getsum(pos+1, i, n, false, other);
       }
 
       return R = res;
 
}
 
void Solve()
{
        
        string l, r;
        cin>>l>>r;
 
        int n = r.size();
 
 
        r='*'+r;
 
        for(int i=0 ; i<=n ; i++)
        {
        	a[i]=r[i]-'0';
        }
        
        memset(dp, -1, sizeof(dp));
        ll sumr = getsum(1, -1 , n, 0, 0);

      //  cout<<sumr<<endl;
        
        
 
        n = l.size();
        l = '*' + l;
 
        for(int i=0 ; i<=n ; i++)
        	a[i] = l[i]-'0';
 
        memset(dp, -1, sizeof(dp));
        
        ll suml = getsum(1, -1, n, 0, 0);
 
        bool ok=1;
 
        for(int i=2 ; i<=n ; i++)
        	if(l[i-1]==l[i])
                ok=0;
 
        cout<<sumr - suml + ok<<endl;
 
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;
        
        //cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 

//https://cses.fi/problemset/task/2220/