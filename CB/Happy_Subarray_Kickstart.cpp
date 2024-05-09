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

const int N = 4e5 + 9;
int Table[N][20], a[N];

void Build(int n)
{
  
     for(int i=1 ; i<=n ; i++)
      Table[i][0]=a[i];

     for(int k=1 ; k<20 ; k++)
     {
         for(int i=1 ; i+(1<<k)-1<=n ; i++)
          Table[i][k]=min(Table[i][k-1], Table[i+(1<<(k-1))][k-1]);
     }
   
}

int Query(int l, int r)
{
     int k = log2(r-l+1);
     return min(Table[l][k], Table[r-(1<<k)+1][k]);
}


void Solve()
{
        
        int n;
        cin>>n;

        ll b[n+1];

        for(int i=1 ; i<=n ; i++)
            cin>>a[i], b[i] = a[i];

        ll cum[n+1];

        cum[0]=0;

        for(int i=1 ; i<=n ; i++)
        {
            cum[i] = cum[i-1] +a[i];
        }
        
        for(int i=1 ; i<=n ; i++)
        {
            a[i] = cum[i];
           
        }

    

        Build(n);


        ll rangeSum[n+1];

        rangeSum[0]=0;

        for(int i=1 ;  i<=n ; i++)
        {
            rangeSum[i] = rangeSum[i-1] + cum[i];
        }

        

        ll ans=0;

        for(int i=1 ; i<=n ; i++)
        {
             if(b[i]<0)
                continue;

             int low = i , high =n;

             int index = i;

             while(low<=high)
             {
                  int mid = (low+high)/2;

                  if(Query(i, mid) - cum[i-1]>=0)
                  {
                      index = mid;
                      low = mid + 1;
                  }
                  else
                    high = mid - 1;
             }
             
            
             ans+=rangeSum[index];
             ans-=rangeSum[i-1];
             ans-=(1LL*(index - i +1 ) ) * cum[i-1];
            
          
        }

        cout<<ans<<endl;
      
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;
        
        cin>>tt;
        int test=0;

        while(tt--)
        {
            cout<<"Case #"<<++test<<": ";
            Solve();
        }
 
        return 0;
        
} 