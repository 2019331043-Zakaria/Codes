/*
* @Author: Zakaria 
* @Date:   2022-12-13 14:51:25
* @Last Modified time: 2022-12-13 15:18:13
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
        

        string s;
        cin>>s;

   
        stack<char>st;


        int ans = 0;

        for(int i=0 ; i<s.size() ; i++)
        {
           if(s[i]=='(')
            st.push(s[i]);
           
           else if(s[i]=='{')
            st.push(s[i]);
           
           else if(s[i]=='[')
           	st.push(s[i]);

           else if(s[i]=='<')
            st.push(s[i]);

           else if(s[i]==')')
           {
           	    if(st.size())
           	    {
           	    	if(st.top()=='(')
           	    		st.pop();
           	    	else
           	    		ans++, st.pop();
           	    }
           	    else
           	    {
           	    	cout<<"Impossible"<<endl;
           	    	return ;
           	    }
           }

           else if(s[i]=='}')
           {
           	   if(st.size())
           	    {
           	    	if(st.top()=='{')
           	    		st.pop();
           	    	else
           	    		ans++, st.pop();
           	    }
           	    else
           	    {
           	    	cout<<"Impossible"<<endl;
           	    	return ;
           	    }
           }

           else if(s[i]==']')
           {
           	    if(st.size())
           	    {
           	    	if(st.top()=='[')
           	    		st.pop();
           	    	else
           	    		ans++, st.pop();
           	    }
           	    else
           	    {
           	    	cout<<"Impossible"<<endl;
           	    	return ;
           	    }
           }

           else if(s[i]=='>')
           {
           	    if(st.size())
           	    {
           	    	if(st.top()=='<')
           	    		st.pop();
           	    	else
           	    		ans++, st.pop();
           	    }
           	    else
           	    {
           	    	cout<<"Impossible"<<endl;
           	    	return ;
           	    }
           }
        }
        if(st.size())
        	cout<<"Impossible"<<endl;
        else
        cout<<ans<<endl;
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;
        
      //  cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 