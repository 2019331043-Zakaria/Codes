#include<bits/stdc++.h>
#define pb       push_back
#define mp       make_pair
#define mod      1000000007
#define pi       acos(-1.0)
typedef long long ll;
using namespace std;
int main()
{


     ios::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);


     int n;
     cin>>n;
     int  x,y;
     vector<pair<int,int>>p,q,r;
    for(int i=0;i<n;i++)
    {
         cin>>x>>y;
         p.push_back(make_pair(x,y));
         q.push_back(make_pair(x+y,i));
         r.push_back(make_pair(x-y,i));
    }
    sort(q.begin(),q.end());
    sort(r.begin(),r.end());

    ll ans1=abs(p[q[0].second].first-p[q[n-1].second].first)+abs((p[q[0].second].second-p[q[n-1].second].second));
    ll ans2=abs(p[r[0].second].first-p[r[n-1].second].first)+abs((p[r[0].second].second-p[r[n-1].second].second));

    cout<<max(ans1,ans2)<<endl;




      return 0;
 }
