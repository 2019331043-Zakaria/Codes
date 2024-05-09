/*
* @Author: Zakaria 
* @Date:   2022-10-13 21:42:37
* @Last Modified time: 2022-10-13 23:59:03
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

bool ok(map<int, ll>pans, map<int, ll>lans)
{
       for(int i=1 ; i<=25 ; i++)
       {
          if(lans[i])
            return 1;
       }

       for(int i=1 ; i<=25 ; i++)
       {
           if(pans[i])
            return 0;
       }

       if(pans[0]<lans[0])
         return 1;
       else
        return 0;
}

void Solve()
{
        
        int n;
        cin>>n;

        map<int, ll>pans, lans;
        pans[0]=1;
        lans[0]=1;

        ll lena=0, lenb=0;

        int mnl=0, mxr=0;
        int tem=0;

        for(int i=1 ; i<=n ; i++)
        {
              int type, x;
              cin>>type>>x;
              
              string s;
              cin>>s;


              if(type==1)
              {
              	for(auto i:s)
              	{
              		pans[i-'a']+=x;
              		mnl = (mnl, i-'a');
              		lena+=x;
              		tem=max(tem, i-'a');
              	}
              }
              else
              {
              	  for(auto i:s)
              	  {
              	  	 lans[i-'a']+=x;
              	  	 lenb+=x;
              	  	 mxr=max(mxr, i-'a');
              	  }
              }

             
             if(ok(pans, lans))
                cout<<"YES"<<endl;
             else
                cout<<"NO"<<endl;
        }
      
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