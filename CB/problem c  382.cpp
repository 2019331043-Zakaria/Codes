#include<bits/stdc++.h>
#define pb push_back
#define test int t; cin>>t; while(t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
using namespace std;

int main()
{
    fast
    int n;
    cin>>n;
    if(n==2)
        cout<<1;

    else if(n%2==0)
        cout<<2<<endl;
    else
    {
        int flag=1;
        int temp=sqrt(n);
        for(int i=2;i<=temp;i++)
        {
            if(n%i==0)
            {
                flag=0;
                break;
            }
        }
        if(flag)
            cout<<1<<endl;
        else
        {
            n=n-2;

            int temp=sqrt(n);
            for(int i=2;i<=temp;i++)
            {
                if(n%i==0)
                {
                    flag=1;
                }
            }
            if(flag)
                cout<<3<<endl;
            else
                cout<<2<<endl;


        }


    }

    return 0;
}

