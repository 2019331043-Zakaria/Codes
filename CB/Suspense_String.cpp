/*
* @Author: Zakaria 
* @Date:   2022-10-05 20:32:49
* @Last Modified time: 2022-10-05 20:37:57
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

       deque<char>q;

       int cnt=0;

       int i=0, j=n-1;

       while(i<=j)
       {
       	   if(cnt%2==0)
       	   {
       	   	    if(s[i]=='0')
       	   	    	q.push_front('0');
       	   	    else
       	   	    	q.push_back('1');
       	   	    i++;
       	   }
       	   else
       	   {
       	   	    if(s[j]=='1')
       	   	    	q.push_front('1');
       	   	    else
       	   	    	q.push_back('0');
       	   	    j--;
       	   }

       	   cnt++;
       }

       while(q.size())
       	cout<<q.front(), q.pop_front();
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