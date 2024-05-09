#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
typedef long long ll;
using namespace std;
int main()
{
       int t;
       cin>>t;
       while(t--)
       {

           int x,y,z;
           cin>>x>>y>>z;
           if(x!=y&&y!=z&&z!=x)
            cout<<"NO"<<endl;
           else if(x==y&&x==z&&z==y)
             cout<<"YES"<<endl<<x<<" "<<y<<" "<<z<<endl;
           else if((x==y&&z>x)||(y==z&&x>y)||(x==z&&y>z))
            cout<<"NO"<<endl;
            else
            {
                if(x==y)
                    cout<<"YES"<<endl<<z<<" "<<x<<" "<<z<<endl;
                else if(y==z)
                    cout<<"YES"<<endl<<x<<" "<<y<<" "<<x<<endl;
                else
                cout<<"YES"<<endl<<y<<" "<<x<<" "<<y<<endl;


            }





       }



return 0;
}


