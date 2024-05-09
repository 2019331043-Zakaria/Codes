/*
* @Author: Zakaria 
* @Date:   2022-09-22 22:30:41
* @Last Modified time: 2022-09-22 23:38:22
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

#define sz 100010
bool siv[sz];
vector<long long >primes;

void seive()
{
    long long  limit = sqrt(sz+1);

    for (long long  i=3; i<=limit; i+=2)
        if(!siv[i])
            for (long  j = i*i; j<sz; j+=i+i)
                siv[j] = 1;
    primes.push_back(2);
    for (long long i=3; i<sz; i+=2)
        if(!siv[i]) primes.push_back(i);
}

void Solve()
{
        
        ll n;
        cin>>n;

        seive();

        ll a[n+1];

       

        ll cum[n+1];
      
        cum[0]=0;

        map<int, vector<int> > v;

        for(int i=1 ; i<=n ; i++)
        {
        	 cin>>a[i];
        	 v[a[i]].push_back(i);
        	 cum[i]=cum[i-1]+a[i];
        }

        map<int, vector<pair<int, int> > > prime;


        int q;
        cin>>q;
        
        int index[q+1], primevalu[q+1];
        for(int i=1 ; i<=q ; i++)
        {
             int k, p;
             cin>>p>>k;

             index[i]=k;
             primevalu[i]=p;

             prime[p].push_back({k, i});
        }

        for(int i=1 ;  i<=100000 ; i++)
        {
        	 if(prime.find(i)!=prime.end())
        	 	sort(prime[i].rbegin(), prime[i].rend());

        	 if(v.find(i)!=v.end())
        	 	reverse(v[i].begin(), v[i].end());
        }
        
        map<int, vector<int> > store;

        for(auto i:primes)
        {
              int temp=i;
              int add=i;

              while(temp<=100000)
              {
              	  for(auto k:v[temp])
              	  	store[i].push_back(temp);
              	  temp+=add;
              }
        }

        for(auto i:primes)
        {
              sort(store[i].begin(), store[i].end());

              ll res=0;

              for(int j=0 ; j<store[i].size() ; j++)
              {
              	  res+=store[i][j];
              	  store[i][j]=res;
              }       	
        }

      

        ll ans[q+1];
        for(int i=1 ; i<=q ; i++)
        	ans[i]=0;


        for(auto i:prime)
        {  
        	  int temp=i.f;

        	  cout<<temp<<endl;
        	
              int add=temp;

              vector<pair<int, int> > vp;
              vp=i.s;
              int cnt=0;

        	  while(temp<=100000)
        	  {
                  
              	  while(v[temp].size())
              	  {
                       
                       if(vp.size())
                       {
                           if(v[temp].back()<=vp.back().f)
                           {
                           	   cnt++;
                           	   ans[vp.back().s]=cnt;
                           	   v[temp].pop_back();
                           }
                           else
                           {
                           	   vp.pop_back();
                           }
                       }
                       else
                       break;
              	  }
                  
                  temp+=add;
        	  }
        }

        for(int i=1 ; i<=q ; i++)
        {
        	cout<<ans[i]<<endl;
        }
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