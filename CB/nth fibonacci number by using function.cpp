#include<bits/stdc++.h>
//#define push_back pb
#define make_pair mp

using namespace std;

int fibo(int n)
{
    int    a=0,b=1,c=1;
    for(int i=1;i<n;i++)
    {
        c=a+b;
        a=b;
        b=c;
    }
    if(n==0)
        return a;
    if(n==1)
        return b;
    return c;
}






int main()
{


         int n;int t;
         cin>>t;
         while(t--){
         cin>>n;
         cout<<"fibonacci("<<n<<") is "<<fibo(n);
         }
    return 0;
}
