#include<bits/stdc++.h>
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define test int t; cin>>t; while(t--)
#define sz 20000010
typedef long long ll;
using namespace std;

int siv[sz], twin_prime[sz], cnt;
void seive()
{
    int  i, j, limit = sqrt(sz+1);

    for (i=3; i<=limit; i+=2)
        if(!siv[i])
            for (j = i*i; j<=sz; j+=i+i)
                siv[j] = 1;

}

int main()
{
    fast
    seive();
    for (int i=3; i<=sz; i+=2)
        if(!siv[i]&&!siv[i+2])
        {
               twin_prime[cnt++]=i;
        }
   int n;
    while(cin>>n){
        cout<<"("<<twin_prime[n-1]<<", "<<twin_prime[n-1]+2<<")"<<endl;
     }
    return 0;
}
