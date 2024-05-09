#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define test int t; cin>>t; for(int i=1;i<=t;i++)
#define pb push_back
#define sof sizeof
typedef long long ll;
using namespace std;
int main()
{
    test
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        int cnt=0;
        string ans;
        int a[126];
        memset(a,0,sof(a));
        int x;
        int flag=0;
        for(int i=1;i<n;i=i+2)
        {
            if(s[i-1]==s[i])
            {
                flag=1;
                break;

            }
        }
        if(n%2)
        {
            if(s[n-1]==s[n-2])
                flag=1;
        }
        if(!flag)
            cout<<0<<endl<<s<<endl;
        else
        {
             for(int i=0;i<n;i++)
             {
                 x=s[i]-'0';
                 a[x]++;
             }
             vector<int>v;
             for(int i=0;i<126;i++)
             {
                 if(a[i])
                    v.push_back(a[i]);
             }
             char z;
             vector<pair<int,char>>c;

             for(int i=0;i<126;i++)
             {
                 if(a[i])
                 {
                     z=i+'0';
                     c.push_back(make_pair(a[i],z));
                 }
             }
             sort(c.begin(),c.end());

             sort(v.begin(),v.end());
             reverse(v.begin(),v.end());
             if(v.size()==1)
                cout<<0<<endl;
             else
             {
                 int sum=0;
                 for(int i=1;i<v.size();i++)
                        sum+=v[i];

             //cout<<v[0]<<" "<<sum<<endl;
               int y=c.size();
             if(v[0]<=sum+1)
             {
                 if(n%2)
                 {
                     cout<<1<<endl;
                    cnt=0;
                    flag=0;
                    while(1)
                    {
                        for(int i=0;i<y;i++)
                        {

                            if(c[i].first){
                                 cnt++;
                            cout<<c[i].second;
                            c[i].first--;
                            if(cnt==n-1)
                                {
                                    flag=1;
                                    break;
                                }
                                cnt++;
                                if(cnt==n-1)
                                {
                                    flag=1;
                                    break;
                                }
                                if(c[y-1].first){
                                cout<<c[y-1].second;
                                c[y-1].first--;
                                }
                                else
                                   y--;
                                if(i==y)
                                {
                                    flag=1;
                                    break;
                                }
                        }
                        if(flag)
                            break;
                    }
                 }
                 }
                 else
                 {



                     cout<<2<<endl;
                    cnt=0;
                    flag=0;
                    while(1)
                    {
                        for(int i=0;i<y;i++)
                        {
                            if(c[i].first){
                            cnt++;
                            cout<<c[i].second;
                             c[i].first--;
                            if(cnt==n-2)
                            {
                                flag=1;
                                break;
                            }
                            cnt++;
                            if(cnt==n-2)
                            {
                                flag=1;
                                break;
                            }
                            if(c[y-1].first){
                            cout<<c[y-1].second;
                             c[y-1].first--;
                            }
                            else
                               y--;
                            }

                        }
                        if(flag)
                            break;
                    }






                 }

             }
             else
             {


                     cnt=0;
                     flag=0;
                     while(1)
                     {
                         for(int i=0;i<c.size();i++)
                         {
                             if(c[i].first){
                             cnt++;
                             ans+=c[i].second;
                             c[i].first--;
                             }
                             if(cnt==2*sum-1)
                             {
                                 flag=1;
                                 break;
                             }

                         }
                         if(flag)
                            break;
                     }


                   cout<<n-ans.size()<<endl<<ans<<endl;








             }


             }

        }
        cout<<endl;

    }

return 0;

}



