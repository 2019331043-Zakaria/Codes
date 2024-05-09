/*
* @Author: Zakaria 
* @Date:   2022-04-01 01:08:32
* @Last Modified time: 2022-12-27 14:27:39
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
#define  MAX         1000002
typedef long long ll;
using namespace std;

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

bool Check(int len)
{

       
      
       ll pans1=GetHash1(1,len);
       ll pans2=GetHash2(1,len);
       
       ll lans1=GetHash1(n-len+1, n);
       ll lans2=GetHash2(n-len+1, n);

       if(!(pans1==lans1 && pans2==lans2))
         return 0;
       
       
       ll b=2, e=2+len-1;

       while(e<n)
       {
           
             if(GetHash1(b,e)==pans1 && pans2==GetHash2(b,e))
                return 1;
             b++,e++;
       }

       return 0;

}

void Solve()
{
         
         
          cin>>s;
          n=s.size();
         
          PowerGenerate1(n);
          PowerGenerate2(n);
          GenerateHash1(s);
          GenerateHash2(s);
          
          vector<int>v;
          v.push_back(n);

          int b=n,e=n,start=1;

          while(start<=n)
          {
               if(GetHash1(1,start)==GetHash1(b,e) && GetHash2(1,start)==GetHash2(b,e))
                  v.push_back(start);
               b--;
               start++;
          }

          
          int low=1, high=v.size(), mid;

          int ans=0;
          while(low<=high)
          {
               
                mid=(low+high)/2;
               
                if(mid==1 || Check(v[mid-1]))
                  low=mid+1,ans=max(ans,mid-1);
                else
                  high=mid-1;
          }

       

          if(!ans)
            cout<<"Just a legend"<<endl;
          else
          {
              for(int i=0 ; i<v[ans] ; i++)
               cout<<s[i];
              cout<<endl;
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


