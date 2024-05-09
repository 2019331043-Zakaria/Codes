/*
* @Author: Zakaria 
* @Date:   2022-09-10 19:28:44
* @Last Modified time: 2022-09-10 20:19:57
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
        
        int n, q;
        cin>>n>>q;

        int a[n+1];
        for(int i=0 ; i<n ; i++)
            a[i]=i+1;

        ll odd=0, even=0;
        bool oddin1=1, evenin1=0;
        while(q--)
        {
            int type;
            cin>>type;
            if(type==1)
            {
                int x;
                cin>>x;

                if(x<0)
                    x=n+x;
                
                if(x%2)
                {
                    evenin1=1;
                    oddin1=0;
                }
                else
                {
                    evenin1=0;
                    oddin1=1;
                }

                odd+=x;
                even+=x;
                
               /* int temp[n];

                for(int i=0 ; i<n ; i++)
                {
                    temp[(i+x)%n]=a[i];
                }

                for(int i=0 ; i<n ; i++)
                    a[i]=temp[i];

                for(int i=0 ; i<n ; i++)
                    cout<<a[i]<<" ";
                cout<<endl;*/
            }
            else
            {
                /*for(int i=1 ; i<n ; i+=2)
                 swap(a[i], a[i-1]);

                for(int i=0 ; i<n ; i++)
                    cout<<a[i]<<" ";
                cout<<endl;*/
               
               if(odd%2==0) 
               {
                 odd++;
                 even+=n-1;
               }
               else
               {
                   even++;
                   odd+=n-1;
               }
            }
        }

       
        for(int i=0 ; i<n ; i++)
            a[i]=i+1;
        int temp[n];

        for(int i=0 ; i<n ; i++)
        {
            if(i%2==0)
                temp[(i+odd)%n]=a[i];
            else
                temp[(i+even)%n]=a[i];
        }
        for(auto i:temp)
            cout<<i<<" ";
      
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