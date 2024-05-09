/*
* @Author: Zakaria 
* @Date:   2022-09-28 00:16:18
* @Last Modified time: 2022-09-28 00:40:35
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

struct type
{
	 int l, r, index;
};

bool comp1(type a, type b)
{
	  return a.r>b.r;

}

bool comp2(type a, type b)
{
	  return a.r<b.r;
}
void Solve()
{
        
       int n;
       cin>>n;
       
       vector<type>less, greater;

       for(int i=1 ; i<=n ; i++)
       {
       	   type a;
       	   cin>>a.l>>a.r;
       	   a.index=i;

       	   if(a.l>a.r)
       	   	greater.push_back(a);
       	   else
       	   	less.push_back(a);
       }

       sort(less.begin(), less.end(), comp1);
       
       
       vector<int>ans1;
       
       int val=INT_MAX;
       
       for(auto i:less)
       {
           if(i.l<val)
           {
           	   ans1.push_back(i.index);
           	   val=i.r;  
           }
       }

       sort(greater.begin(), greater.end(), comp2);

       val=0;
       vector<int>ans2;

       for(auto i:greater)
       {
       	   if(i.l>val)
       	   {
       	   	  ans2.push_back(i.index);
       	   	  val=i.r;
       	   }
       }

       if(ans1.size()<ans2.size())
       	swap(ans1, ans2);

       cout<<ans1.size()<<endl;

       for(auto i:ans1)
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