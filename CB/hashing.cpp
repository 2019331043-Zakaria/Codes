/*
* @Author: Zakaria 
* @Date:   2022-06-16 14:57:32
* @Last Modified time: 2022-12-04 22:31:29
*/

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



const int N = 5e5 + 9;
 
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
 
// credit: solaimanope
const pll M = make_pair(2147483647, 1088888881);
const ll base = 1135019;   
 
pll operator+ (pll a, ll x)     {return make_pair(a.first + x, a.second + x);}
pll operator- (pll a, ll x)     {return make_pair(a.first - x, a.second - x);}
pll operator* (pll a, ll x)     {return make_pair(a.first * x, a.second * x);}
pll operator+ (pll a, pll x)    {return make_pair(a.first + x.first, a.second + x.second);}
pll operator- (pll a, pll x)    {return make_pair(a.first - x.first, a.second - x.second);}
pll operator* (pll a, pll x)    {return make_pair(a.first * x.first, a.second * x.second);}
pll operator% (pll a, pll m)    {return make_pair(a.first % m.first, a.second % m.second);}
 
pll power (pll a, ll p) {
  if (p==0)   return make_pair(1,1);
  pll ans = power(a, p/2);
  ans = (ans * ans)%M;
  if (p%2)    ans = (ans*a)%M;
  return ans;
}
 
///Magic!!!!!!!
pll inverse(pll a)  {
  return power(a, (M.first-1)*(M.second-1)-1);
}
 
pll pb[N]; // powers of base mod M
pll invb;
pll inv[N];
void prec() {
  pb[0] = make_pair(1,1);
  for (int i=1; i<N; i++)
      pb[i] = (pb[i-1] * base)%M;
  invb = inverse(pb[1]);
  for (int i = 1; i < N; i++) {
    inv[i] = inverse(pb[i] - 1);
  }
}
 
// Calculates Hash of a string
pll Hash (string s) {
  pll ans = make_pair(0,0);
  for (int i=0; i<s.size(); i++)
      ans=(ans*base + s[i])%M;
  return ans;
}
 
// concatenates two strings where length of the right is k
pll concat(pll left, pll right, int k) {
  return (left*pb[k] + right)%M;
}
 
//Calculates hash of string with size len repeated cnt times
//This is O(log n). For O(1), pre-calculate inverses
pll repeat(pll hash, int len, ll cnt) {
  pll mul = (pb[len*cnt] - 1) * inv[len];
  mul = (mul%M+M)%M;
  pll ans = (hash*mul)%M;
 
  if (pb[len].first == 1)    ans.first = hash.first*cnt;
  if (pb[len].second == 1)    ans.second = hash.second*cnt;
  return ans;
}
 
//Calculates hashes of all prefixes of s including empty prefix
vector<pll> hashList(string s) {
  int n = s.size();
  vector<pll> ans(n+1);
  ans[0] = make_pair(0,0);
 
  for (int i=1; i<=n; i++)
      ans[i] = (ans[i-1] * base + s[i-1])%M;
  return ans;
}
 
//Calculates hash of substring s[l..r] (1 indexed)
pll get_hash(const vector<pll> &hashlist, int l, int r) {
  int len = (r-l+1);
  return ((hashlist[r] - hashlist[l-1]*pb[len])%M+M)%M;
}
string s;
vector<pll> a;
int n;
 
pll yo(int i, int len) {
  pll ans = {0, 0};
  if (len >= i) ans = repeat(get_hash(a, 1, i), i, len / i);
  len %= i;
  if (len) {
    ans = concat(ans, get_hash(a, 1, len), len);
  }
  return ans;
}
char get(int i, int len) {
  --len;
  len %= i;
  return s[len];
}