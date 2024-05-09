/*
* @Author: Zakaria 
* @Date:   2022-10-23 01:29:14
* @Last Modified time: 2022-10-23 11:29:14
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
       cin>>n;

       string s;
       cin>>s;

       s = '*' + s;

       int odd = 0;

       for(auto i:s)
       	odd+=(i=='1');

       if(odd==0 || odd%2)
       {
       	   cout<<"NO"<<endl;
       	   return ;
       }

       //cout<<s<<endl;

       if(s.back()=='0')
       {
              int last = n;

              for(int i=n ; i>=1 ; i--)
              {
                  if(s[i]=='1')
                  {
                       last=i;
                       break;
                  }
              }

              last++;

              vector<pair<int, int> > ans;
              
              vector<int>zero;

              for(int i=last+1 ; i<=n ; i++)
              {
                  zero.push_back(i);
              }
              

              for(int i=1 ; i<last ; i++)
              {
                   if(s[i]=='0')
                   {
                      zero.push_back(i);
                   }
                   else
                   {
                      if(zero.size()==0)
                      { 
                           ans.push_back({i, last});
                      }
                      else
                      {

                            for(int i=1 ; i<zero.size() ; i++)
                            {
                                 ans.push_back({zero[i-1], zero[i]});
                            }
                            ans.push_back({zero.back(), i});
                            ans.push_back({zero[0], last});

                            zero.clear();
                       }

                   }
              }

              cout<<"YES"<<endl;

              for(auto i:ans)
                cout<<i.f<<" "<<i.s<<endl;
       }
       else
       {
              
              vector<int>zero;
              vector<pair<int, int> > ans;

              for(int i=2 ; i<=n ; i++)
              {
                  if(s[i]=='0')
                    zero.push_back(i);
                  else
                  {
                       if(zero.size()==0)
                       {
                          ans.push_back({1, i});
                       }
                       else
                       { 
                           for(int i=1 ; i<zero.size() ; i++)
                            {
                                 ans.push_back({zero[i-1], zero[i]});
                            }
                            ans.push_back({zero.back(), i});
                            ans.push_back({zero[0], 1});

                            zero.clear();
                       }
                  }
              }

              cout<<"YES"<<endl;

              for(auto i:ans)
                cout<<i.f<<" "<<i.s<<endl;


       }
      
      
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