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

void Solve()
{
        

        vector<int>v1, v2, v3, v4;
        for(int i=4 ; i<=50; i++)
        	v1.push_back(i);

        for(int i = 10 ; i<=50 ; i++)
        	v2.push_back(i);

        for(int i = 10 ; i<=50 ; i++)
        	v3.push_back(i);

        for(int i = 10 ; i<=50 ; i++)
        	v4.push_back(i);



        for(auto i:v1)
        {
        	for(auto j:v2)
        	{
        		for(auto k:v3)
        		{
        			for(auto l : v4)
        			{
        				bool ok = 0;
	        			set<int>st;
						st.insert(i);
						st.insert(j);
						st.insert(k);
						st.insert(l);

	        			for(int p = 1 ; p<=500 ; p++)
	        			{
	        			    	

	        				if(GCD(i+p, j+p)==1 && GCD(i+p, k+p)==1 && GCD(i+p, l+p)==1 && GCD(j+p, k+p)==1 && GCD(j+p, l+p)==1 && GCD(k+p, l+p)==1)
	        				{
	        					ok = 1;
	        					cout<<i<<" "<<j<<" "<<k<<" "<<l<<endl;
	        					int G = GCD(i, j);
	        					G = GCD(G, k);
	        					G = GCD(G, l);
	        					//cout<<G<<endl;
	        					break;
	        				}
	        			}

	        			if(!ok)
	        			{
	        				if(st.size()==4)
	        				{
	        					int G = GCD(i, j);
	        					G = GCD(G, k);
	        					G = GCD(G, l);
	        				//	cout<<G<<endl;
	        				//	cout<<i<<" "<<j<<" "<<k<<" "<<l<<endl;
	        				}
	        			}
        		   }

        			
        		}
        	}
        }
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