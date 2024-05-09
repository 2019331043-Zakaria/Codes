/*
* @Author: Zakaria 
* @Date:   2022-09-25 20:35:25
* @Last Modified time: 2022-09-27 19:37:41
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

const int MAX = 2e5+6;
ll Hash1[MAX], Pow1[MAX];
const ll Base1=1231;
const ll Mod1=1e9+7;
string s;
int n;

void PowerGenerate1(ll n)
{
     Pow1[0]=1;
     for(int i=1 ; i<=n ; i++)
     {
       Pow1[i]=(Pow1[i-1]*Base1)%Mod1;
     }

}

void GenerateHash1(string text)
{
       Hash1[0]=0;

       for(int i=1 ; i<=text.size() ; i++) //1 base indexing for string
       {
           Hash1[i] = ( (Hash1[i-1]*Base1)%Mod1 + (text[i-1]-'a'+1) ) % Mod1;
       }

}

ll GetHash1(int Left , int Right)
{
     ll HashValue = (Hash1[Right] - (Hash1[Left-1]*Pow1[Right-Left+1])%Mod1)%Mod1 ; //Here pow is base^mod
      HashValue+=Mod1;
      HashValue%=Mod1;

      return HashValue;

}

ll PatternHash1(string pattern)
{
     ll x=0;
     for(int i=1 ; i<=pattern.size() ; i++)
      x = ( (x*Base1)%Mod1 + (pattern[i-1]-'a'+1))%Mod1;
     return x;
}


ll Hash2[MAX], Pow2[MAX];
const ll Base2=1567;
const ll Mod2=1e9+9;

void PowerGenerate2(ll n)
{
     Pow2[0]=1;
     for(int i=1 ; i<=n ; i++)
     {
       Pow2[i]=(Pow2[i-1]*Base2)%Mod2;
     }

}

void GenerateHash2(string text)
{
       Hash2[0]=0;

       for(int i=1 ; i<=text.size() ; i++) //1 base indexing for string
       {
           Hash2[i] = ( (Hash2[i-1]*Base2)%Mod2 + (text[i-1]-'a'+1) ) % Mod2;
       }

}

ll GetHash2(int Left , int Right)
{
      ll HashValue = (Hash2[Right] - (Hash2[Left-1]*Pow2[Right-Left+1])%Mod2)%Mod2 ; //Here pow is base^mod
      HashValue+=Mod2;
      HashValue%=Mod2;

      return HashValue;

}

ll PatternHash2(string pattern)
{
     ll x=0;
     for(int i=1 ; i<=pattern.size() ; i++)
      x = ( (x*Base2)%Mod2 + (pattern[i-1]-'a'+1))%Mod2;
     return x;
}

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int cnt[MAX];

void Solve()
{
        
       
       cin>>s;

       for(int i=0 ; i<s.size() ; i++)
       s[i]=s[i]-'A'+'a';
       
       n=s.size();

       vector<int>z;
       z=z_function(s);
       

      
       map<int, int>m;

       for(auto i:z)
        m[i]++;
       
      
       
       
       int temp=0;
       for(int i=n ; i>=1 ; i--)
       {
            if(m[i])
                temp+=m[i];

            cnt[i]=temp+1;
       }

      

       PowerGenerate1(n);
       PowerGenerate2(n);
       GenerateHash1(s);
       GenerateHash2(s);
       
       int low=1, high=n;

       vector<pair<int, int> > ans;


       while(low<=n)
       {
           if(GetHash1(1, low) == GetHash1(high, n) && GetHash2(1, low) == GetHash2(high, n))
           {
               ans.push_back({low, cnt[low]});
           }

           low++;
           high--;
       }

       cout<<ans.size()<<endl;
       for(auto i:ans)
        cout<<i.f<<" "<<i.s<<endl;

      
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