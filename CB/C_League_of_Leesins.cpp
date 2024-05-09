/*
* @Author: Zakaria 
* @Date:   2022-10-21 09:24:59
* @Last Modified time: 2022-10-21 10:30:26
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

vector< int >node[N];
int head, trail;
int cnt[N];
vector<int>ans;
int n;
int vis[N];

void dfs(int p, int par, int midvalue)
{
	    if(p==midvalue)
	    	return ;
        
        vis[p]=1;
        cout<<p<<" ";

        for(auto i:node[p])
        {
        	if(vis[i]==0)
        	{
        		if(abs(cnt[i] - cnt[p])==1)
        			dfs(i, p, midvalue);
        	}
        }
}

vector<int>ansleft;

void dfsleft(int p)
{
        vis[p]=1;
     
        if(ansleft.size()==n/2 - 1)
        	return ;

        ansleft.push_back(p);
        bool ok=1; //p<child

        for(auto i:node[p])
        {
        	if(vis[i]==0)
        	{
        		if(cnt[i] - cnt[p]==1)
        			dfsleft(i);
        	}
        }

}
vector<int>ansright;

void dfsright(int p)
{
        vis[p]=1;
     
        if(ansright.size()==n/2 - 1)
        	return ;

        ansright.push_back(p);
        bool ok=1; //p<child

        for(auto i:node[p])
        {
        	if(vis[i]==0)
        	{
        		if(cnt[i] - cnt[p]==1)
        			dfsright(i);
        	}
        }

}
void Solve()
{
        
       
       cin>>n;
       
      
       for(int i=3 ; i<=n ; i++)
       {
       	   int x, y, z;
       	   cin>>x>>y>>z;

       	   node[x].push_back(y);
       	   node[x].push_back(z);

       	   node[y].push_back(z);
       	   node[y].push_back(x);
       	   
       	   node[z].push_back(y);
       	   node[z].push_back(x);
       	  // node[x].push_back(y);

       	   cnt[x]++;
       	   cnt[y]++;
       	   cnt[z]++;
       }


       for(int i=1 ; i<=n ; i++)
       {
       	   if(cnt[i]==1)
       	   {
       	   	   if(head==0)
       	   	   	head=i;
       	   	   else
       	   	   	trail=i;
       	   }
       }

       
       vector<int>mid;
       for(int i=1 ; i<=n ; i++)
       {
       	  cout<<i<<" "<<cnt[i]<<endl;
       	  if(cnt[i]==(n+1)/2)
       	  	mid.push_back(i);
       }

       if(n%2)
       {
           
       	  /* cout<<mid[0]<<endl;
       	   dfs(head, -1, mid[0]);
*/


       	  
       }
       else
       {
       	   
           
       	   dfsleft(head);

       	   //reverse(ansleft.begin(), ansleft.end());
       	   for(auto i:ansleft)
       	   	cout<<i<<" ";
       	
       	   dfsright(trail);
           
           reverse(ansright.begin(), ansright.end());
       	   
       	  
           int ok=0;
       	   for(auto i:node[ansright[1]])
       	   {
       	   	   if(i==mid[0])
       	   	   {
                  
                   ok=1;
                   break;
       	   	   }
       	   	   else if(i==mid[1])
       	   	   {
       	   	   	   ok=2;
       	   	   	  
       	   	   	   break;
       	   	   }
       	   }

       	   if(ok==1)
       	   	cout<<mid[1]<<" "<<mid[0]<<" ";
       	   else
       	   	cout<<mid[0]<<" "<<mid[1]<<" ";
           


       	   for(auto i:ansright)
       	   	cout<<i<<" ";
           


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