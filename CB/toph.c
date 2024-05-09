#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct point {
      int x;
      int y;
};

int main()
{
      ios::sync_with_stdio(false);
      cin.tie(0);

      int n;
      cin>>n;
      struct point a[n];
      cout<<n<<endl;
      for(int i=0 ; i<n ; i++)
      {
            //scanf("%d %d", &a[i].x, &a[i].y);
            cin>>a[i].x>>a[i].y;
      }
      for(int i= 0 ; i<n ; i++)
      {
            cout<<a[i].x<<" "<<a[i].y<<endl;
      }






return 0;

}




}
