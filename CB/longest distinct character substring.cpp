#include<bits/stdc++.h>
#define pb       push_back
#define mp       make_pair
#define memset   mem
#define sizeof   sof
#define mod      1000000007
#define sz       430
typedef long long ll;
using namespace std;
int main()
{

    string s;
    cin>>s;
    int n=s.size();
    vector<int>lastchar(sz,-1);
    int res=0;
    int j=0;
    vector<int>v;
    for(int i=0;i<n;i++)
    {
        j=max(j,lastchar[s[i]]+1);

        res=max(res,i-j+1);
        v.push_back(i-j+1);

        lastchar[s[i]]=i;

    }

   cout<<res<<endl;

   return 0;

}
