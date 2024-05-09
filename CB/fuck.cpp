#include <bits/stdc++.h>
#include <stdio.h>
#define fin freopen("input", "r", stdin)
#define whatis(x) cerr << #x << ": " << x << endl;

using namespace std;
using ll = long long;

#define mx 10000
int ar[mx];
int tree[mx];

int getMIN(int idx){
    int sum = INT_MAX;
    while (idx > 0){
        sum = min(tree[idx], sum);
        idx -= (idx & -idx);
    }
    return sum;
}

void update(int idx, int val, int n){
    while (idx <= n){
        tree[idx] = min(val, tree[idx]);
        idx += (idx & -idx);
    }
}

void print(int *ar, int n) {
    for (int i = 1; i <= n; ++i) {
        cout << ar[i] << " ";
    }
    puts("");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    
    for(int i=1 ; i<=n ; i++)
        tree[i]=INT_MAX;


    for (int i = 1; i <= n; ++i) { cin >> ar[i]; update(i, ar[i], n); }

    cout << "input array:\t";
    print(ar, n);
    cout << "\n";

    cout<<read(5);
    return 0;
}