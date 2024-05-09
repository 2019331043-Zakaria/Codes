#include<bits/stdc++.h>
#define pb push_back
#define test int t; cin>>t; while(t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
using namespace std;

int main()
{
      fast

       int n,k,cnt1=0,cnt2=0;
       string s,t;
       cin>>n>>k>>s;
       for(int i=0;i<s.length();i++)
       {
          if(s[i]=='(')
          {
              cnt1++;
              if(cnt1<=k/2)
                t+=s[i];
          }
          else
          {
              cnt2++;
              if(cnt2<=k/2)
                t+=s[i];
          }

       }
       cout<<t<<endl;
    return 0;
}

