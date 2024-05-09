/*
* @Author: Zakaria 
* @Date:   2022-11-06 20:51:39
* @Last Modified time: 2022-11-06 22:27:02
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

        string s, t;
        cin>>s>>t;

        int match = 0, unmatch = 0;

        for(int i = 0 ; i<n ; i++)
        {
        	if(s[i]!=t[i])
        		unmatch++;
        	else
        		match++;
        }

        if(match && unmatch)
        {
        	cout<<"NO"<<endl;
        	return ;
        }


        
        s = '*' + s;
        t = '*' + t;
        
        int temp[n+3];
        memset(temp, 0, sizeof(temp));
        int cnt = 0;

        vector<pair<int, int> > v;



        for(int i=1 ; i<=n ; i++)
        {
            if(s[i]=='0' && cnt%2==0)
            {
                  temp[0]++;
                  temp[i]--;
                  cnt++;
                  v.push_back({i, n});
            }
            else if(s[i]=='1' && cnt%2==1)
            {
            	  temp[0]++;
                  temp[i]--;
            	  cnt++;
            	  v.push_back({i, n});
            }
        }

        for(int i=1 ; i<=n ; i++)
        {
        	temp[i]+=temp[i-1];
        }

       /* for(int i=1 ; i<=n ; i++)
        	cout<<temp[i]<<" ";

        cout<<endl;*/

        for(int i=1 ; i<=n ; i++)
        {
        	if(temp[i]%2)
        	{
        		if(t[i]=='1')
        			t[i]='0';
        		else
        			t[i]='1';
        	}
        }

        if(t[1]=='0')
        {
           v.push_back({1, n});
        }
        else
        {
        	v.push_back({1, 1});
        	v.push_back({2, n});
        }

        cout<<"YES"<<endl;

        cout<<v.size()<<endl;

        for(auto i:v)
        	cout<<i.f<<" "<<i.s<<endl;



      
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