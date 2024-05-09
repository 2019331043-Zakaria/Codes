/*
* @Author: Zakaria 
* @Date:   2022-09-08 21:04:55
* @Last Modified time: 2022-09-08 22:06:34
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
#define  MAX         200002
#define  eps         1e-6
typedef long long ll;
using namespace std;

const int N = 2e5+6;

ll a[N], b[N];

int digitcount(ll x)
{
	  int cnt=0;
	  while(x)
	  {
	  	 cnt++;
	  	 x/=10;
	  }
	  return cnt;
}

void Solve()
{
        

        int n;
        cin>>n;
        
        map<ll, vector<int> >stA, stB;

        vector<pair<ll, ll> > va, vb;
        for(int i=0 ; i<n ; i++)
        {
        	 cin>>a[i];
        	 stA[a[i]].push_back(i);
        	 va.push_back({a[i], i});
        }

        for(int i=0 ; i<n ; i++)
        {
        	 cin>>b[i];
        	 stB[b[i]].push_back(i);
        	 vb.push_back({b[i], i});
        }

        int ans=0;
        
        sort(va.rbegin(), va.rend());
        sort(vb.rbegin(), vb.rend());


        for(auto i:va)
        {
        	 ll indx=i.s;
        	 ll val=i.f;
        	 stA[val].pop_back();

        	 if(stB[val].size())
        	 {
        	 	   a[indx]=0;
        	 	   b[stB[val].back()]=0;
        	 	   stB[val].pop_back();
        	 }
        }
        
        for(int i=0 ; i<n ; i++)
        {
        	 if(a[i]>10)
        	 {
        	 	 int digit=digitcount(a[i]);

        	 	 a[i]=digit;
        	 	 ans++;

        	 }
        	 if(b[i]>10)
        	 {
        	 	    int digit=digitcount(b[i]);
        	 	 	b[i]=digit;
        	 	 	ans++;

        	 }
        }

       
        
        stB.clear();
        stA.clear();
        va.clear();
        vb.clear();
        
        for(int i=0 ; i<n ; i++)
        {
        	 if(a[i])
        	 {
        	 	 stA[a[i]].push_back(i);
        	 	 va.push_back({a[i], i});
        	 }

        	 if(b[i])
        	 {
        	 	 stB[b[i]].push_back(i);
        	 	 vb.push_back({b[i], i});
        	 }
        }

        sort(va.rbegin(), va.rend());
        sort(vb.rbegin(), vb.rend());


        for(auto i:va)
        {
        	 ll indx=i.s;
        	 ll val=i.f;
        	 stA[val].pop_back();
        	 if(val==0)
        	 	continue;

        	 if(stB[val].size())
        	 {
        	 	   a[indx]=0;
        	 	   b[stB[val].back()]=0;
        	 	   stB[val].pop_back();
        	 }
        }


        for(int i=0 ; i<n ; i++)
        {
        	 if(a[i]==10)
        	 {
        	 	 int digit=digitcount(a[i]);

        	 	 a[i]=digit;
        	 	 ans++;

        	 }
        	 if(b[i]==10)
        	 {
        	 	    int digit=digitcount(b[i]);
        	 	 	b[i]=digit;
        	 	 	ans++;

        	 }
        }


        stB.clear();
        stA.clear();
        va.clear();
        vb.clear();
        
        for(int i=0 ; i<n ; i++)
        {
        	 if(a[i])
        	 {
        	 	 stA[a[i]].push_back(i);
        	 	 va.push_back({a[i], i});
        	 }

        	 if(b[i])
        	 {
        	 	 stB[b[i]].push_back(i);
        	 	 vb.push_back({b[i], i});
        	 }
        }

        sort(va.rbegin(), va.rend());
        sort(vb.rbegin(), vb.rend());


        for(auto i:va)
        {
        	 ll indx=i.s;
        	 ll val=i.f;
        	 stA[val].pop_back();
        	 if(val==0)
        	 	continue;

        	 if(stB[val].size())
        	 {
        	 	   a[indx]=0;
        	 	   b[stB[val].back()]=0;
        	 	   stB[val].pop_back();
        	 }
        }



         for(int i=0 ; i<n ; i++)
        {
        	 if(a[i]>1)
        	 {
        	 	 int digit=digitcount(a[i]);

        	 	 a[i]=digit;
        	 	 ans++;

        	 }
        	 if(b[i]>1)
        	 {
        	 	    int digit=digitcount(b[i]);
        	 	 	b[i]=digit;
        	 	 	ans++;

        	 }
        }


        stB.clear();
        stA.clear();
        va.clear();
        vb.clear();
        
        for(int i=0 ; i<n ; i++)
        {
        	 if(a[i])
        	 {
        	 	 stA[a[i]].push_back(i);
        	 	 va.push_back({a[i], i});
        	 }

        	 if(b[i])
        	 {
        	 	 stB[b[i]].push_back(i);
        	 	 vb.push_back({b[i], i});
        	 }
        }

        sort(va.rbegin(), va.rend());
        sort(vb.rbegin(), vb.rend());


        for(auto i:va)
        {
        	 ll indx=i.s;
        	 ll val=i.f;
        	 stA[val].pop_back();
        	 if(val==0)
        	 	continue;

        	 if(stB[val].size())
        	 {
        	 	   a[indx]=0;
        	 	   b[stB[val].back()]=0;
        	 	   stB[val].pop_back();
        	 }
        }

         for(int i=0 ; i<n ; i++)
        {
        	 if(a[i]>1)
        	 {
        	 	 int digit=digitcount(a[i]);

        	 	 a[i]=digit;
        	 	 ans++;

        	 }
        	 if(b[i]>1)
        	 {
        	 	    int digit=digitcount(b[i]);
        	 	 	b[i]=digit;
        	 	 	ans++;

        	 }
        }


         stB.clear();
        stA.clear();
        va.clear();
        vb.clear();
        
        for(int i=0 ; i<n ; i++)
        {
        	 if(a[i])
        	 {
        	 	 stA[a[i]].push_back(i);
        	 	 va.push_back({a[i], i});
        	 }

        	 if(b[i])
        	 {
        	 	 stB[b[i]].push_back(i);
        	 	 vb.push_back({b[i], i});
        	 }
        }

        sort(va.rbegin(), va.rend());
        sort(vb.rbegin(), vb.rend());


        for(auto i:va)
        {
        	 ll indx=i.s;
        	 ll val=i.f;
        	 stA[val].pop_back();
        	 if(val==0)
        	 	continue;

        	 if(stB[val].size())
        	 {
        	 	   a[indx]=0;
        	 	   b[stB[val].back()]=0;
        	 	   stB[val].pop_back();
        	 }
        }
        
        cout<<ans<<endl;


        

      
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