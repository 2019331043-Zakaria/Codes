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
const int N = 5e5 + 6;

int goal[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 0};
int a[3][3];
int dx[] = {0 , 0 , -1, 1};
int dy[] = {1 , -1 , 0, 0};
struct node
{
    int mat[3][3] {};
    int gscore , fscore;
    int px, py;

    node(int a[3][3])
    {
        for (int i = 0 ; i < 3 ; i++)
        {
            for (int j = 0 ; j < 3 ; j++)
            {
                mat[i][j] = a[i][j];
                if (a[i][j] == 0)
                    px = i, py = j;
            }
        }
    }
};

class cpm {
public:

    bool operator()(node a, node b)
    {
        if (a.gscore > b.fscore )
            return true;
        else
            return false;
    }

};

int gs(node p)
{
    int cnt = 0;
    for (int i = 0 ; i < 3 ; i++)
    {
        for (int j = 0 ; j < 3 ; j++)
        {
            cnt += p.mat[i][j] != goal[i][j];
        }
    }
    return cnt;
}

void print(node p)
{
    for (int i = 0 ; i < 3 ; i++)
    {
        for (int j = 0 ; j < 3 ; j++)
            cout << p.mat[i][j] << " ";
        cout << endl;
    }

    cout << "--------\n";
}

void astar()
{
    node cur(a);
    cur.fscore = 0;
    cur.gscore = gs(cur) + cur.fscore;
    priority_queue<node, vector<node> , cpm > pq;
    pq.push(cur);

    bool found = 0;

    while (pq.size() && found == 0)
    {
        node temp = pq.top();
        pq.pop();

        print(temp);

        if (gs(temp) == 0)
        {
            found = 1;
            break;
        }

        int px = temp.px;
        int py = temp.py;

        for (int i = 0 ; i < 4 ; i++)
        {
            int tempx = px + dx[i];
            int tempy = py + dy[i];

            if (tempx < 3 && tempx >= 0 && tempy < 3 && tempy >= 0)
            {
                node pans = temp;
                swap(pans.mat[px][py], pans.mat[tempx][tempy]);
                pans.px = tempx;
                pans.py = tempy;
                pans.fscore = temp.fscore + 1;
                pans.gscore = gs(pans) + pans.fscore;
                pq.push(pans);
            }
        }
    }
}

void Solve()
{
    for (int i = 0 ; i < 3 ; i++)
    {
        for (int j = 0 ; j < 3 ; j++)
            cin >> a[i][j];
    }



    astar();
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);


    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    int tt = 1, testcae = 1;

    //    cin>>tt;

    while (tt--)
    {

        //cout<<"Case "<<testcae++<<": ";

        Solve();
    }

    return 0;

}