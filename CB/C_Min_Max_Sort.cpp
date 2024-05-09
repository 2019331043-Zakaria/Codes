/*............bismillahir rahmanir rahim...............*/

// author :  Muhammad Najmul Hasan Nayeem (SUST MATH 17)

#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/trie_policy.hpp>
// using namespace __gnu_pbds;
 
using namespace std;

#define ff first
#define ss second
#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}

typedef long long ll;
typedef unsigned long long ull;

// typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

mt19937 mt_rand(chrono::high_resolution_clock::now().time_since_epoch().count());
const int N = 2e5 + 5;

void solve() {
    vector<int> cnt(4);
    for (auto &i: cnt) cin >> i;
    int a = cnt[0], b = cnt[0], res = cnt[0];
    // int cc = 0;
    while (1) {
        // cc++;
        // if (cc == 10) break;
        bool f = false;
        if (b > 0 && cnt[1] > 0) {
            int x = min(b, cnt[1]);
            cnt[1] -= x;
            a += x;
            b -= x;
            res += x;
            f = true;
        } 
        if (a > 0 && cnt[2] > 0) {
            int x = min(a, cnt[2]);
            cnt[2] -= x;
            a -= x;
            b += x;
            res += x;
            f = true;
        }
        if (!f) break;
        // cout << a << ' ' << b << endl;
    }
    int x = min({a , b, cnt[3]});
    res += x;
    a -= x;
    b -= x;
    cnt[3] -= x;
    if (cnt[3] || cnt[1] || cnt[2]) {
        res++;
    }
    cout << res << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);//cin.tie(NULL);cout.tie(NULL);
    int q=1;
    cin>>q;
    // SI(q);
    for(int kase=1; kase<=q; kase++)
    {
        // cout<<"Case "<<kase<<":\n";
        // printf("Case %d: ",kase );
        solve();
    }
    return 0;
}