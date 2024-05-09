/*
* @Author: Zakaria 
* @Date:   2022-10-17 22:01:12
* @Last Modified time: 2022-10-17 22:34:23
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

        string s;
        cin>>s;

        if(n==1000000)
        {
        	  string ans="";
              int cnt=0;
        	  for(auto i:s)
        	  {
                    if(i=='1')
                    	ans+='1', cnt++;
        	  }

        	  while(ans.size()<=n && cnt)
        	  {
                  ans+='1';
                  cnt--;
        	  }
        	  while(ans.size()<n)
        	  	ans+='0';

        	  cout<<ans<<endl;
        	  return ;

        }

        int index=n;

        for(int i=0 ; i<n ; i++)
        {
        	if(s[i]=='1')
        	{
        		index=i;
        		break;
        	}
        }

        string ans="";

        for(int i=index ; i<n ; i++)
        	ans+=s[i];

        vector<int>zero;
        reverse(ans.begin(), ans.end());

        for(int i=0 ; i<ans.size() ; i++)
        {
        	if(ans[i]=='0')
        		zero.push_back(i);
        }

        reverse(ans.begin(), ans.end());

        map<int, int>m;

        for(auto i:zero)
          m[i]=1;

        

        map<vector<int>, int>mp;


        for(int i=0 ; i<n ; i++)
        {
        	int cnt=0;
        	vector<int>res;
        	for(int j=i ; j>=0 ; j--)
        	{
                 if(s[j]=='1' && m[cnt]==1)
                 	res.push_back(cnt);
                 cnt++;
        	}

        	reverse(res.begin(), res.end());
        	mp[res]=1;

        	
        }

       
        vector<int>pans;

        for(auto i:mp)
        {
        	pans=i.f;
        }

        

        reverse(ans.begin(), ans.end());

        for(auto i:pans)
        	ans[i]='1';

         reverse(ans.begin(), ans.end());

         bool one=0;

         for(auto i:ans)
         	if(i=='1')
         		one=1;

         if(one==0)
         	cout<<0<<endl;
         else
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