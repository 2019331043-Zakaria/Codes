/*
* @Author: Zakaria 
* @Date:   2022-09-23 11:44:06
* @Last Modified time: 2022-09-23 12:34:03
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

        map<char, int > v;

        for(int i=0 ; i<n ; i++)
        {
        	v[s[i]]++;
        }

        string distinct="";

        for(char i='a' ; i<='z' ; i++)
        {
        	if(v[i])
        		distinct+=i;
        }

        int i=0, j=(distinct.size()+1)/2;

        string ans="";

        vector<string> pans;


        while(j<distinct.size())
        {
        	if(abs(distinct[i] - distinct[j])==1)
        	{
        		cout<<"No answer"<<endl;
        		return ;
        	}
        	string temp="";
        	while(v[distinct[i]])
        	temp+=distinct[i], v[distinct[i]]--;
        	while(v[distinct[j]])
        	temp+=distinct[j], v[distinct[j]]--;
        	i++;j++;
        	pans.push_back({temp});
        }

        while(pans.size())
        {
        	ans+=pans.back();
        	pans.pop_back();
        }

        if(distinct.size()==1)
        {
        	cout<<s<<endl;
        	return ;
        }



        if(distinct.size()%2)
        {
        	 char c=distinct[distinct.size()/2];
        	 bool ok=0;

        	 if(abs(c-ans[0])!=1)
        	 {
        	 	   string temp="";
        	 	   while(v[c])
        	 	   	temp+=c, v[c]--;
        	 	   ans=temp+ans;
        	 }
        	 else if(abs(c-ans.back())!=1)
        	 {
        	 	   while(v[c])
        	 	   	ans+=c, v[c]--;
        	 }
        	 else
        	 {

		        	 for(int i=1 ; i<ans.size() ; i++)
		        	 {
		                  if(abs(ans[i-1] - c)!=1 && abs(c - ans[i])!=1)
		                  {
		                  	  string temp="";
		                  	  while(v[c])
		                  	  	temp+=c, v[c]--;

		                  	  string res="";

		                  	  for(int k=0 ; k<i ; k++)
		                  	  	res+=ans[k];
		                  	  res+=temp;
		                  	  for(int k=i ; k<ans.size() ; k++)
		                  	  	res+=ans[k];

		                  	 ans=res;

		                  	 ok=1;
		                  	 break;
		                  }
		        	 }

		        	 if(!ok)
		        	 {
		        	 	cout<<"No answer"<<endl;
		        	 	return ;
		        	 }

        	 }
        }

        cout<<ans<<endl;

         
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