/*
* @Author: Zakaria 
* @Date:   2022-10-15 20:55:52
* @Last Modified time: 2022-10-15 21:37:14
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

       int a[n+1];

       for(int i=1 ; i<=n ; i++)
       	cin>>a[i];

       int rem=n;
       int tot=0;
       
       vector<pair<int, int> >ans;

       for(int i=2 ; i<=n ; i++)
       {
           if(a[i]<a[i-1])
           {
           	    int baki = a[i-1]-a[i];
                ans.push_back({baki, i});
           }
       }

       sort(ans.begin(), ans.end());

       int res[n+1];

       for(int i=1 ; i<=n ; i++)
       	res[i]=1;

       int index=n;

       while(ans.size())
       {
       	  if(index<1)
       	  	break;
       	  
       	    int value=ans.back().f;
       	    int pos=ans.back().s;
            
       	    while(value>0)
       	    {  
       	    	res[index]=pos;
       	    	value-=index;
       	    	index--;
       	    }

       	    ans.pop_back();
       }

       for(int i=1 ; i<=n ; i++)
       	cout<<res[i]<<" ";

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