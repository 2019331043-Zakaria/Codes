#include<bits/stdc++.h>
#define pb       push_back
#define mp       make_pair
#define mod      1000000007
#define first    ff
#define second   ss
#define pi       acos(-1.0)
#define bg       begin()
#define end       end()
#define test     int t;cin>>t;while(t--)
typedef long long ll;
using namespace std;
int cnt1[1000000],cnt2[1000000];
vector<int>v1,v2;
int main()
{


     ios::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);

     int n;
     cin>>n;
     int x;
     int mx=0,mx1=0,mx2=0;
     for(int i=0;i<n;i++)
     {
         cin>>x;

         cnt1[x]++;
         mx=max(mx,x);
         mx1=max(mx1,x);
     }
     for(int i=0;i<n;i++)
     {
         cin>>x;
         cnt2[x]++;
          mx=max(mx,x);
        mx2=max(mx2,x);
     }

        int ans1=0,ans2=0,ans=0;
     for (int i =mx ; i>1; i--)
     {

        int j=i;
        int flag=0;
        int temp1=0,temp2=0;
          ans1=0,ans2=0;
      while(j<=mx)
      {
        if(cnt1[j]&&cnt2[j])
        {
            ans=max(ans,2*j);


        }
        else
        {

           if(cnt1[j])
           {
            temp1++;
            v1.push_back(j);
           }
           if(cnt2[j])
            temp2++,v2.push_back(j);
           if(temp1==1&&cnt2[j])
           {
                flag=1;
                v1.push_back(j);
               ans1=v1[v1.size()-1]+v1[v1.size()-2];
           }
           if(temp2==1&&cnt1[j])
           {
                flag=1;
             v2.push_back(j);
                ans2=v2[v2.size()-1]+v2[v2.size()-2];
           }


        }
       j+=i;


         if(flag)
         {
            cout<<max(ans,max(ans2,ans1))<<endl;
            return 0;
         }

       }
       temp2=0,temp1=0;
       v1.clear(),v2.clear();

    }

    if(!max(ans1,ans2))
    {
        cout<<mx1+mx2<<endl;
    }



      return 0;

 }
