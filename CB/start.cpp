#include<bits/stdc++.h>
#define vector   vec;
#define pb       push_back
#define mp       make_pair
#define mod      1000000007
typedef long long ll;
using namespace std;
b_search(int a[],int n,int k)
{
    int low=0,high=n,mid;
    int ans=-1;
    while(low<high)
    {

        mid=(high+low)/2;
        if(a[mid]>=k)
        {
              ans=mid;
              high=mid-1;

        }
        else
        {
            low=mid+1;
        }

    }
    
  return ans;

}


int main()
{  

    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    int k;
    cin>>k;
   cout<<b_search(a,n,k)<<endl;


  
   return 0;
}