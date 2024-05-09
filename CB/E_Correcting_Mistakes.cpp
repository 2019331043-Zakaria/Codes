/*
* @Author: Zakaria 
* @Date:   2022-09-22 14:46:29
* @Last Modified time: 2022-09-22 15:34:26
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

int n;
string s, t;

bool ok(string pans)
{
       string temp="";
       int i=0, j=0;
       while(i<n && j<=n)
       {
            if(s[i]==pans[j])
            temp+=s[i], i++, j++;
            else
            j++;
       }

       if(temp!=s)
       return 0;
       
       temp="";
       i=0, j=0;

       while(i<n && j<=n)
       {
            if(t[i]==pans[j])
            temp+=t[i], i++, j++;
            else
            j++;
       }


       if(temp!=t)
       return 0;

       return 1;

}

void Solve()
{
        
       
        cin>>n;

        cin>>s>>t;

        int index=0;

        for(int i=0 ; i<n ; i++)
        {
            if(s[i]!=t[i])
            {
                index=i;
                break;
            }
        }
        
        string pans="";

        for(int i=0 ; i<=index ; i++)
        pans+=s[i];
        for(int i=index ; i<n ; i++)
        pans+=t[i];

  

        int ans=0;
        ans+=ok(pans);
        
        pans="";
        for(int i=0 ; i<=index ; i++)
        pans+=t[i];
        for(int i=index ; i<n ; i++)
        pans+=s[i];

        ans+=ok(pans);

        cout<<ans<<endl;



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