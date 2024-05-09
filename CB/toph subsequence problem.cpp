#include<bits/stdc++.h>
#define test int t; cin>>t; while(t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
using namespace std;
 vector<int>v[30];
int main()
{
       int n,temp;
       cin>>n;
       vector<char>bin;
       string s,p;
       cin>>s;
       for(int i=0;i<n;i++)
       {
           bin.push_back(s[i]);
           temp=s[i]-'a';
           v[temp].push_back(i);
       }
       sort(bin.begin(),bin.end());
       int m;
       cin>>m;
       while(m--)
       {
           cin>>p;
           int flag=1,temp1,temp2,d;
           int x=p.length();
           int cnt=1;
           for(int i=0;i<x;i++)
           {
               if(!(binary_search(bin.begin(),bin.end(),p[i])))
               {
                   flag=0;
                   break;
               }
           }
           if(flag){
           temp1=p[0]-'a';
           temp1=v[temp1][0];
            int y=0;
           for(int i=1;i<x;i++)
           {

               temp2=p[i]-'a';

                   d=upper_bound(v[temp2].begin(),v[temp2].end(),temp1)-v[temp2].begin();
                  if(v[temp2][d]==0)
                  {
                      flag=0;
                      break;
                  }
                       temp1=v[temp2][d];

           }
             if(flag)
                cout<<"YES"<<endl;
             else
                cout<<"NO"<<endl;

       }
       else
        cout<<"NO"<<endl;
       }


    return 0;
}
