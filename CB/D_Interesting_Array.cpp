/*
* @Author: Zakaria 
* @Date:   2022-09-10 12:38:42
* @Last Modified time: 2022-09-10 15:15:50
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

const int N = 1e5+6;

int a[N];
int tree[N*4];

void init(int node, int b, int e) 
{
      
       if(b==e)
       {
          tree[node]=a[b];
          return ;
       }

       int left=2*node;
       int right=left+1;

       int mid=(b+e)/2;

       init(left, b, mid); 
       init(right, mid+1, e); 

       tree[node]=tree[left]&tree[right];
}

int query(int node, int b, int e, int i, int j)
{
      if(i>e || j<b)
        return (1<<30)-1;
      if(b>=i && e<=j)
        return tree[node];

      int left=node*2;
      int right=node*2 +1;

      int mid=(b+e)/2;
      
      int ans=1<<30;
      ans--;

      int p1=query(left,  b,  mid, i, j);
      int p2=query(right , mid+1, e, i, j);
      ans&=p1;
      ans&=p2;
      return ans;

}


struct type
{
     int l, r, x;
};

void Solve()
{
        
        
       int n, q;
       
       cin>>n>>q;
       
       int shift[35];

       for(int bit=0 ; bit<30 ; bit++)
        shift[bit]=1<<bit;
       
       type qwrt[q+1];

       for(int i=1 ; i<=q ; i++)
       {
            cin>>qwrt[i].l>>qwrt[i].r>>qwrt[i].x;
       }

       for(int bit=0 ; bit<30 ; bit++)
       {
              
              int sum[n+1];
              for(int i=0 ; i<=n ; i++) sum[i]=0;

              for(int i=1; i<=q ; i++)
              {
                   int l = qwrt[i].l;
                   int r = qwrt[i].r;
                   int x = qwrt[i].x;
                   if(x&shift[bit])
                   {
                     sum[l]++;
                     sum[r+1]--;
                   }
              }

              for(int i=1 ; i<=n ; i++)
              {
                   sum[i]+=sum[i-1];

                   if(sum[i]>0)
                    a[i]|=(1<<bit);
              }

       }

       init(1, 1, n);

       for(int i=1 ;i<=q ; i++)
       {
          if(query(1, 1, n, qwrt[i].l, qwrt[i].r)!=qwrt[i].x)
          {
              cout<<"NO"<<endl;
              return ;
          }
       }

       cout<<"YES"<<endl;

       for(int i=1 ; i<=n ; i++)
        cout<<a[i]<<" ";
       cout<<endl;
       
       
      
}
 
int main()
{
         
     
        int tt=1;
        
        //cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 