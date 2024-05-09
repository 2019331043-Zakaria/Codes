#include<bits/stdc++.h>
using namespace std;
#define ll  long long

main () {
    ll p;
    cin >> p;
    vector < ll > ans (p, -1);
    for (ll i = 0; i < p; i++) ans[i * i % p] = i;

    for(int i=0 ; i<p ; i++)
        cout<<ans[i]<<" ";
    cout<<endl;
    
    for (ll i = 0; i < p; i++) cout << ans[i] << " \n"[i == p - 1];
}
