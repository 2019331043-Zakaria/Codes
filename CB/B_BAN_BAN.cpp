/*
* @Author: Zakaria 
* @Date:   2022-11-04 20:38:49
* @Last Modified time: 2022-11-04 21:03:08
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

        if(n==1)
        {
        	  cout<<1<<endl;
        	  cout<<1<<" "<<2<<endl;
        }
        else
        {
        	  cout<<n-1<<endl;
              string t="BAN";
              string s="1";
              for(int i=1 ; i<=n ; i++)
              	s+=t;



              set<int>v;
              v.insert(2);
              int pans = 6;
              cout<<s<<endl;

              for(int j=1 ; j<n ; j++)
              {
                   swap(s[*v.begin()], s[pans]);
                   cout<<*v.begin()<<" "<<pans<<endl;
                   int temp = *v.begin();

                   v.erase(temp);
                   
                   v.insert(pans);

                   if(pans%3==0)
                   	v.insert(pans-1);

                   pans+=3;
              }

              cout<<s<<endl;
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