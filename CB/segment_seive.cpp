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

#define sz 1000010
bool siv[sz];
vector<long long >primes;

void seive()
{
    long long  limit = sqrt(sz+1);

    for (long long  i=3; i<=limit; i+=2)
        if(!siv[i])
            for (long  j = i*i; j<sz; j+=i+i)
                siv[j] = 1;
    primes.push_back(2);
    for (long long i=3; i<sz; i+=2)
        if(!siv[i]) primes.push_back(i);
}

bool vis[sz];


void Solve()
{
        
        int l, r;
        cin>>l>>r;

        for(int i=0 ; i<=100000 ; i++)
            vis[i]=0;
        
        for(auto i:primes)
        {
             int pans = (l + i - 1)/i;

             for(ll j = pans*i ; j<=r ; j+=i)
             {
                
                 if(j==i)
                    continue;
               //  cout<<j<<" ";
                 vis[j - l]=1;
             }
            // cout<<endl;

        }

        int ans = 0;

        for(int i=max(2, l) ; i<=r ; i++)
        {
           // cout<<i<<endl;
            if(vis[i - l]==0)
                ans++;
        }

        cout<<ans<<endl;
      
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        

        seive();


        int tt=1;
        
        cin>>tt;

        int test = 0;
        
        while(tt--)
        {
            cout<<"Case "<<++test<<": ";
            Solve();
        }
 
        return 0;
        
} 