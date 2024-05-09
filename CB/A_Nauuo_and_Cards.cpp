/*
* @Author: Zakaria 
* @Date:   2022-09-21 12:01:53
* @Last Modified time: 2022-09-21 15:42:59
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

        priority_queue<int,  vector<int>, greater<int>  > pq;
        
        int a[n+1];
        int pos1=n+1;

        for(int i=1 ; i<=n ; i++)
        {
            int x;
            cin>>x;

            if(x)
                pq.push(x);
        }

        vector<int>v, store;
       
        for(int i=0 ; i<n ; i++)
        {
            int x;
            cin>>x;
        
            if(x==1)
                pos1=i;

            v.push_back(x);
        }

        if(is_sorted(v.begin(), v.end()) && v[0]==1 && v.back()==n)
        {
            cout<<0<<endl;
            return ;
        }

        if(pos1<n)
        {
            vector<int>copy;
            copy = v;

            priority_queue<int,  vector<int>, greater<int>  > pqcopy;

            pqcopy=pq;

            

            vector<int>pans;
            

            for(int i=pos1 ; i<n ; i++)
            {

                pans.push_back(copy[i]);
            
            }

           
            int lans=pqcopy.size();
            
            for(int i=0 ; i<pos1 ; i++)
            {
                if(pqcopy.size()==0)
                {
                    break;
                }
                if(pqcopy.top())
                pans.push_back(pqcopy.top());
                pqcopy.pop();
                if(copy[i])
                pqcopy.push(copy[i]);
                
            }

            
            while(pqcopy.size())
            {
                if(pqcopy.top())
                    pans.push_back(pqcopy.top());
                 pqcopy.pop();
            }

            int cnt=1;

            bool ok=true;

            for(auto i:pans)
            {
                if(i==cnt)
                    cnt++;
                else
                {
                    ok=false;
                    break;
                }
            }
            if(cnt<=n)
                ok=false;
            
            if(ok)
            {
                cout<<pos1<<endl;
                return ;
            }

           
        }

        reverse(v.begin(), v.end());
        
        int cnt=1;

        int ans=0;
        pq.push(n+5);
        
        while(1)
        {
             while(pq.top()!=cnt)
             {
                 if(v.back())
                 {
                    pq.push(v.back());
                 }
                 v.pop_back();
                 ans++;
             }

             while(cnt == pq.top())
             {
                 
                 ans++;
                 pq.pop();
                 if(v.size())
                 {
                    if(v.back())
                        pq.push(v.back());

                    v.pop_back();
                 }

                 cnt++;
             }

             if(cnt>n)
                break;
        }

        cout<<ans<<endl;
        


      
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;
        
       // cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 