/*
* @Author: Zakaria 
* @Date:   2022-12-27 13:56:01
* @Last Modified time: 2022-12-27 15:21:06
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
const int N = 2e6+6;

const ll Base1=1231;
const ll Mod1=1e9+7;

const ll Base2=1567;
const ll Mod2=1e9+9;

ll Pow1[N];
ll Pow2[N];

vector<ll>AnswerHash1, AnswerHash2;
string ans="";

void PowerGenerate1(ll n)
{
     Pow1[0]=1;
     for(int i=1 ; i<=n ; i++)
     {
       Pow1[i] = (Pow1[i-1]*Base1)%Mod1;
     }

}

void PowerGenerate2(ll n)
{
     Pow2[0]=1;
     for(int i=1 ; i<=n ; i++)
     {
       Pow2[i] = (Pow2[i-1]*Base2)%Mod2;
     }

}

void Concate(string s, int l, int r)
{
     
     for(int i = l ; i<=r ; i++)
     {
     	AnswerHash1.push_back( ( (AnswerHash1.back()*Base1)%Mod1 + (s[i] - '$' + 1) )%Mod1 );
        ans+=s[i];
     }
    
}


vector<ll>GenerateHash1(string s)
{
	vector<ll>v;
	v.push_back(0);
	for(auto i:s)
	{
		v.push_back( ( (v.back()*Base1)%Mod1 + (i - '$' + 1) )%Mod1 );
	}

	return v;
}

ll GetHash1Answer(int Left, int Right)
{
	//  cout<<Left<<" "<<Right<<endl;
	  ll HashValue = (AnswerHash1[Right] - (AnswerHash1[Left-1]*Pow1[Right-Left+1])%Mod1)%Mod1 ; //Here pow is base^mod
      HashValue+=Mod1;
      HashValue%=Mod1;

      return HashValue;
}



int BinSearch(string s)
{
	
	
	vector<ll>TempHash1;
	
	TempHash1 = GenerateHash1(s);

	
    int totlen = ans.size();

    int Canbe = min(ans.size(), s.size()) - 1;
    int ok = -1;

    for(int i = 0 ; i<=Canbe ; i++)
    {
    	 ll value = GetHash1Answer(totlen-i, totlen);
    	 ll oppo = TempHash1[i+1];

    	 if(value==oppo)
    	 {
    	 	ok = i;
    	 }
    }


    return ok;

}

void Solve()
{
      
      int n;
      cin>>n;

      PowerGenerate1(1e5+7);
      PowerGenerate2(1e5+7);

      vector<string>v;

     

      for(int i=1 ; i<=n ; i++)
      {
      	string s;
      	cin>>s;
      	v.push_back(s);
      }

      AnswerHash1.push_back(0);
      AnswerHash2.push_back(0);

      
      for(string s : v)
      {
            if(ans.size()==0)
            {
                 Concate(s, 0, s.size() - 1);
            }
            else
            {
            	 int left = BinSearch(s);
            	 Concate(s, left+1, s.size() - 1);
            }
      }


      cout<<ans<<endl;

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