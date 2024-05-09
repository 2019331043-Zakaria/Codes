/*
* @Author: Zakaria 
* @Date:   2022-06-13 22:42:16
* @Last Modified time: 2022-06-13 22:51:35
*/
#include <bits/stdc++.h>
#define  pb          push_back
#define  f           first
#define  s           second
#define  pi          acos(-1.0)
#define  LCM(a,b)    a*b/__gcd(a,b)
#define  GCD(a,b)    __gcd(a,b)
#define  mod         1000000007
#define  sof         sizeof
#define  endl        '\n'
#define  MAX         2000002
typedef long long ll;
using namespace std;

struct PT
{
       double x, y;
       PT(){ x = y = 0 ;}
       PT(double _x , double _y) { x = _x , y = _y ; }
       PT operator + (const PT &p)  const
	   {
	        return PT(x+p.x, y+p.y);
	   }
	   PT operator - (const PT &p)  const
	   {
           return PT(x-p.x, y-p.y);
       }
       PT operator * (double c)     const
	   {
	        return PT(x*c,   y*c  );
	   }
	   PT operator / (double c)     const
       {
	        return PT(x/c,   y/c  );
       }



};

int main()
{
        vector<PT>v;
        v.push_back({1,2});
        v.push_back({2,4});


        PT x = v[0]+v[1];

        cout<<x.x<<" "<<x.y<<endl;


        return 0;
}