/*
* @Author: Zakaria 
* @Date:   2022-10-29 15:10:21
* @Last Modified time: 2022-10-29 15:13:07
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

#define sz 1000001
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
        
        int n;
        cin>>n;

        if(n==2)
        	cout<<2<<endl;
        else
        	cout<<3<<endl;
      
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
       // seive();

        int tt=1;
        
        cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 