#include<bits/stdc++.h>
#define test int t; cin>>t; while(t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
typedef long long ll;
using namespace std;
int main()
{
     string s;
     map<string,int>m;
     int n;
     cin>>n;
     while(n--)
     {
         cin>>s;
         m[s]++;
     }
     for(auto i=m.begin();i!=m.end();i++)
        cout<<i->first<<" occured "<<i->second<<" time"<<endl;






}
