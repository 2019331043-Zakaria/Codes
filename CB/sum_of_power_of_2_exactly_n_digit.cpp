#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
 
        ios::sync_with_stdio(false);
        cin.tie(0); 

      

             int n,k;
             cin>>k>>n;
             
            

             int temp=__builtin_popcount(k);

             if(n<temp||n>k)
              cout<<"NO\n"<<endl;
            else
            {
                 priority_queue<int>pq;

                 int x=1;
                 while(k)
                 {
                    if(k&1)
                      pq.push(x);

                    x*=2;
                    k>>=1;

                 } 

                 while(pq.size()<n)
                 {
                    int temp=pq.top();
                    pq.pop();
                    pq.push(temp/2);
                    pq.push(temp/2);
                 }
                   
                   cout<<"YES\n";
                 while(!pq.empty())
                 {
                    int x=pq.top();
                 
                    cout<<x<<" ";
                   pq.pop();
                 }

                 

            }
        
         

     return 0;           
        
}
