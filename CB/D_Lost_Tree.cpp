/*
* @Author: Zakaria
* @Date:   2022-09-16 23:17:27
* @Last Modified time: 2022-09-16 23:17:41
*/
#include <bits/stdc++.h>
#define  pb          push_back
#define  f           first
#define  s           second
#define  pi          acos(-1.0)
#define  LCM(a,b)    a*b/__gcd(a,b)
#define  GCD(a,b)    __gcd(a,b)
#define  sof         sizeof
#define  endl        '\n'
#define  eps         1e-6
typedef long long ll;
using namespace std;

const int mod = 1e9+7;
const int N = 2e5+6;

vector<int>node[N];
vector<pair<int, int> > ans;

vector<int> query(int p, int n)
{
      cout<<"? "<<p<<endl<<flush;

      vector<int>v;
      v.push_back(-1);

      for(int i=0 ; i<n ; i++)
      {
          int x;
          cin>>x;
          v.push_back(x);
      }

      return v;

}

void dfs(int p, int par)
{

      for(auto i:node[p])
      {
          if(i==par)
            continue;
          ans.push_back({i, p});
          dfs(i, p);

      }
}

void Solve()
{

        int n;
        cin>>n;

        vector<int>dis;
        dis=query(1, n);
        vector<int>odd, even;

        for(int i=2 ; i<=n ; i++)
        {
            if(dis[i]==1)
            {
                node[1].push_back(i);
                node[i].push_back(1);
            }

            if(dis[i]%2)
            {
                odd.push_back(i);
            }
            else
            {
                even.push_back(i);
            }
        }

        if(odd.size()>even.size())
            swap(odd, even);



        for(auto i:odd)
        {

             vector<int>dis;
             dis=query(i, n);

             for(int j=1 ; j<=n ; j++)
             {
                 if(dis[j]==1)
                 {
                     node[j].push_back(i);
                     node[i].push_back(j);
                 }
             }
        }

        dfs(1, 0);

        cout<<"!"<<endl;
        for(auto i:ans)
        {
            if(n<=1)
                continue;
            if(i.f && i.s)
                cout<<i.f<<" "<<i.s<<endl;
            n--;
        }
}

int main()
{

        ios::sync_with_stdio(false);
        cin.tie(0);

        int tt=1;

     //   cin>>tt;

        while(tt--)
        {

            Solve();
        }

        return 0;

}
