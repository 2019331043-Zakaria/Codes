#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define int ll
#define endl '\n'
string s;
char dp[2000][2000][26][2];

int DP(int i, int j, int alice, int who) {
    // cout << i << ' ' << j << endl;
    if(i > j) return 1;

    if(dp[i][j][alice][who] != -1) return dp[i][j][alice][who];

    int ret;

    if(who) {
        int best = DP(i+1, j, s[i] - 'a', who ^ 1);
        best = max(best, DP(i, j-1, s[j] - 'a', who ^ 1));

        ret = best;
    }

    else {
        int best1 = DP(i+1, j, alice, who ^ 1);
        if(best1 == 1) {
            if(alice > s[i] - 'a') best1 = 2;
            else if(alice < s[i] - 'a') best1 = 0;
            else best1 = 1;
        }


        int best2 = DP(i, j-1, alice, who ^ 1);
        if(best2 == 1) {
            if(alice > s[j] - 'a') best2 = 2;
            else if(alice < s[j] - 'a') best2 = 0;
            else best2 = 1;
        }

        ret = min(best1, best2);
    }

    return dp[i][j][alice][who] = ret;
}

void solve(ll tt) {
    cin >> s;
    for(int i=0; i<s.size(); i++) {
        memset(dp[i], -1, sizeof dp[i]);
    }

    int ans = DP(0, s.size()-1, 0, 1);

    if(ans == 1) cout << "Draw" << endl;
    else cout << (ans ? "Alice" : "Bob") << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1;
    cin >> T;
    for(int i=1; i<=T; i++) {
        solve(i);
    }

    return 0;   
}