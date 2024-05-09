#include<bits/stdc++.h>
#define test int t; cin>>t; while(t--)
#define fast ios::sync_with_stdio(false);
typedef long long ll;
using namespace std;

ll bigmod(ll a,ll b,ll n)
{

    ll  res=1;
    a=a%n;
    if(a==0)
       return 0;
    while(b>0)
    {

           if(b%2)
            res=(res*a)%n;

            b=b/2;;
            a=(a*a)%n;


    }
   return res;

}

int main()
{
     fast

    while(true)
    {


         int k,n;
         cin>>n>>k;
         if(n==0&&k==0)
            return 0;
         int ans=0;

            int x=10000007;
            int  temp1=bigmod(n-1,n-1,x);
              temp1=(2*temp1)%x;
              int temp2=bigmod(n-1,k,x);
              temp2=(2*temp2)%x;
              int temp3=bigmod(n,n,x);
              int temp4=bigmod(n,k,x);
              ans=(temp1+temp2+temp3+temp4)%x;
              cout<<ans<<endl;
//            cout<<endl;
//             for(int i=1;i<=n;i++)
//            {
//                cout<<bigmod(i,k,x)<<" ";
//
//            }

    }

return 0;

}
