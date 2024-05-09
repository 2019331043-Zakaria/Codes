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
string par;
bool ok(string s)
{
        int n = s.size();
        string pans="";
        for(int i=0 ; i<n ; i++)
        {
                pans+=s[i];

                string lans="";
                for(int j = i+1 ; j<n ; j++)
                {
                    lans+=s[j];
                }

                string res = lans+pans;
              //  cout<<res<<endl;
                string temp = res;
                reverse(temp.begin(), temp.end());

                if(temp == res && res!=par)
                {
                    return 1;
                }
        }

        return 0;

}

void Solve()
{

        string s;
        cin>>s;
        par=s;

        int n = s.size();
        
        vector<char>v;
        string pans="";
        for(int i=0 ; i<n/2 ; i++)
        {
           if(i==0)
            v.push_back(s[i]);
           else
            {
                if(v.back()!=s[i])
                  v.push_back(s[i]);
            }

            pans+=s[i];
        } 


        if(v.size()<=1)
        {
             cout<<"Impossible\n";
        }
        else
        {
           
            if(ok(s))
            {
                 cout<<1<<endl;
                 return ;
            }
            reverse(s.begin(), s.end());
            
            if(ok(s))
            {
                 cout<<1<<endl;
                 return ;
            }

            cout<<2<<endl;
        }
       
      
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