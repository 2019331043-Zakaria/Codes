/*
* @Author: Zakaria 
* @Date:   2023-01-19 12:05:22
* @Last Modified time: 2023-01-19 12:59:30
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

int Fenwick[N];

void Update(int idx)
{
    while(idx<=N){
        Fenwick[idx]++;
        idx+=(idx&(-idx));
    }
}
int Query(int idx)  // number of int <=idx
{
    int r=0;
    while(idx){
        r+=Fenwick[idx];
        idx-=(idx&(-idx));
    }
    return r;
}



void Solve()
{
        
      int n;
      cin>>n;

      string s;
      cin>>s;
      map<char, vector<int> > Charpos;

      for(int i = n-1 ; i>=0 ; i--)
      	Charpos[s[i]].push_back(i);

      vector<int>Permuatation;

      string rev = s;
      reverse(rev.begin(), rev.end());

      for(auto i:rev)
      {
      	Permuatation.push_back(Charpos[i].back());
      	Charpos[i].pop_back();
      }

      ll ans = 0;

      reverse(Permuatation.begin(), Permuatation.end());

      for(auto i:Permuatation)
      {
      	ans+=Query(i+1);
      	Update(i+1);
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