#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    vector<pair<ll,ll>>p;
    ll n;
    cin>>n;
     vector<long double>v;
     ll x,y;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        p.push_back(make_pair(x,y));
        long double temp=(long double)x/(long double)y;
        v.push_back(temp);

    }
     for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1-i;j++)
            {
            if(v[j+1]>v[j])
            {
                swap(v[j+1],v[j]);
                swap(p[j+1],p[j]);
            }
        }
    }
 for(int i=0;i<n;i++)
    cout<<p[i].first<<" "<<p[i].second<<endl;


return 0;
}
