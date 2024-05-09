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

bool ok(vector<int> v)
{
	  for(int i=0 ; i<v.size()-1 ; i++)
	  {
	  	if(v[i]-1<=v[i+1])
	  		continue;
	  	else
	  	{
	  		return false;
	  	}
	  }

	  return 1;
}

void Solve()
{
        
          vector<int>v;

          v.push_back(1);
          v.push_back(2);
          v.push_back(3);
          v.push_back(4);
          v.push_back(5);
          v.push_back(6);
        

          do{
                
               if(ok(v))
               {
               	  for(auto i:v)
               	  	cout<<i<<" ";
               	  cout<<endl;
               }

           
          }while(next_permutation(v.begin(), v.end()));


      
      
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;
        
     //   cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 