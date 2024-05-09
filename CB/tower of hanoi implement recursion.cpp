#include<bits/stdc++.h>
#define test int t; cin>>t; while(t--)
#define fast ios::sync_with_stdio(false);
#define pb push_back
typedef long long ll;
using namespace std;
void tower(int n,char A,char C,char B)
{

     if(!n)
        return ;
    tower(n-1,A,B,C);
    
    cout<<"Disk #"<<n<<" from "<<A<<" "<<C<<endl;

    tower(n-1,B,C,A);



}

int main()
{
    fast
    
       int n,cnt=0;
       cin>>n;
       cout<<"solution for n disk: "<<endl;
       tower(n,'A','C','B');
    

    return 0;
}

