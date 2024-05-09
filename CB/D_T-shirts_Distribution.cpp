/*
* @Author: Zakaria 
* @Date:   2022-09-10 23:04:01
* @Last Modified time: 2022-09-11 00:47:30
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

struct type
{
    int index;
    string a, b;

};
map< string, int > sa;

bool comp(type pans , type lans)
{
      if(pans.a==lans.a)
        return sa[pans.b]<sa[lans.b];
      else
        return sa[pans.a]<sa[lans.a];
}

void Solve()
{
        
        int s, m, l, xl, xxl, xxxl;
        cin>>s>>m>>l>>xl>>xxl>>xxxl;
        
        map<string, int>rem;
        map<int, string>ans;

        rem["S"]=s; rem["M"]=m; rem["L"]=l; rem["XL"]=xl; rem["XXL"]=xxl; rem["XXXL"]=xxxl;
        
        vector<type>v;

        int n;
        cin>>n;

        for(int i=0 ; i<n ; i++)
            ans[i]="#";
        
        bool ok=0;

        for(int i=0 ; i<n ; i++)
        {
             string s;
             cin>>s;
             
             int ind=-1;

             for(int k=0 ; k<s.size() ; k++)
             {
                if(s[k]==',')
                    ind=k;
             }

             if(ind==-1)
             {
                 if(rem[s])
                 {
                    ans[i]=s;
                    rem[s]--;
                 }
                 else
                    ok=1;
             }
             else
             {
                  string pans="", lans="";

                  for(int k=0; k<ind ; k++)
                    pans+=s[k];
                  for(int k=ind+1 ; k<s.size() ; k++)
                    lans+=s[k];
                  
                  type x;

                  x.index=i, x.a=pans, x.b=lans;
                  
                  v.push_back(x);
                 
             }
              
        }
        
        if(ok)
        {
            cout<<"NO"<<endl;
            return ;
        }

        map<string, vector<int>>cnt;

        for(auto i:v)
        {
            cnt[i.a].push_back(i.index);
            cnt[i.b].push_back(i.index);
        }

       
        
        sa["S"]=0;
        sa["M"]=1;
        sa["L"]=2;
        sa["XL"]=3;
        sa["XXL"]=4;
        sa["XXXL"]=5;
        
        sort(v.begin(), v.end(), comp);
     
        for(auto i:v)
        {
            string a=i.a;
            string b=i.b;
            
            if(sa[a]>sa[b])
                swap(a, b);

            if(rem[a]>0)
                ans[i.index]=a, rem[a]--;
            else if(rem[b]>0)
                ans[i.index]=b, rem[b]--;
            else
            {
                cout<<"NO"<<endl;
                return ;
            }

        }


        /*cout<<endl;
        for(int i=0 ; i<n ; i++)
            cout<<ans[i]<<endl;*/

        cout<<"YES"<<endl;
        for(int i=0 ; i<n ; i++)
            cout<<ans[i]<<endl;
      
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