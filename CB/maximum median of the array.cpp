#include<bits/stdc++.h>
#define test int t; cin>>t; while(t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define endl "\n"
typedef long long ll;
using namespace std;
int main()
{
    ll n,k;
    cin>>n>>k;
    ll a[n];
    vector<ll>c;

    for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
      sort(a,a+n);
      for(int i=n/2;i<n;i++)
        c.push_back(a[i]);

     vector<ll>v;
     for(int i=1;i<c.size();i++)
     {
         v.push_back(c[i]-c[i-1]);
     }
     ll temp=0;
     int x=c.size()-1;
     int flag=0;
     for(int i=0;i<v.size();i++)
     {
         temp+=(i+1)*v[i];
         //cout<<temp<<" ";

         if(temp>k)
         {
             flag=1;
             x=i;
             break;
         }
         else if(temp==k)
         {
             flag=1;
             x=i+1;
             break;

         }

     }
     ll y=c[x];
     //cout<<y<<endl;
     ll cnt;
     reverse(c.begin(),c.end());

     for(int i=0;i<c.size();i++)
     {
         if(c[i]==y)
         {
             cnt=c.size()-i-1;
             break;
         }
     }
     ll rem=0;

     sort(c.begin(),c.end());
   for(int i=0;i<=cnt;i++)
    {
        rem+=(y-c[i]);
    }
    rem=k-rem;
    //cout<<rem<<endl;
    cout<<y+(rem/(cnt+1))<<endl;

  return 0;
}
