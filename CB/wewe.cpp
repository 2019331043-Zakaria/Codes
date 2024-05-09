#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
   int t;
   cin>>t;
  for(int i=1;i<=t;i++)
  {
       ll n,j,ans;
       double temp;
       cin>>n;

       for( j=1;j<=35;j++)
       {
           temp=pow(n,1.0/j);
           if(floor(temp)==ceil(temp))
             {
                 temp=int(temp);
                 cout<<temp<<" ";
             }
       }
       cout<<endl;
  }
    return 0;
}
