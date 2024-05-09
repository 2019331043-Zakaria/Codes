#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define testcase int t; scanf("%d ",&t); while(t--)
#define pb push_back
typedef long long ll;
using namespace std;
int main()
{

    testcase{

     string s;
     vector<char>v[200];
     char a[2000];
     memset(a,0,sizeof(a));
     gets(a);
     int n=strlen(a);
     for(int i=0;i<n;i++)
     s+=a[i];
     int temp=0;
     for(int i=0;i<n;i++)
     {
        if(s[i]!=' ')
            v[temp].push_back(s[i]);
            else
                temp++;
    }
       string vec[200];
       string cnt;
    for(int i=0;i<=temp;i++)
    {
        for(int j=0;j<v[i].size();j++)
           cnt+=v[i][j];
           vec[i]=cnt;

           cnt="";
    }



         vector<int>occur;
         cout<<"Words are : "<<endl;
         vector<int>l;
       for(int i=0;i<=temp;i++)
       {
           cout<<vec[i]<<endl;
           l.push_back(vec[i].size());
       }
      sort(l.begin(),l.end());
       cout<<"shortest word :"<<endl;
       for(int i=0;i<=temp;i++)
       {
           if(vec[i].size()==l[0])
            cout<<vec[i]<<endl;
       }
       cout<<"Longest word :"<<endl;
        for(int i=0;i<=temp;i++)
       {
           if(vec[i].size()==l[l.size()-1])
            cout<<vec[i]<<endl;
       }

    }
return 0;
}
