#include<bits/stdc++.h>
#define pb push_back
#define test int t; cin>>t; while(t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
using namespace std;

int main()
{
      fast
      test
      {
           string s;
           cin>>s;
           int res=0;
              for(ll init=0;;init++)
            {
               int cur=init;
               bool ok =true;

                   for(int i=0;i<s.length();i++)
                   {
                       res++;
                       if(s[i]=='+')
                        cur++;
                       else
                        cur--;
                        cout<<cur<<endl;
                       if(cur<0)
                       {
                           ok=false;
                           break;
                       }
                   }
                   if(ok)
                    break;

                  // cout<<res<<endl;
            }






      }

    return 0;
}
