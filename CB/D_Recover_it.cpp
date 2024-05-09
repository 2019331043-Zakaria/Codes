/*
* @Author: Zakaria 
* @Date:   2022-09-07 22:44:26
* @Last Modified time: 2022-09-07 23:44:03
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

const int N = 5e5+6;
int a[N];
#define sz 10000010
bool siv[sz];
bool is_prime[sz];

vector<long long >primes;

void seive()
{
    long long  limit = sqrt(sz+1);

    for (long long  i=3; i<=limit; i+=2)
        if(!siv[i])
            for (long  j = i*i; j<sz; j+=i+i)
                siv[j] = 1;
    primes.push_back(2);
    is_prime[2]=1;
    for (long long i=3; i<sz; i+=2)
        if(!siv[i]) primes.push_back(i), is_prime[i]=1;
}

void Solve()
{
        
      seive();


      
      int n;
      cin>>n;
      
      vector<int>elementprime, composit;

      for(int i=1 ; i<=2*n ; i++)
      {
      	 cin>>a[i];
      	 if(is_prime[a[i]])
      	 	elementprime.push_back(a[i]);
      	 else
      	 	composit.push_back(a[i]);
      }
      sort(composit.rbegin(), composit.rend());

      map<int, int>freqcomposit, freqprime;

      for(auto i:composit)
      	freqcomposit[i]++;

      for(auto i:elementprime)
      	freqprime[i]++;

      vector<int>ans;


      for(auto i:composit)
      {
      	  ll val=i;
          if(freqcomposit[val]==0)
          	continue;
          
          ans.push_back(val);
          freqcomposit[val]--;

      	  for(int k=2 ; k*k<=val ; k++)
      	  {
      	  	  if(val%k==0)
      	  	  {

	                 val=val/k;
	                // ans.push_back(val);
	                 if(is_prime[val])
	                 	freqprime[val]--;
	                 else
	                 	freqcomposit[val]--;

	                 break;
      	  	  }
      	  }
      }
      
      sort(elementprime.begin(), elementprime.end());

      for(auto i:elementprime)
      {   
      	  
      	  while(freqprime[i]>0)
      	  {
      	  	 
      	  	   ans.push_back(i);
      	  	//   ans.push_back(primes[i-1]);
      	  	   freqprime[i]--;
      	  	   freqprime[primes[i-1]]--;

      	  }
      }

      for(auto i:ans)
      	cout<<i<<" ";
      cout<<endl;
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