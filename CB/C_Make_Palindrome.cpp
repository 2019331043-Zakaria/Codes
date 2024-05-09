/*
* @Author: Zakaria 
* @Date:   2022-09-10 15:54:33
* @Last Modified time: 2022-09-10 16:41:57
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

        int n = s.size();
        vector<char>odd, even;
        map<char, int> m;
      
      
      	 
      	char limbo;


        if(n%2)
        {        
             for(auto i:s)
        	 	m[i]++;

        	 for(char i='a' ; i<='z' ; i++)
        	 {
                if(m[i]%2)
                	odd.push_back(i);
                else
                	even.push_back(i);
        	 }

        	int l=0, r=odd.size()-1;
        	while(l<r)
        	{
        		 m[odd[l]]++;
        		 m[odd[r]]--;
        		 l++, r--;
        	}

            limbo=odd[l];
           
        }
        else
        {
        	
        	 for(auto i:s)
        	 	m[i]++;
        	 
        	 for(char i='a' ; i<='z' ; i++)
        	 {
                if(m[i]%2)
                	odd.push_back(i);
                else
                	even.push_back(i);
        	 }

        	 
         	int l=0, r=odd.size()-1;
        	while(l<r)
        	{
        		 m[odd[l]]++;
        		 m[odd[r]]--;
        		 l++, r--;
        	}
        }

       
        
        int l=0, r=n-1;
        while(l<r)
        {
        	 bool ok=0;
             for(char i='a' ; i<='z' ; i++)
             {
             	if(m[i]>=2)
                {
                     s[l]=i;
                     s[r]=i;
                     l++;
                     r--;
                     m[i]--;
                     m[i]--;
                     ok=1;
                     break;
                }
            }
            if(!ok)
            	break;
        }



        if(n%2)
        {
        	s[n/2]=limbo;
        }

        cout<<s<<endl;
      
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;
        //cin>>tt;
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 