int Fenwick[mx];
void update(int idx)
{
    while(idx<=N){
        Fenwick[idx]++;
        idx+=(idx&(-idx));
    }
}

int query(int idx)   // number of int <=idx
{
    int r=0;
    while(idx){
        r+=Fenwick[idx];
        idx-=(idx&(-idx));
    }
    return r;
}

