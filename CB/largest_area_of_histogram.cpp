#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
 
        ios::sync_with_stdio(false);
        cin.tie(0); 
        

        int n;
        cin>>n;
        ll a[n];

        for(int i=0;i<n;i++)
          cin>>a[i];

        stack<ll>st;
        ll ans=0;
        ll temp=0;

        int i=0;
        while(i<n)
        {
           if(st.empty()||a[st.top()]<=a[i])
            st.push(i++);
           else
           {
              ll tp=st.top();
              st.pop();
              temp=a[tp]*(st.empty() ? i : i-st.top()-1);
              ans=max(ans,temp);
           }
        }

        while(!st.empty())
        {
           int tp=st.top();
           st.pop();
           temp=a[tp]*(st.empty() ? i : i-st.top()-1);
           ans=max(ans,temp);

        }

        cout<<"Area is "<<ans<<endl;
        
        

            
        return 0;
}
