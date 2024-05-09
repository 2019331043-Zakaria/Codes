#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
typedef long long ll;
using namespace std;
int main()
{

     int n;
     cin>>n;
     int a[n];
     for(int i=0;i<n;i++)
        cin>>a[i];
     sort(a,a+n);
     if(a[n-1]==1)
        cout<<1<<endl;
     else
     {
         reverse(a,a+n);
         int cnt=1;
         int temp=a[0];
         //cout<<temp<<endl;
         for(int i=1;i<n;i++)
         {
             if(a[i]==temp)
                cnt++;
         }
         if(cnt==1)
            cout<<temp-1<<endl;
         else
            cout<<temp<<endl;

     }


return 0;

}
