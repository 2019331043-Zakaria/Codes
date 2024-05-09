/*
* @Author: Zakaria 
* @Date:   2022-09-11 01:47:25
* @Last Modified time: 2022-09-11 02:59:10
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
const int N = 5e5+6;

int n, k;
int a[N], b[N];



void Solve()
{
        
        
        cin>>n>>k;
       
        for(int i=1 ; i<=n ; i++)
        {
        	cin>>a[i];
        	
        }

        for(int i=1 ; i<=n ; i++)
        {
        	cin>>b[i];
        }

        int value=b[1];

        if(k==0)
        {
        	for(int i=1 ; i<=n ; i++)
        	{
        		if(a[i]!=b[i])
        		{
        			cout<<"NO"<<endl;
        			return ;
        		}
        	}

        	cout<<"YES"<<endl;
        	return ;
        }

        vector<int>v;

        for(int i=1 ; i<=n ; i++)
        {
        	if(a[i]==value)
        	{
        		for(int j=i ; j<=n ; j++)
        			v.push_back(a[j]);

        		for(int j=1 ; j<i ; j++)
        			v.push_back(a[j]), k--;


        	}
        }

        for(int i=1 ; i<=n ; i++)
        {
        	if(b[i]!=v[i-1])
        	{
        		cout<<"NO"<<endl;
        		return;
        	}
        }

        cout<<"YES"<<endl;

        
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;
        
        cin>>tt;
        int t=1;
        while(tt--)
        {
            cout<<"Case #"<<t++<<": ";
            Solve();
        }
 
        return 0;
        
} 