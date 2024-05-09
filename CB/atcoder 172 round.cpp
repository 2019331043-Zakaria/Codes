#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>
#define MAX 10000002
typedef long long ll;
int main(){
    ll N;
    scanf("%lld",&N);
    ll table[MAX]={0};
    for(ll i=1;i<=N;i++){
        for(ll j=1;i*j<=N;j++){
            table[i*j]++;
        }
    }
    ll ans=0;
    for(ll i=1;i<=N;i++)
        ans += table[i]*i;
    printf("%lld",ans);
}
