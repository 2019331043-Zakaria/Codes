#include<bits/stdc++.h>
#define test int t; cin>>t; while(t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define mp make_pair
typedef long long ll;
using namespace std;
int main()
{
     int n;
     cin>>n;
     int a[n];
     for(int i=0;i<n;i++)
     cin>>a[i];
     sort(a,a+n);

     vector<int>mother;
     mother.push_back(a[0]);
     for(int i=1;i<n;i++)
     {
         if(a[i]!=a[i-1])
            mother.push_back(a[i]);
     }
     map<int,int>m;
     vector<int>comp;
     int assgined=0,x;
     for(int i=0;i<n;i++)
     {
        x=a[i];
        if(m.find(x)==m.end())
        {
            m[x]=assgined;
            assgined++;
        }
       x=m[x];
       comp.push_back(x);

     }
      int p=mother.size();
      int cnt[p];
      memset(cnt,0,sizeof(cnt));
      for(int i=0;i<comp.size();i++)
      {
          cnt[comp[i]]++;
      }

    for(int i=0;i<p;i++)
    cout<<mother[i]<<" repeated "<<cnt[i]<<" times "<<endl;;


   return 0;
}


