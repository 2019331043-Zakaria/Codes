#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define testcase int t; scanf("%d ",&t); for(int k=1;k<=t;k++)
#define pb push_back
#define sz 200007
typedef long long ll;
using namespace std;
int main()
{
    testcase
    {
        int n;
        cin>>n;
        ll cnt=0;
        int temp;
        int m=0;
         while(n>0)
         {
             if(n%2)
               m++;
             n=n/2;

         }
         m=pow(2,m);
           for(int i=0;i<m;i++)
           {
               temp=0;
               int pro=1;
               int x=i;
               while(x)
               {
                   if(x%2)
                    {
                        temp++;
                         pro=pro*2;
                    }
                   x=x/2;

               }
             cnt+=pro;
           }
           cout<<cnt<<endl;


        }



    return 0;

}

