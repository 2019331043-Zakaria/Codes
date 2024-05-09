/*
* @Author: Zakaria
* @Date:   2022-09-12 01:22:12
* @Last Modified time: 2022-09-12 01:22:56
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

int ask(int i, int j)
{
    cout<<"? "<<i<<" "<<j<<endl<<flush;
    char c;
    cin>>c;

    if(c=='<')
        return j;
    else
        return i;
}

void Solve()
{
       int n;
       cin>>n;

       if(n==1)
       {
            cout<<"! 1"<<" "<<1<<endl<<flush;
            return ;
       }

       vector<int>minarry, maxarray;

       for(int i=1 ; i<n ; i+=2)
       {
           int j=i+1;
           int x = ask(i, j);

           if(x==i && x==j)
            maxarray.push_back(x), minarry.push_back(x);
           else if(x==i)
             maxarray.push_back(i), minarry.push_back(j);
           else if(x==j)
             maxarray.push_back(j), minarry.push_back(i);

       }

       if(n%2)
        maxarray.push_back(n), minarry.push_back(n);

       while(maxarray.size()>=2)
       {
            vector<int>temp;
            while(maxarray.size()>=2)
            {
                int i=maxarray.back();
                maxarray.pop_back();
                int j=maxarray.back();
                maxarray.pop_back();

                int x = ask(i, j);

                temp.push_back(x);

            }
            if(maxarray.size())
                temp.push_back(maxarray.back());
            maxarray=temp;
       }

       int posmax = maxarray.back();
       swap(maxarray, minarry);

       while(maxarray.size()>=2)
       {
            vector<int>temp;
            while(maxarray.size()>=2)
            {
                int i=maxarray.back();
                maxarray.pop_back();
                int j=maxarray.back();
                maxarray.pop_back();

                int x = ask(i, j);
                if(x==i && x==j)
                temp.push_back(x);
                else if(x!=i)
                temp.push_back(i);
                else if(x!=j)
                temp.push_back(j);

            }
            if(maxarray.size())
                temp.push_back(maxarray.back());
            maxarray=temp;
       }

       int posmin=maxarray.back();

       cout<<"! "<<posmin<<" "<<posmax<<endl<<flush;



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
