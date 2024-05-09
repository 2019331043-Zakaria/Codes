#include<bits/stdc++.h>
#define test int t; cin>>t; while(t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
typedef long long ll;
using namespace std;
int main()
{
    test
    {
       string s,p;

       cin>>s>>p;
       int flag;
       for(int i=1;i<p.size();i++)
       {
           if(p[i-1]<p[i])
           {
               flag=1;
               break;
           }
           else if(p[i-1]>p[i])
           {
               flag=0;
               break;
           }
       }
      // cout<<flag<<endl;

       int a[130];
       memset(a,0,sizeof(a));
       sort(s.begin(),s.end());
       for(int i=0;i<s.size();i++)
         a[int(s[i])]++;

        for(int i=0;i<p.size();i++)
            a[int(p[i])]--;

            if(flag){
        for(int i=97;i<=int(p[0]);i++)
        {
            for(int j=0;j<a[i];j++)
                    {
                        cout<<char(i);
                    }
        }
        cout<<p;
        for(int i=int(p[0])+1;i<=123;i++)
        {

            for(int j=0;j<a[i];j++)
                cout<<char(i);
        }
        cout<<endl;
        }
        else
        {

            for(int i=97;i<int(p[0]);i++)
        {
            for(int j=0;j<a[i];j++)
                    {
                        cout<<char(i);
                    }
                    a[i]=0;
        }
        cout<<p;
        for(int i=97;i<=123;i++)
        {

            for(int j=0;j<a[i];j++)
                cout<<char(i);
        }
        cout<<endl;

        }


    }

return 0;
}

