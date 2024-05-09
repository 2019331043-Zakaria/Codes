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
ll n;
ll m;
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

ll Query(int l, int r)
{
     int k = log2(r-l+1);
     return min(Table[l][k], Table[r-(1<<k)+1][k]);
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
        
        cin>>n>>m;

        for(int i=1 ; i<=n ; i++)
            cin>>a[i];

        Build(n);

        ll ans=0;

        for(int i=1 ; i<=n ; i++)
        {
          //  if(a[i]*1LL*(find_right(i) - find_left(i) + 1)<=m)
            ans=max(ans, a[i]*1LL*(find_right(i) - find_left(i) + 1) );
        }

        cout<<ans<<endl;
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;
        
      //  cin>>tt;

        int teest=1;
        
        while(tt--)
        {
           // cout<<"Case "<<teest++<<": ";
            Solve();
        }
 
        return 0;
        
} 