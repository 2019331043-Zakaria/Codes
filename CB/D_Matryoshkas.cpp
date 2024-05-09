/*
* @Author: Zakaria 
* @Date:   2023-01-27 21:17:27
* @Last Modified time: 2023-01-27 21:38:04
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

map<int, int>m;

bool Check(int k)
{
/*	for(auto i:m)
		cout<<i.f<<" "<<i.s<<endl;
	cout<<"after "<<endl;*/
    
	for(int i=1 ; i<=k ; i++)
	{
		if(m.size()==0)
		  break;

		auto it = *m.begin();
		int temp = it.f;

		for(int p = temp ;  ; p++)
		{
			if(m[p]==0)
			{   
				m.erase(p);
				break;
			}
			m[p]--;
			if(m[p]==0)
				m.erase(p);
		}
	}

	/*for(auto i:m)
		cout<<i.f<<" "<<i.s<<endl;*/

	for(auto i:m)
	{
		if(i.s>0)
			return  0;
	}

	return 1;

}

void Solve()
{
        
      int n;
      cin>>n;

      int a[n];

      m.clear();
     
      for(int i=0 ; i<n ; i++)
      {
      	 cin>>a[i];
      	 m[a[i]]++;
      }

      map<int, int>pans;
      pans = m;

      int low = 1, high = n, mid;
      int ans = n;
      while(low<=high)
      {
      	m = pans;
      	mid = (low+high)/2;
      	if(Check(mid))
      		ans = mid , high = mid - 1;
      	else
      		low = mid + 1;
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