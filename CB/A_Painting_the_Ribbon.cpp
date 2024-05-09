#include<bits/stdc++.h>

using namespace std;

void solve(){
    int a, b, c;
    cin >> a >> b >> c;
    if(b==1){
        cout << "NO" << endl;
        return;
    }
    int maxi = ceil(double(a)/b);
    //cout << maxi<< endl;



    if(c<(a-maxi)){
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;
    
    return;
}

int main(){
    int cas;
    cin >>cas;
    while(cas--){
        solve();
    }

    return 0;
}