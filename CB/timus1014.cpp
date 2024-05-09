#include<bits/stdc++.h>
#define pb       push_back
#define mp       make_pair
#define mod      1000000007
#define pi       acos(-1.0)
typedef long long ll;
using namespace std;
int main()
{
     
      
      int t;
      cin>>t;
      while(t--){
        int n;
        cin>>n;
        ll a[n];
        vector<pair<ll,ll>>p;
        for(int i=0;i<n;i++)
        {
           cin>>a[i];
           p.push_back(make_pair(a[i],i));

        }

        
        sort(p.begin(),p.end());
        reverse(p.begin(),p.end());

        ll ans=(n*(n-1))/2;
        ans--;
        cout<<ans<<endl;
        ll sum=0,cnt=0;
        for(int i=0;i<p.size();i++)
        {
            if(p[i].second-cnt<n-i)
            {
               
               sum+=(n-i-p[i].second-1+cnt);
               cnt++;
            }
        }
        cout<<sum<<endl;
       
       if(sum>ans)
        cout<<"NO"<<endl;
      else
        cout<<"YES"<<endl;
}

     return 0;
}