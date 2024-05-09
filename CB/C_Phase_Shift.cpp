/*
* @Author: Zakaria 
* @Date:   2022-10-02 21:33:44
* @Last Modified time: 2022-10-02 22:00:41
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

int parent[N],Rank[N];
void init(int n)
{
          for(int i=1 ;i<=30 ;i++)
            Rank[i]=1,parent[i]=i;
}

int find_parent(int v) {
    if (v == parent[v]) {
        return v;
        }
    return parent[v] = find_parent(parent[v]);
}
 
void union_sets(int a, int b) {
    a = find_parent(a);
    b = find_parent(b);
    
    parent[a] = b;
        
}


void Solve()
{
        
       int n;
       cin>>n;

       init(n);

       string s;
       cin>>s;


       map<char, char>m;

       for(char c='a' ; c<='z' ; c++)
       	m[c]='*';
       
       
       for(auto i:s)
       {
       	  if(m[i]=='*')
       	  {
       	  	   set<int>st;
       	  	   for(int k=1 ; k<=26 ; k++)
       	  	   	st.insert(find_parent(k));
       	  	   bool ok=0;

       	  	   for(auto k:st)
       	  	   {
                   if(find_parent(k)!=find_parent(i-'a'+1))
                   {
                   	   m[i]=k+'a'-1;
                   	  // cout<<m[i]<<endl;
                   	   union_sets(k, i-'a'+1);
                   	   ok=1;
                   	   break;
                   }
       	  	   }

       	  	   if(!ok)
       	  	   	m[i]=*st.begin() + 'a' - 1;

       	  	  
       	  }
       }

       for(auto i:s)
       	cout<<m[i];

       cout<<endl;

      
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;
        
        cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 