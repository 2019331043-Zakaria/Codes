#include <stdio.h>
int main(){
  int list[100001]={0};
  long long answer=0;
  int a,n;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",&a);
    answer+=a;
    list[a]++;
  }
//  int q,b,c;
//  scanf("%d",&q);
//  for(int i=0;i<q;i++){
//    scanf("%d %d",&b,&c);
//
//    answer+=(c-b)*(list[b]);
//
//    printf("%lld\n",answer);
//
//    list[c]+=list[b];
//
//    list[b]=0;
//  }
printf("%d",list[5]);
  return 0;
}
