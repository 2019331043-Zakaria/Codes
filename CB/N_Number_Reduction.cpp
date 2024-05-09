/*
* @Author: Zakaria 
* @Date:   2022-11-27 21:10:59
* @Last Modified time: 2022-11-28 19:08:10
*/
#include <bits/stdc++.h>
#define  pb          push_back
#define  f           first
#define  s           second
#define  pi          acos(-1.0)
#define  LCM(a,b)    a*b/__gcd(a,b)
#define  GCD(a,b)    __gcd(a,b)
#define  sof         sizeof
#define  endl        '\n'
#define  eps         1e-6
typedef long long ll;
using namespace std;

const int mod = 1e9+7;
const int N = 2e5+6;

void Solve()
{
       int n;
       string s;
       cin>>s;
       n = s.size();

       s = '*' + s;
       
       int k;
       cin>>k;

       map<char, vector<int> >m;

       for(int i=n ; i>=1 ; i--)
        m[s[i]].push_back(i);

       int rem = n - k;
       
       string ans = "";

       int last = 0;

       for(char i='1' ; i<='9' ; i++)
       {
           if(m[i].size() && rem)
           {
                int pans = m[i].back();
                if(n - pans + 1>=rem && pans>last)
                {
                    ans+=i;
                    rem--;
                    m[i].pop_back();
                    last = pans;
                    break;
                }
           }
       }

   //    cout<<rem<<endl;

       for(int k=rem ; k>=1 ; k--)
       {
              for(char i='0' ; i<='9' ; i++)
               {
                   while(m[i].size())
                   {
                      if(m[i].back()<last)
                        m[i].pop_back();
                      else
                        break;
                   }
               }


              bool ok = 0;
              char digit = '*';
               for(char i='0' ; i<='9' ; i++)
               {
                   if(m[i].size())
                   {
                        int pans = m[i].back();

                        if(n - pans + 1>=k && pans>last)
                        {
                            ans+=i;
                            last = pans;
                            ok=1;
                            digit = i;
                            m[i].pop_back();
                            break;
                        }

                   }
               }
             


       }


       cout<<ans<<endl;
       
       
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;
        
        cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 