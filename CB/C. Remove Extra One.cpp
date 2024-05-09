/*
* @Author: Zakaria 
* @Date:   2022-04-01 01:08:32
* @Last Modified time: 2022-06-06 01:27:50
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
#define  MAX         500002
typedef long long ll;
using namespace std;


#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key


void Solve()
{  
    
            pbds st;

            int n;
            cin>>n;
            int a[n+1],cnt[n+1];
            for(int i=1 ; i<=n  ; i++)
            {
                cin>>a[i];
                cnt[i]=0;
            }


         
            for(int i=1  ; i<=n ; i++)
            {
                 
               
                 int x=st.size() - st.order_of_key(a[i]);
            
                 if(x==1)
                 {
                      int great = *st.find_by_order(st.size() - 1);
                      cnt[great]++;
                 }
                 else if(x==0)
                 {
                      cnt[a[i]]--;
                 }

                 st.insert(a[i]);
            }
           
          
         
            int ans=n+1, res=-100;

            for(int i=1 ; i<=n ; i++)
            {
                 if(cnt[i]>res)
                 {
                    res=cnt[i];
                    ans=i;
                 }
                 else if(cnt[i]==res)
                 {
                    ans=min(ans,i);
                 }
            }

            cout<<ans<<endl;
           
}

int main()
{
         
          ios::sync_with_stdio(false);
          cin.tie(0);
          


          int tt=1;
       //   cin>>tt;
          while(tt--)
          {
           
             Solve();
          }


          return 0;
        
}

// answer = 1;

