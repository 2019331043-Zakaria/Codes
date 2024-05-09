#include<bits/stdc++.h>
//#define test int t; cin>>t; while(t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
using namespace std;
int main()
{


               vector<int>taxi;
               vector<int>pizza;
               vector<int>chicks;
               vector<string>v;

         int t,mxt=0,mxp=0,mxc=0;
         cin>>t;
         for(int i=1;i<=t;i++)
         {


               int n;
              string temp;
              cin>>n>>temp;
              v.push_back(temp);
          int t=0,p=0,c=0;
          string s;
          while(n--)
          {

            cin>>s;
            if(s[0]==s[1]&&s[1]==s[3]&&s[3]==s[4]&&s[4]==s[6]&&s[6]==s[7])
                t++;
            else if(s[0]>s[1]&&s[1]>s[3]&&s[3]>s[4]&&s[4]>s[6]&&s[6]>s[7])
                p++;
                else
                    c++;
          }
            mxt=max(mxt,t);
            mxp=max(mxp,p);
            mxc=max(mxc,c);
            taxi.push_back(t);
            pizza.push_back(p);
            chicks.push_back(c);

         }
          vector<string>anst,ansp,ansc;

         for(int i=0;i<taxi.size();i++)
         {
             if(taxi[i]==mxt)
                anst.push_back(v[i]);

         }

         for(int i=0;i<pizza.size();i++)
         {
             if(pizza[i]==mxp)
                ansp.push_back(v[i]);
         }

          for(int i=0;i<chicks.size();i++)
         {
             if(chicks[i]==mxc)
                ansc.push_back(v[i]);
         }
        cout<<"If you want to call a taxi, you should call:";
        for(int i=0;i<anst.size();i++)
        {
            if(i==anst.size()-1)
                cout<<" "<<anst[i]<<"."<<endl;
            else
                cout<<" "<<anst[i]<<",";
        }
        cout<<"If you want to order a pizza, you should call:";

        for(int i=0;i<ansp.size();i++)
        {
            if(i==ansp.size()-1)
                cout<<" "<<ansp[i]<<"."<<endl;
            else
                cout<<" "<<ansp[i]<<",";
        }

        cout<<"If you want to go to a cafe with a wonderful girl, you should call:";
        for(int i=0;i<ansc.size();i++)
        {
            if(i==ansc.size()-1)
                cout<<" "<<ansc[i]<<"."<<endl;
            else
                cout<<" "<<ansc[i]<<",";
        }

return 0;
}
