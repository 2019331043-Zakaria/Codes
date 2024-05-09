/*
* @Author: Zakaria 
* @Date:   2023-01-05 20:49:06
* @Last Modified time: 2023-01-05 21:11:06
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


void Solve()
{
        
       int n;
       cin>>n;

       int a[n+1];

       for(int i=1 ; i<=n ; i++)
       	cin>>a[i];

       map<int, vector<int> > pos;

       for(int i=1 ; i<=n ; i++)
       {
       	  pos[a[i]].push_back(i);
       }

       set <int> stA, stB;

       for(int i=1 ; i<=n ; i++)
       	stA.insert(i), stB.insert(i);


       map<int, int>ansA, ansB;


       for(int i=1 ; i<=n ; i++)
       {
       	   for(auto k : pos[i])
       	   {
       	   	    bool ok = 0;

       	   		if(stA.find(i)!=stA.end())
       	   		{
                     int temp = *stB.begin();

                     if(temp<=i)
                     {
                     	ansA[k] = i;
                     	ansB[k] = temp;
                     	ok = 1;
                     	stA.erase(i);
                     	stB.erase(temp);
                     }
       	   		}

       	   		if(ok)
       	   			continue;

       	   		if(stB.find(i)!=stB.end())
       	   		{
       	   			int temp = *stA.begin();

       	   			if(temp<=i)
       	   			{
       	   				ansA[k] = temp;
       	   				ansB[k] = i;
       	   				ok = 1;
       	   				stA.erase(temp);
       	   				stB.erase(i);

       	   			}
       	   		}

       	   		if(!ok)
       	   		{
       	   			cout<<"NO"<<endl;
       	   			return ;
       	   		}
       	   }
       }

       cout<<"YES"<<endl;

       for(int i=1 ; i<=n ; i++)
       	cout<<ansA[i]<<" ";
       cout<<endl;
       for(int i=1 ; i<=n ; i++)
       	cout<<ansB[i]<<" ";

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