#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
typedef long long ll;
using namespace std;
int binsearch(int p,int l,int r,int a[])
{

       int m;
    while(l<=r)
    {

        m=(l+r)/2;
        if(a[m]==p)
            return m;
        if(a[m]<p)
            l=m+1;
        else
            r=m-1;

    }
    return -1;



}

int main()
{
     int n;
     cin>>n;
     int a[n];
     for(int i=0;i<n;i++)
        cin>>a[i];
     sort(a,a+n);

     int x;
     cin>>x;
     cout<<binsearch(x,0,n-1,a);
    return 0;


}
