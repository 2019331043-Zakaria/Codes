#include<bits/stdc++.h>
#define test int t; cin>>t; while(t--)
#define fast ios::sync_with_stdio(false);
#define pb push_back
int main()
{

   test
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        string s=string(n,'a');
         int k=1;
        while(b>k)
        {
            b-=k;
            k++;
        }
        s[n-k-b]=='b';
        s[n-b]=='b';
        cout<<s<<endl;
    }
    return 0;

}
