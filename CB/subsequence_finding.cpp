#include<bits/stdc++.h>
#define test int t; cin>>t; while(t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
using namespace std;

int main()
{
   
    string s;
    int i,l,q,x;
    vector<int>pos[30];
    cin >> l >> s;
    for(i=0;i<l;i++)pos[s[i]-'a'].push_back(i);
    cin >> q;
    while(q--)
    {
        cin >> s;
        l=s.size(),x=-1;
        for(i=0;i<l;i++)
        {
            auto it=upper_bound(pos[s[i]-'a'].begin(),pos[s[i]-'a'].end(),x);
            if(it == pos[s[i]-'a'].end())break;
            x=*(it);
        }
        if(i == l)cout << "YES\n";
        else cout << "NO\n";
    }
   

    return 0;
}