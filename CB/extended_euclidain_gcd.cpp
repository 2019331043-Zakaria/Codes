#include<bits/stdc++.h>
#define pb       push_back
#define mp       make_pair
#define pi       acos(-1.0)
#define test     int t; cin>>t ;while(t--)
typedef long long ll;
using namespace std;
ll x,y;
ll egcd(ll a, ll b, ll *x, ll *y) 
{
   if (b==0)
   {
      *x = 1;
      *y = 0;
      return a;
   }
   ll x1, y1;
   ll gcd=egcd(b,a%b,&x1,&y1);
   *x =y1;
   *y =x1-y1*(a/b);
   return gcd;
}
int main() 
{
   
   int j=0;
   test{
   ll a,b,c;
    
    cin>>a>>b>>c;
   
   ll ans=egcd(a,b,&x,&y);
  
   if(c%ans)
   	cout<<"Case "<<++j<<":No"<<endl;
   else
   	cout<<"Case "<<++j<<":Yes"<<endl;
   }
   
   return 0;
}