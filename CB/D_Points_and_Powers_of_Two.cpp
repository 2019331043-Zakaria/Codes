/*
* @Author: Zakaria 
* @Date:   2022-12-28 23:47:52
* @Last Modified time: 2022-12-29 00:01:00
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

int a[N];

void Solve()
{
        
      int n;
      cin>>n;
      
      map<int, int>m;

      for(int i=0 ; i<n ; i++)
      	cin>>a[i], m[a[i]]++;

      sort(a, a+n);

      int ans = 0;

      int value = 0;

      int TwoPow = 0;

      for(auto i:a)
      {
      	 ll temp = i;

      	 for(ll k = 0 ; k<31 ; k++)
      	 {
      	 	
      	 	int Pans = 1LL<<k;
      	 	int Result = m[temp] + m[temp+Pans] + m[temp+Pans+Pans];



      	 	if(Result>ans)
      	 	{
      	 		ans = Result;
      	 		TwoPow = Pans;
      	 		value = temp;
      	 	}

      	 }
      }

      cout<<ans<<endl;

      for(int i = 0 ; i<m[value] ; i++)
      	cout<<value<<" ";
      for(int i = 0 ; i<m[value+TwoPow] ; i++)
      	cout<<value+TwoPow<<" ";
      for(int i = 0 ; i<m[value+TwoPow+TwoPow] ; i++)
      	cout<<value+TwoPow+TwoPow<<" ";

      cout<<endl;
      
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