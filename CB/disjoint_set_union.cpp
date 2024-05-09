int n,m;
int Parent[N], Rank[N];

void Init(int n)
{
          for(int i=1 ; i<=n ; i++)
            Rank[i]=1, Parent[i]=i;
}

int Find_Parent(int v)
{
    if (v == Parent[v]) 
        return v;

    return Parent[v] = Find_Parent(Parent[v]);
}
 
void Union(int a, int b)
{
    a = Find_Parent(a);
    b = Find_Parent(b);
    
    if (a != b) 
    {

        if (Rank[a] > Rank[b]) 
            swap (a, b);
                
        Parent[a] = b;
        Rank[b] += Rank[a];
    }
}

int main()
{
        
        
        cin>>n>>m;
        
        Init(n);


        for(int i=1 ; i<=m;i++)
        {
            int u,v;
            cin>>u>>v;
            Union(u,v);
        }

        for(int i=1 ;i<=n; i++)
            cout<<Find_Parent(i)<<" ";
        cout<<endl;
        
       

        

        

return 0;

} 

/*struct dsu{
    int n;
    vector<int>par, rnk;
    void init(int _n){
        n = _n;
        par.resize(n+1), rnk.resize(n+1, 0);
        for(int i=1; i<=n; i++) par[i] = i;
    }
    bool unite(int u, int v){
        u = faind(u), v = faind(v);
        if(u==v) return false;
        if(rnk[u]>rnk[v]) swap(u,v);
        par[u] = v;
        if(rnk[u]==rnk[v]) rnk[v]++;
        return true;
    }
    int faind(int u){
        if(u==par[u]) return u;
        return par[u] = faind(par[u]);
    }
};
 */

