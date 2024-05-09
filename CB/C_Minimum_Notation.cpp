/*
* @Author: Zakaria 
* @Date:   2022-09-25 21:12:31
* @Last Modified time: 2022-09-25 21:50:27
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

        int n=s.size();

        map<char, int>pos;
        s='*'+s;

        for(int i=1 ; i<=n ; i++)
        {
        	
        	pos[s[i]]=i;
        }
        

        string temp="";

        int val=0;

        string ans="";

        for(char c='0' ; c<='9' ; c++)
        {
        	 int last=pos[c];

        	 if(last<=val)
        	 	continue;

        	 for(int j=val+1 ; j<=last ; j++)
        	 {
        	 	 if(s[j]!=c)
        	 	 temp+=min(++s[j], '9');
        	 	 else
        	 	 	ans+=c;
        	 }
        	 val=last;
        }

        
        sort(temp.rbegin(), temp.rend());
        reverse(ans.begin(), ans.end());

        while(ans.size())
        {
        	if(temp.size())
        	{
        		if(temp.back()<=ans.back())
        			cout<<temp.back(), temp.pop_back();
        		else
        			cout<<ans.back(), ans.pop_back();
        	}
        	else
        	{
        		cout<<ans.back(), ans.pop_back();
        	}
        }

        while(ans.size())
        	cout<<ans.back(), ans.pop_back();
        while(temp.size())
        	cout<<temp.back(), temp.pop_back();
        cout<<endl;



      
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