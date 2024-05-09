/*
* @Author: Zakaria
* @Date:   2023-01-21 21:13:26
* @Last Modified time: 2023-01-24 15:36:07
*/
#include <bits/stdc++.h>
#define  pb          push_back
#define  f           first
#define  s           second
#define  pi          acos(-1.0)
#define  LCM(a,b)    a*b/__gcd(a,b)
#define  GCD(a,b)    __gcd(a,b)
#define  sof         sizeof
#define  endl        '\n'
#define  eps         1e-6
typedef long long ll;
using namespace std;

const int mod = 1e9 + 7;
const int N = 2e5 + 6;

int visited[N];
vector<int>divisor[N];
int cur;
int exist[N];
int n, m;
void add(int val)
{
    for (auto i : divisor[val])
    {
        if (i <= m)
        {
            if (exist[i] == 0)
            {
                cur++;

            }

            exist[i]++;
        }
    }
}

void remove(int val)
{
    for (auto i : divisor[val])
    {
        if (i <= m)
        {
            if (exist[i])
            {
                exist[i]--;
                if (exist[i] == 0)
                    cur--;
            }
        }
    }
}
void Solve()
{


    cin >> n >> m;

    int a[n];
    int mx = 0;
    for (int i = 0 ; i < n ; i++)
        cin >> a[i];


    sort(a, a + n);

    for (int i = 0 ; i <= m ; i++)
        exist[i] = 0;
    cur = 0;

    int left = 0, right = 0;

    int ans = 1e9;

    while (left < n)
    {


        while (cur != m && right < n)
        {
            add(a[right]);

            right++;
        }


        if (cur == m)
        {
            ans = min(ans, a[right - 1] - a[left]);
        }

        remove(a[left]);
        left++;


    }

    if (ans == 1e9)
        cout << -1 << endl;
    else
        cout << ans << endl;





}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);


    for (int i = 1 ; i < N ; i++)
    {
        for (int j = i ; j < N ; j += i)
            divisor[j].push_back(i);
    }

    int tt = 1;

    cin >> tt;

    while (tt--)
    {

        Solve();
    }

    return 0;

}