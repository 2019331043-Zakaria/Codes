/*
* @Author: Zakaria 
* @Date:   2022-10-05 22:04:09
* @Last Modified time: 2022-10-05 23:18:21
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
        
        int n, op;
        cin>>n>>op;

        string s;
        cin>>s;


        if(op<=3)
        {
        	  for(int i=1 ; i<=op ; i++)
	          {
	                 
	                 string temp=s;

	                 for(int i=0 ; i<n ; i++)
	                 {
	                     if(s[i]=='1')
	                     {
	                         if(i-1>=0 && s[i-1]=='0')
	                            temp[i-1]='1';
	                         if(i+1<n && s[i+1]=='0')
	                            temp[i+1]='1';

	                         temp[i]='0';
	                     }
	                 }

	                 s=temp;
	          }

	          cout<<s<<endl;
	          return ;
        }

            for(int i=1 ; i<=3 ; i++)
	          {
	                 
	                 string temp=s;

	                 for(int i=0 ; i<n ; i++)
	                 {
	                     if(s[i]=='1')
	                     {
	                         if(i-1>=0 && s[i-1]=='0')
	                            temp[i-1]='1';
	                         if(i+1<n && s[i+1]=='0')
	                            temp[i+1]='1';

	                         temp[i]='0';
	                     }
	                 }

	                 s=temp;
	          }


	          op-=3;


        vector<int>ones;

        int first=n, last=0;

        for(int i=0 ; i<n ; i++)
        {
        	 if(s[i]=='1')
        	 	ones.push_back(i), first=min(first, i), last=max(last, i);
        }

        if(ones.size()==0)
        {
        	 cout<<s<<endl;
        	 return ;
        }

        vector<pair<int, int> > segment ;

        for(int i=1 ; i<ones.size() ; i++)
        {
        	segment.push_back({ones[i-1], ones[i]});
        }

        for(auto i:segment)
        {
        	 int l=i.f;
        	 int r=i.s;
            
             int cnt=0;
       	     while(l<=r)
       	     {
                  if(cnt>op)
                  	break;

                 if(op%2)
                 {
                  if(cnt%2==0)
                  	s[l]='0', s[r]='0';
                  else
                  	s[l]='1', s[r]='1';
                  cnt++;
                 }
                 else
                 {
                 	    if(cnt%2)
	                  	s[l]='0', s[r]='0';
	                  else
	                  	s[l]='1', s[r]='1';
	                  cnt++;
                 }

                  l++;
                  r--;
       	     }
        }

        for(int i=first, cnt=0 ; i>=0; i--)
        {
        	      if(op%2)
                 {
                  if(cnt%2==0)
                  	s[i]='0';
                  else
                  	s[i]='1';
                  cnt++;
                 }
                 else
                 {
                 	    if(cnt%2)
	                  	s[i]='0';
	                  else
	                  	s[i]='1';
	                  cnt++;
                 }
        }

        for(int i=last, cnt=0 ; i<n ; i++)
        {
        	   if(op%2)
                 {
                  if(cnt%2==0)
                  	s[i]='0';
                  else
                  	s[i]='1';
                  cnt++;
                 }
                 else
                 {
                 	    if(cnt%2)
	                  	s[i]='0';
	                  else
	                  	s[i]='1';
	                  cnt++;
                 }
        }


        cout<<s<<endl;
      
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