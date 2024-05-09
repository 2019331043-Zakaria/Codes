#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll inf = INT_MAX;
ll n, m, p, q, k, w;
ll node[504][504];
ll dis[503][504];
ll vis[504][504];
void warshall(ll n)
{

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {

                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
}



int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dis[i][j] = inf;
        }
        dis[i][i] = 0;

    }

    while (m--)
    {
        cin >> p >> q >> w;

        dis[p][q] = min(dis[p][q], w);
        dis[q][p] = min(dis[q][p], w);

    }



    warshall(n);

    while (k--)
    {
        cin >> p >> q;
        if (p == q)
            cout << 0 << endl;
        else if (dis[p][q] >= inf || dis[p][q] < 0)
            cout << -1 << endl;
        else
            cout << dis[p][q] << endl;
    }




    return 0;
}
