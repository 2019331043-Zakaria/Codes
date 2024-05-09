/*
* @Author: Zakaria 
* @Date:   2022-12-17 22:03:50
* @Last Modified time: 2022-12-27 12:24:38
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



void Solve()
{
        
      int n, m;
      cin>>n>>m;

      int tot = 0;
      
    
      map<int, int>cntone;

      int a[n+1][m+1];

      for(int i=1 ; i<=n ; i++)
      {
      	  int x;
      	 
      	  int one = 0;

      	  for(int j=1 ; j<=m ; j++)
      	  {
      	  	cin>>x;
      	  	a[i][j] = x;
      	  	one+=x;
      	  }
      	  tot+=one;

      	  cntone[i] = one;

      }

      if(tot%n)
      {
      	  cout<<"-1"<<endl;
      	  return ;
      }

      int lage = tot/n;


      map<int, set<int> > onerow, zerorow;


      for(int j = 1 ; j<=m ; j++)
      {
         for(int i = 1 ; i<=n ; i++)
         {

            if(a[i][j] && cntone[i]>lage)
                onerow[j].insert(i);
            else if(a[i][j]==0 && cntone[i]<lage)
                zerorow[j].insert(i);

         }
      }
      

     /* cout<<lage<<endl;

      for(int j=1 ; j<=n ; j++)
      {
         cout<<j<<" => "<<cntone[j]<<endl;
      }
*/
      
      vector<pair<int, pair<int,int> > > ans;

      set<int>st;

      


      for(int i = 1 ; i<=n ; i++)
      {
         for(int j=1 ; j<=m ; j++)
         {
             if(cntone[i]<lage)
             {
                if(a[i][j]==0)
                {
                    

                    while(onerow[j].size())
                    {
                        if(cntone[*onerow[j].begin()]!=lage)
                            break;
                        else
                            onerow[j].erase(onerow[j].begin());

                    }

                    if(onerow[j].size()==0)
                    {
                        continue;
                    }

                    int temp = *onerow[j].begin();

                 

                    ans.push_back({i, {temp, j}});
                    a[temp][j]=0;
                    cntone[temp]--;
                    cntone[i]++;
                    onerow[j].erase(temp);
                    zerorow[j].erase(i);


                }
             }
             else if(cntone[i]>lage) // cnt1>lage
             {
                if(a[i][j])
                {
                    while(zerorow[j].size())
                    {
                       
                        if(cntone[*zerorow[j].begin()]!=lage)
                            break;
                        else
                            zerorow[j].erase(zerorow[j].begin());

                    }

                    if(zerorow[j].size()==0)
                    {
                        continue;
                    }

                    
                    int temp = *zerorow[j].begin();
                    
                   

                    ans.push_back({i, {temp, j}});
                    a[temp][j] = 1;
                    cntone[i]--;
                    cntone[temp]++;
                    zerorow[j].erase(temp);
                    onerow[j].erase(i);
                    
                }
             }

         }
      }

      cout<<ans.size()<<endl;

      for(auto i:ans)
        cout<<i.f<<" "<<i.s.f<<" "<<i.s.s<<endl;

     
    
      

}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;
        
        cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 