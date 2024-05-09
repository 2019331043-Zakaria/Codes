/*
* @Author: Zakaria 
* @Date:   2022-10-07 22:47:28
* @Last Modified time: 2022-10-07 23:03:06
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
        int r1,c1, r2,c2, r3, c3;
        cin>>r1>>c1>>r2>>c2>>r3>>c3;

        int x, y;
        cin>>x>>y;

        int tempx, tempy;

        if(r1==r2)
        	tempx=r1;
        if(r1==r3)
        	tempx=r1;

        if(r2==r3)
        	tempx=r2;

        if(c1==c2)
        	tempy=c1;
        if(c1==c3)
        	tempy=c1;
        if(c2==c3)
        	tempy=c3;

        if(x==r1 && y==c1 || x==r2 && y==c2 || x==r3 && y==c3 )
        {
        	   cout<<"YES"<<endl;
        	   return ;
        }

        map<pair<int, int>, int > m;
        m[{1,1}]=1;
        m[{1, 2}]=1;
        m[{2, 1}]=1;

        int ok=0;
        ok+=m[{r1, c1}];
        ok+=m[{r2, c2}];
        ok+=m[{r3, c3}];

        if(ok==3)
        {
        	cout<<"NO"<<endl;
        	return ;
        }
        m.clear();

        m[{n,n}]=1;
        m[{n-1, n}]=1;
        m[{n, n-1}]=1;

         ok=0;
        ok+=m[{r1, c1}];
        ok+=m[{r2, c2}];
        ok+=m[{r3, c3}];

        if(ok==3)
        {
        	cout<<"NO"<<endl;
        	return ;
        }



        if(x%2==tempx%2 || y%2==tempy%2)
        	cout<<"YES"<<endl;
        else
        {
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