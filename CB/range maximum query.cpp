/*
* @Author: Zakaria 
* @Date:   2022-08-24 13:41:37
* @Last Modified time: 2022-08-24 14:38:53
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

const int N=1e5+5;

int n, q;
int a[N], tree[N];

int getMAX(int idx){
    int sum = 0;
    while (idx > 0){
        sum = max(tree[idx], sum);
        idx -= (idx & -idx);
    }
    return sum;
}

void update(int idx, int val, int n){

    while (idx <= n){
        tree[idx] = max(val, tree[idx]);
        idx += (idx & -idx);
    }
}
void Solve()
{
        
       cin>>n>>q;

       while(q--)
       {
       	    int type;
       	    cin>>type;

       	    if(type==1)
       	    {
       	    	   int l, r, w;
       	    	   cin>>l>>r>>w;

       	    	   a[l]=max(a[l], r);

       	    	   update(l, a[l], n);

       	    }
       	    else
       	    {
       	    	   
                   vector<int>v;

                   int k;
                   cin>>k;

                   for(int i=0 ; i<k ; i++)
                   {
                   	   int x;
                   	   cin>>x;
                   	   v.push_back(x);
                   }
                   
                   reverse(v.begin(), v.end());
                   int ans=0;
       	    	   int temp=0;
                   
                   while(v.size())
                   {
                   	    temp=getMAX(v.back());
                   	    if(temp<v.back())
                   	    {
                   	    	 ans=-1;
                   	    	 break;
                   	    }
                   	    ans++;
                   	    while(v.size() && temp>=v.back())
                   	    	v.pop_back();
                   }

                   cout<<ans<<endl;
                   
                   

       	    }
       }
      
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;
        
        //cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 

https://codeforces.com/gym/103061/my