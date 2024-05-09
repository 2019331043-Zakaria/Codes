/*
* @Author: Zakaria 
* @Date:   2022-12-30 21:22:58
* @Last Modified time: 2023-01-02 22:19:30
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
bool is_prime(int x)
{
    if(x==2)
        return 1;
    
    for(int i=2 ; i*i<=x; i++)
    {
         if(x%i==0)
            return 0;
    }

    return 1;
}
void Solve()
{
        
        int n;
        cin>>n;

        ll a[n];
        set<ll>st;

        for(int i=0 ; i<n ; i++)
        	cin>>a[i], st.insert(a[i]);

        
        if(st.size()==n)
        {
        	  
        	  for(int i=2 ; i<=n ; i++)
              {
                 if(is_prime(i))
                 {
                      vector<int>mcount(i);

                      for(auto j:a)
                        mcount[j%i]++;
                      bool ok = 0;
                      for(int k=0 ; k<i ; k++)
                      {
                        if(mcount[k]<2)
                            ok = 1;
                      }

                      if(!ok)
                      {
                        cout<<"NO"<<endl;
                        return ;
                      }
                 }
              }

              cout<<"YES"<<endl;
              return ;

        }

        cout<<"NO"<<endl;
      
      
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