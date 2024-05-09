/*
* @Author: Zakaria 
* @Date:   2022-04-01 01:08:32
* @Last Modified time: 2022-08-25 19:47:54
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

const int N = 11;

ll dp[N][100][100][2];
ll a[N];

string l, r;
ll k;

ll getSUM(ll pos, ll n, ll sumofdigit, ll number,  bool ok)
{
       
       if(pos>n)
       {
             if(sumofdigit%k==0 && number%k==0)
                return 1;
             else
                return 0;
       }
       
       ll &R = dp[pos][sumofdigit][number][ok];
       
       if(R!=-1)
        return R;

       ll maxdigit=9;

       if(!ok)
        maxdigit = a[pos];

       ll cnt=0;

       for(ll i=0 ; i<=maxdigit ; i++)
       {
          if(i<maxdigit || ok)
          {
              
              ll sum=sumofdigit+i;
              sum%=k;
              
              ll sumNum=number;
              sumNum+=(i*pow(10, n-pos));
              sumNum%=k;

              cnt+=getSUM(pos+1, n, sum,  sumNum,  true);
          }
          else
          {
             
              ll sum=sumofdigit+i;
              sum%=k;

              ll sumNum=number;
              sumNum+=(i*pow(10, n-pos));
              sumNum%=k;

              cnt+=getSUM(pos+1, n, sum, sumNum, false);
          }
       }

       return  R = cnt;

}

void Solve()
{
        
        cin>>l>>r>>k;

        if(k>90)
        {
            cout<<0<<endl;
            return ;
        }

        int n = r.size();
        r='*'+r;

        for(int i=1 ; i<=n ; i++)
          a[i] = r[i]-'0';

        memset(dp, -1, sizeof(dp)); 
        ll sumr = getSUM(1, n, 0, 0, 0); 
         
       


        n = l.size();
        l = '*' + l;

        for(int i=1 ; i<=n ; i++)
           a[i] = l[i] - '0';

        memset(dp, -1, sizeof(dp));              
        ll suml =  getSUM(1, n, 0, 0, 0); 

        ll ans=0;
        ll number=0;
        ll cnt=0;
        for(int i=1 ; i<=n ; i++)
            cnt+=l[i]-'0';
        ll temp=1;
        for(int i=n ; i>=1 ; i--)
          number+=(l[i]-'0')*temp, temp*=10;

        if(cnt%k==0 && number%k==0)
            ans++;

        ans+=sumr;
        ans-=suml;

        cout<<ans<<endl;
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1, test=0;
        
        cin>>tt;
        
        while(tt--)
        {
            cout<<"Case "<<++test<<": ";
            Solve();
        }
 
        return 0;
        
} 