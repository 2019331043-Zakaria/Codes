#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
typedef long long ll;
using namespace std;
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
      int n,k;
      cin>>n>>k;
      string s;
      cin>>s;
       string t[k];

     for(int i=0;i<n;i++)
     {
         t[i%k]+=s[i];
     }
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<t[i].size();j++)
            cout<<t[i][j];
        cout<<endl;
    }

   }
  return 0;
}
