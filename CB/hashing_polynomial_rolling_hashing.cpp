/*
* @Author: Zakaria
* @Date:   2021-09-14 15:44:21
* @Last Modified time: 2022-04-01 02:51:43
*/
//https://www.spoj.com/problems/SUB_PROB/
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


ll dp[1000001];
ll inv[1000001];
ll dp1[1000001];
ll inv1[1000001];
ll power(ll a , ll n)
{
   ll result = 1;
 
   while(n)
   {
      if(n & 1) result = (result * a) % mod;
 
      n >>= 1;
      a = (a * a) % mod;
   }
 
   return result;
}
 
 
void init(string input_string)
{
   ll p = 31;
   ll p_power = 1;
   inv[0] = 1;
   dp[0] = (input_string[0] - 'a' + 1);
 
 
   for(int i=1;i<input_string.size();i++)
   {
      char ch = input_string[i];
 
      p_power = (p_power * p) % mod;
      inv[i] = power(p_power , mod - 2);
 
      dp[i] = (dp[i-1] + (ch - 'a' + 1)*p_power) % mod;
   }
}
 
ll substringHash(int L , int R)
{
   int result = dp[R];
 
   if(L > 0) result -= dp[L-1];
   result+=mod;
   result%=mod;
   result = (result * inv[L]) % mod;
 
   return result;
}


void init1(string input_string)
{
   ll p = 31;
   ll p_power = 1;
   inv1[0] = 1;
   dp1[0] = (input_string[0] - 'a' + 1);
 
 
   for(int i=1;i<input_string.size();i++)
   {
      char ch = input_string[i];
 
      p_power = (p_power * p) % mod;
      inv1[i] = power(p_power , mod - 2);
 
      dp1[i] = (dp1[i-1] + (ch - 'a' + 1)*p_power) % mod;
   }
}
 
ll substringHash1(int L , int R)
{
   int result = dp1[R];
 
   if(L > 0) result -= dp1[L-1];
   result+=mod;
   result%=mod;
 
   result = (result * inv1[L]) % mod;
 
   return result;
}


void Solve()
{
          
        
         string s;
         cin>>s;

         init(s);

         int n;
         cin>>n;

         for(int i= 1 ; i<=n ; i++)
         {
               string t;
               cin>>t;
             
              
               init1(t);

               ll temp = substringHash1(0,t.size()-1);
            
               bool ok=0;

               int l=0,r=t.size()-1;
               while(r<s.size())
               {
                   
                    if(substringHash(l,r)==temp)
                    {
                       cout<<"Y"<<endl;
                       ok=1;
                       break;
                    }
                    l++,r++;
               }
               
               if(!ok)
                  cout<<"N"<<endl;

         }
         
         
        
      
}

int main()
{
      ios::sync_with_stdio(false);
      cin.tie(0);

    
      int tt=1;
    //  cin>>tt;
      while(tt--)
      {
            Solve();
      }

      return 0;

}

