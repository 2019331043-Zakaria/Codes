#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
typedef long long ll;
using namespace std;
int main()
{
    int n;
    cin>>n;
    string temp,s;
    vector<string>v;
    cin>>temp;
    v.push_back(temp);
    int a[150];
    memset(a,0,sizeof(a));
    int x;
    for(int i=0;i<temp.size();i++)
    {
        x=temp[i]-'0';
        a[x]++;
    }
    int flag=0;
    for(int i=0;i<n-1;i++)
    {
       cin>>s;
       v.push_back(s);
       for(int i=0;i<s.size();i++)
       {
          x=s[i]-'0';
          if(a[x]==0)
            flag=1;
       }
    }
    if(flag==1)
        cout<<-1<<endl;
    else
    {
        ll mn=10000000,cnt=0;
       for(int i=0;i<temp.size();i++)
       {
           for(int j=0;j<v.size();j++)
           {
               for(int k=0;k<temp.size();k++)
               {
                   if(v[j][k]!=temp[i])
                    cnt++;
                   else
                    break;
               }
           }
          cout<<cnt<<endl;
            cnt=0;
       }
      cout<<mn<<endl;

    }




return 0;

}
