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

int a[N];
int ans[N];

int query(int n)
{
     cout<<"? ";
     for(int i=1 ; i<=n ; i++)
        cout<<a[i]<<" ";
     cout<<endl<<flush;

     int index;
     cin>>index;

     return index;
}

void Solve()
{

       int n;
       cin>>n;

       int less=0;
       for(int k=2 ; k<=n ; k++)
       {
            a[n]=1;
            for(int i=1 ; i<n ; i++)
                a[i]=k;

            int index = query(n);
            if(index)
                ans[index]=1-k, less++;
            else
                break;
       }

       ans[n]=less+1;


       for(int k=2; k<=n ; k++)
       {
           a[n]=k;
           for(int i=1 ; i<n ; i++)
            a[i]=1;
           int index = query(n);

           if(index)
            ans[index]=k-1;
           else
            break;
       }
       for(int i=1 ; i<n ; i++)
        ans[i]+=ans[n];

       cout<<"! ";
       for(int i=1 ; i<=n ; i++)
        cout<<ans[i]<<" ";
       cout<<endl<<flush;


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
/*

5
? 2 2 2 2 1
3
? 3 3 3 3 1
1
? 4 4 4 4 1
0
? 1 1 1 1 2
4
? 1 1 1 1 3
2
? 1 1 1 1 4
0

*/
