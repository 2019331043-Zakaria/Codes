/*
* @Author: Zakaria 
* @Date:   2022-09-17 15:24:05
* @Last Modified time: 2022-09-18 10:33:58
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

const int MAX=5e3+5;


struct hashing
{

		ll Hash1[MAX], Pow1[MAX];
		ll Base1=1231;
		ll Mod1=1e9+7;

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
		           Hash1[i] = (Hash1[i-1]*Base1 + (text[i-1]-'a'+1) ) % Mod1;
		           Hash1[i]+=Mod1;
		           Hash1[i]%=Mod1;
		       }

		}

		ll GetHash1(int Left , int Right)
		{
		      ll HashValue = Hash1[Right] - (Hash1[Left-1]*Pow1[Right-Left+1])%Mod1 ; //Here pow is base^(right-lest+1)%mod
		      HashValue+=Mod1;
		      HashValue%=Mod1;

		      return HashValue;

		}

		ll PatternHash1(string pattern)
		{
		     ll x=0;
		     for(int i=1 ; i<=pattern.size() ; i++)
		      x = (x*Base1 + (pattern[i-1]-'a'+1))%Mod1 , x+=Mod1, x%=Mod1;
		     return x;
		}


		ll Hash2[MAX], Pow2[MAX];
	    ll Base2=1567;
	    ll Mod2=1e9+9;

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
		           Hash2[i] = (Hash2[i-1]*Base2 + (text[i-1]-'a'+1) ) % Mod2;
		           Hash2[i]+=Mod2;
		           Hash2[i]%=Mod2;
		       }

		}

		ll GetHash2(int Left , int Right)
		{
		      ll HashValue = Hash2[Right] - (Hash2[Left-1]*Pow2[Right-Left+1])%Mod2 ; //Here pow is base^mod
		      HashValue+=Mod2;
		      HashValue%=Mod2;

		      return HashValue;

		}

		ll PatternHash2(string pattern)
		{
		     ll x=0;
		     for(int i=1 ; i<=pattern.size() ; i++)
		      x = (x*Base2 + (pattern[i-1]-'a'+1))%Mod2 , x+=Mod2, x%=Mod2;
		     return x;
		}
};


int is_Pal[MAX][MAX], dp[MAX][MAX];
int n;
string s;

int foo(int l, int r)
{
	  if(l<1 || r>n)
	  	return 0;
	  if(l>r)
	  	return 0;

	  if(l==r)
	  	return dp[l][r] = 1;

	  if(dp[l][r]!=-1)
	  	return dp[l][r];
    
	  int sum = foo(l+1, r) + foo(l, r-1) - foo(l+1, r-1) + is_Pal[l][r];
	  return dp[l][r] = sum;
}

void Solve()
{
        
        
        cin>>s;
        
        n=s.size();

        hashing ForwardHash, ReverseHash;
        ForwardHash.PowerGenerate1(n);
        ForwardHash.PowerGenerate2(n);
        ForwardHash.GenerateHash1(s);
        ForwardHash.GenerateHash2(s);

        reverse(s.begin(), s.end());



        ReverseHash.PowerGenerate1(n);
        ReverseHash.PowerGenerate2(n);
        ReverseHash.GenerateHash1(s);
        ReverseHash.GenerateHash2(s);
        


        vector<int>temp;

        for(int i=1 ; i<=n ; i++)
        {
        	  for(int j=1 ; j<=i ; j++)
        	  {
        	  	   
                   if(ForwardHash.GetHash1(j, i)==ReverseHash.GetHash1(n-i+1, n-i+1+i-j) &&
                   	ForwardHash.GetHash2(j, i)==ReverseHash.GetHash2(n-i+1, n-i+1+i-j))
        	  	   {
        	  	   	   
        	  	   	    is_Pal[j][i]=1;
        	  	   }
        	  }
        }
        

        memset(dp, -1, sizeof(dp));

        foo(1, n);

        int q;
        cin>>q;
        while(q--)
        {
        	int l, r;
        	cin>>l>>r;
        	cout<<dp[l][r]<<endl;
        }
        



      
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;
        
     //   cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 