#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    ll n,k;
    cin>>n>>k;
    ll a[n],flag=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];

    }
    sort(a,a+n);
    int cnt=0;
    if(n%2==0){
    for(int i=0;i<n;i++)
    {
        if(a[i]!=a[i+1])
            {
                if(a[i]<=k)
                    cnt++;
            }
            if(a[i]>k)
                flag=1;
    }
   if(flag==1)
   {
       int temp=1;
       cout<<"YES"<<endl;
       for(int i=1;i<=n;i++)
        {
            if(i<=k)
                cout<<i<<" ";
            else
                cout<<temp++<<" ";
        }
        cout<<endl;
   }
   else
   {
       if(cnt==k)
        cout<<"NO"<<endl;
       else
       {
          int temp=1;
       cout<<"YES"<<endl;
       for(int i=1;i<=n;i++)
        {
            if(i<=k)
                cout<<i<<" ";
            else
                cout<<temp++<<" ";
        }
        cout<<endl;
       }
   }
    }
else
{
      if(a[n-1]>k)
      {
          flag=1;
          cnt++;
      }
    for(int i=0;i<n-1;i++)
    {
        if(a[i]!=a[i+1])
            {
                if(a[i]<=k)
                    cnt++;
            }
            if(a[i]>k)
                flag=1;
    }
   if(flag==1)
   {
       int temp=1;
       cout<<"YES"<<endl;
       for(int i=1;i<=n;i++)
        {
            if(i<=k)
                cout<<i<<" ";
            else
                cout<<temp++<<" ";
        }
        cout<<endl;
   }
   else
   {
       if(cnt==k)
        cout<<"NO"<<endl;
       else
       {
          int temp=1;
       cout<<"YES"<<endl;
       for(int i=1;i<=n;i++)
        {
            if(i<=k)
                cout<<i<<" ";
            else
                cout<<temp++<<" ";
        }
        cout<<endl;
       }
   }










}

 return 0;
}


