#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

int parent[1000];


void init(int n)
{
    for(int i=1;i<=n;i++){
        parent[i]=i;
    }
}

int find_par(int x)
{
    if(parent[x]==x ){
        return x;
    }
    parent[x]= find_par(parent[x] );
    return parent[x];
}

void unity(int x,int y)
{
    int a,b;
    a=find_par(x);
    b=find_par(y);

    if(a!=b){
        parent[a]=b;
    }
    return;
}



int main()
{
    int n,con;
    cin>>n>>con;

    init(n);

    for(int i=0;i<con;i++){
        int x,y;
        cin>>x>>y;
        unity(x,y);

    }

    for(int i=1;i<=n;i++){
        cout<<i<<" "<<find_par(i)<<endl;
    }

    return 0;
}

/**
9 7
1 3
4 5
2 3
2 4
6 3
7 6
8 9
*/