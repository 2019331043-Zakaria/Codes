/*
* @Author: Zakaria 
* @Date:   2023-01-11 15:06:44
* @Last Modified time: 2023-01-11 15:59:09
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
const int N = 3e5+6;

#define sz 10000010
bool siv[sz];
int lps[sz];

void seive()
{
    long long  limit = sqrt(sz+1);
    
    for(int i=1 ; i<sz ; i++)
        lps[i] = i;

    for(int i=2 ; i<sz ; i+=2)
        lps[i] = 2;

    for (int  i=3; i<=limit; i+=2)
        if(!siv[i])
            for (int  j = i*i; j<sz; j+=i+i)
                siv[j] = 1, lps[j] = min(lps[j], i);
}

vector<int>GetFact(int p)
{
	vector<int>st;
	while(p>1)
	{
		st.push_back(lps[p]);
		p/=lps[p];
	}

	return st;
}

vector<int>node[N];
int cost[N];
int parent[N];
int vis[N];
int UsedFactor[N];

void Pathprint(int index)
{
	if(index==-1)
		return ;
	Pathprint(parent[index]);

	cout<<index<<" ";
}

void Solve()
{

        seive();
         

        int n;
        cin>>n;

        int a[n+1];

        for(int i=1 ; i<=n ; i++)
        	cin>>a[i];
        
        int startindex, stopindex;

        cin>>startindex>>stopindex;

        for(int i=1 ; i<=n ; i++)
        {
        	int temp = a[i];

        	while(temp>1)
        	{
        		node[lps[temp]].push_back(i);
        		temp/=lps[temp];
        	}
        }

        for(int i=1 ; i<=n ; i++)
        	cost[i] = 1e9, parent[i] = -1;


        queue< int >q;  // index

        int temp = a[startindex];

        q.push(startindex);
        
        cost[startindex] = 0;
        vis[startindex] = 1;

        while(q.size())
        {
        	
        	 int Index = q.front();
        	 int Value = a[Index];
        	 int Result = cost[Index];

        	 vector<int>Factor;

        	 Factor = GetFact(Value);

			for(auto i:Factor)
			{
				if(UsedFactor[i])
					continue;

				for(auto k:node[i])
				{
					if(vis[k]==0)
					{	
						cost[k] = Result + 1;
						vis[k] = 1;
						parent[k] = Index;
						q.push(k);
					}
				}
				
				UsedFactor[i] = 1;
			}

        	q.pop();
        }

        if(cost[stopindex]>=1e9)
        {
        	cout<<-1<<endl;
        	return ;
        }

        cout<<cost[stopindex]+1<<endl;
        
        Pathprint(stopindex);



       
      
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;
        
    //    cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 