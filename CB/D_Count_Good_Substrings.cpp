/*
* @Author: Zakaria 
* @Date:   2022-12-04 15:04:05
* @Last Modified time: 2022-12-04 16:42:40
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

      ll tot = 0;

      ll EvenA = 0, OddA = 0, EvenB = 0, OddB = 0;

      ll odd = 0, even = 0;

      for(int i=1 ; i<=n ; i++)
      {

      	 if(s[i-1]=='a')
      	 {
             if(i%2)
             {
             	odd+=OddA;
             	even+=EvenA;
             	OddA++;
             }
             else
             {
             	even+=OddA;
             	odd+=EvenA;
             	EvenA++;
             }
      	 }
      	 else
      	 {
             if(i%2)
             {
             	odd+=OddB;
             	even+=EvenB;
             	OddB++;
             }
             else
             {
             	even+=OddB;
             	odd+=EvenB;
             	EvenB++;
             }
      	 }

      	
      }

      cout<<even<<" "<<odd+n<<endl;
      
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