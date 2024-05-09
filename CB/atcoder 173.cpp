#include<bits/stdc++.h>
#define test int t; cin>>t; while(t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define mod 1000000000

typedef long long ll;
using namespace std;

int main()
{
    test
    {
        int n,x,p,mn=mod;
        cin>>n>>x;

        for(int i=0;i<n;i++)
        {
            cin>>p;
            mn=min(mn,p);
        }
        int temp=mn;
        if(mn<=x)
            cout<<n<<endl;
        else
        {
            int cnt=0;
            while(true)
            {
                mn-=x;
                 cnt++;
                if(mn<=0)
                    break;
                mn*=2;
                if(mn>=temp)
                mn=temp;
                x*=2;
                //cout<<x<<endl;

            }
           cout<<cnt+n-1<<endl;


        }


    }

return 0;
}
