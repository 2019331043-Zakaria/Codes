#include<bits/stdc++.h>
#define  MAX         1000002

typedef long long ll;
using namespace std;
int dp[MAX];
int len[MAX];

int main()
{
 
        ios::sync_with_stdio(false);
        cin.tie(0); 

        
        
            string s;
            cin>>s;
            
            int n=s.size();
            

            

            for(int i=0;i<=n;i++)
              dp[i]=-1,len[i]=-1;
            

            stack<int>st;
            st.push(-1);

            for(int i=0;i<n;i++)
            {
               if(s[i]=='(')
                st.push(i);
               else
               {
                   if(st.top()!=-1)
                   {
                       dp[i]=st.top();

                       if(dp[dp[i]-1]!=-1)
                        dp[i]=dp[dp[i]-1];

                      len[i-dp[i]+1]=dp[i];
                      st.pop();
                   
                   }
               }
            }
              
                int ans=0;
                int temp;
              for(int i=0;i<=n;i++)
               {
                  if(len[i]!=-1)
                    ans=i,temp=len[i];
               }

           if(ans==0)
            cout<<"There is only empty substring exist\n"<<endl;
          else
           cout<<"the length of the substring is "<< ans<<" And its starting at position "<<temp<<" (0) base indexing "<<endl;
        


     return 0;           
        
}

