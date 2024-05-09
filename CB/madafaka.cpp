#include<bits/stdc++.h>
using namespace std;
int main()
{
      int t;
      cin>>t;
      while(t--)
      {
          int x;
          cin>>x;
          int a[x];
          char b[x];
        int cnt=0;
        for(int i=0;i<x;i++)
        {
            cin>>a[i];
            if(a[i]<a[i-1])
                cnt++;
        }
        int cnt1=0,cnto=0;
        for(int j=0;j<x;j++)
        {
            cin>>b[j];
            if(b[j]=='0')
                cnto++;
            else
                cnt1++;
        }
        if(cnt!=0)
        {
            if(cnto==0||cnt1==0)
                cout<<"N0"<<endl;
            else
                cout<<"Yes"<<endl;
        }
            else
                cout<<"Yes"<<endl;


      }
return 0;
}
