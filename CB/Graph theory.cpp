#include<bits/stdc++.h>
#define test int t; cin>>t; while(t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define mp make_pair
typedef long long ll;
using namespace std;
int main()
{
    test
    {
         int n,m;
         cin>>n>>m;
         int a[n];
         for(int i=0;i<n;i++)
            cin>>a[i];
         int x;
          map<int,int>y;
          vector<int>v;
          int b[m];
          for(int i=0;i<m;i++)
            cin>>b[i];
          sort(b,b+m);

       for(int i=0;i<m;i++)
       {
           x=b[i];
           if(y.find(x)==y.end())
            {
                v.push_back(x);
                y[x]=i;
            }
          if(y.find(x+1)==y.end())
          {
              v.push_back(x+1);
              y[x+1]=i;
          }
       }
              int temp1=v[0],temp;
//          for(int i=1;i<v.size();i++)
//          {
//              if(v[i]-v[i-1]>1)
//                {
//                    sort(a+temp1,a+v[i-1]+1);
//                    temp1=v[i];
//                }
//
//          }
//
//          for(int i=0;i<n;i++)
//            cout<<a[i]<<" ";
//          cout<<endl<<endl;;

              vector<pair<int,int>>p;
              int flag;
            for(int i=1;i<v.size();i++)
            {
                flag=1;
                if((v[i]-v[i-1])<=1)
                {

//                    p.push_back(make_pair(temp1,temp));
//                    temp1=v[i];

                     temp=v[i];

                }
                else
                {
                    p.push_back(make_pair(temp1,temp));
                    temp1=v[i];
                    flag=0;
                }
            }
            if(flag)
                p.push_back(make_pair(temp1,temp));



            for(int i=0;i<p.size();i++)
                {
                    if(p[i].second==n)
                        sort(a+p[i].first-1,a+p[i].second);
                    else
                        sort(a+p[i].first-1,a+p[i].second+1);
                }

                int cnt=0;
             for(int i=0;i<n;i++)
               {
                  cout<<a[i]<<" ";
               }
               cout<<endl;
//               if(cnt)
//                cout<<"NO"<<endl;
//               else
//                cout<<"YES"<<endl;


   }

   return 0;
}
