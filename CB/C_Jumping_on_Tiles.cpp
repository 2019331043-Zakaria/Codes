/*
* @Author: Zakaria 
* @Date:   2022-09-12 20:53:03
* @Last Modified time: 2022-09-12 21:49:51
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
        
     
        map<int, char>m;

        for(char c='a' ; c<='z' ; c++)
       	  m[c]=c-'a'+1;
        
        string s;
        cin>>s;
       
        
        

        int n=s.size();

        s='*'+s;

        if(n==2)
        {
        	cout<<abs(m[s[1]]- m[s[2]])<<" "<<2<<endl;
        	cout<<1<<" "<<2<<endl;
        	return ;
        }

        vector< int  >v;
        int cost=1e9;
        for(int i=2 ; i<=n ; i++)
        {
        
            cost=min(cost, abs(m[s[1]]-m[s[i]]) + abs(m[s[i]]-m[s[n]]));

        }
        
        for(int i=2 ; i<n ; i++)
        {
        	 int temp=abs(m[s[1]]-m[s[i]]) + abs(m[s[i]]-m[s[n]]);
        	 if(temp==cost)
        	 	v.push_back(i);
        }

        

        cout<<cost<<" "<<v.size()+2<<endl;
        

       
        cout<<1<<" ";
        
        vector<pair<int, int> >boro , choto;
        
        int totb=0, totch=0;
        for(auto i:v)
        {
        	if(m[s[i]]>=m[s[n]])
        		boro.push_back({m[s[i]], i}), totb=max(totb, abs(m[s[i]]-m[s[n]]));
        	else
        		choto.push_back({m[s[i]], i}), totch=max(totch, abs(m[s[n]]- m[s[i]]));
        }
        
        sort(boro.begin(), boro.end());
        sort(choto.begin(), choto.end());
        
        if(totb<=totch)
        {
        	 for(auto i:choto)
        		cout<<i.s<<" ";

        	 while(boro.size())
        	 {
        	 	cout<<boro.back().s<<" ";
        	 	boro.pop_back();
        	 }


        }
        else
        {
        	while(boro.size())
        	 {
        	 	cout<<boro.back().s<<" ";
        	 	boro.pop_back();
        	 }

        	for(auto i:choto)
        		cout<<i.s<<" ";
        }

        
        

        cout<<n<<endl;
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