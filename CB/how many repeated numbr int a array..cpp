#include<bits/stdc++.h>
#define test int t; cin>>t; while(t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define sz 200000
typedef long long ll;
using namespace std;
int main()
{
     test
     {
         int n;
         cin>>n;
         int a[n];
         for(int i=0;i<n;i++)
            cin>>a[i];
         sort(a,a+n);
          int cnt=1;
          vector<int>v;
         for(int i=1;i<n;i++)
         {
             if(a[i-1]!=a[i])
                {
                    v.push_back(cnt);
                    cnt=1;
                }
                else
                    cnt++;
         }
         v.push_back(cnt);
         sort(v.begin(),v.end());
         for(int i=0;i<v.size();i++)
            cout<<v[i]<<" ";
         cout<<endl;
     }


return 0;

}
