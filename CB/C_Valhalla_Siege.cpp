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

         string temp="";

         while(s.size())
         {
             temp+=s.back();

             if(temp.size()==5)
             {
                reverse(temp.begin(), temp.end());

                if(temp=="dream" || temp=="erase")
                {
                    temp="";
                }
                reverse(temp.begin(), temp.end());
             }
             
             if(temp.size()==6)
             {
                reverse(temp.begin(), temp.end());

                if(temp=="eraser")
                {
                    temp="";
                }
                reverse(temp.begin(), temp.end());
             }

             if(temp.size()==7)
             {
                reverse(temp.begin(), temp.end());

                if(temp=="dreamer")
                {
                    temp="";
                }
                reverse(temp.begin(), temp.end());
             }

             if(temp.size()>=8)
             {
                 cout<<"NO"<<endl;
                 return ;
             }
             
             s.pop_back();

         }

         if(temp.size())
            cout<<"NO"<<endl;
         else
            cout<<"YES"<<endl;
        
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;
        
       // cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 