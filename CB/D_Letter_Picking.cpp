/*
* @Author: Zakaria 
* @Date:   2022-09-10 08:50:07
* @Last Modified time: 2022-10-04 17:47:36
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
#define  MAX         200002
#define  eps         1e-6
typedef long long ll;
using namespace std;

const int N = 1e5+6;
int n;
string s;
int dp[2005][2005];  // 1-> alice, 2->draw, 3->bob

int foo(int i, int j)
{
        
        if(j-i==1)
        {
            if(s[i]==s[j])
                return 2;
            else
                return 1;
        }

        int &R = dp[i][j];

        if(R!=-1)
            return R;

        //Pick from left-->
        int winleft = 1;
        if(s[i]<s[j])
            winleft = max(winleft,1);
        else 
            winleft = max(winleft, foo(i+1, j-1));

        if(s[i]<s[i+1])
            winleft = max(winleft, 1);
        else
            winleft = max(winleft, foo(i+2, j));
        
        //Pick from right-->
        int winright = 1;
        if(s[j]<s[i])
            winright = max(winright, 1);
        else 
            winright = max(winright, foo(i+1, j-1));

        if(s[j]<s[j-1])
            winright = max(winright, 1);
        else
            winright = max(winright, foo(i, j-2));


        return R = min(winleft, winright);


}

void Solve()
{
        
        
      
        cin>>s;
        
        n = s.size();
        
        for(int i=0 ; i<n ; i++)
            for(int j=0 ; j<n ; j++)
                dp[i][j]=-1;

        if(foo(0, n-1)==1)
            cout<<"Alice"<<endl;
        else if(foo(0, n-1)==2)
            cout<<"Draw"<<endl;
        
      
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