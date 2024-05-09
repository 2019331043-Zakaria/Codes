/*
* @Author: Zakaria 
* @Date:   2022-11-16 21:30:31
* @Last Modified time: 2022-11-17 13:53:04
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
        
        int n, k;
        cin>>n>>k;

        int temp = n/k;

        vector<int>v;

        for(int i=1 ; i<=k ; i++)
        	v.push_back(i);

     
        vector<int>ans;

        int baki = n%k;

        for(int i=1 ; i<=temp ; i++)
        {
        	for(auto k:v)
        		ans.push_back(k);
           
        }
        
        int value = k+1;

        while(baki)
        {
        	  vector<int>pans;
              int add = 0;

              for(int i=0 ; i<ans.size() ; i++)
              {
                 if(baki && (i+add)%k==0 && ans.size() - i >=k)
                 {
                 	pans.push_back(value);
                 	pans.push_back(ans[i]);
                 	add++;
                 	baki--;
                 }
                 else
                    pans.push_back(ans[i]);
              }



              ans = pans;
              
             
              value++;
         }
        
        int mx = 0;

        for(auto i:ans)
         mx = max(mx, i);

       cout<<mx<<endl;

       for(auto i:ans)
       	cout<<i<<" ";

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