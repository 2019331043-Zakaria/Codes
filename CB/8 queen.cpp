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

int n = 9;

int findcost(vector<int>row)
{
  int cnt = 0;
  for (int i = 0 ; i < n ; i++)
  {
    for (int j = i + 1 ; j < n ; j++)
    {
      if (row[i] == row[j] || (abs(row[i] - row[j]) == j - i))
        cnt++;
    }
  }

  return cnt;
}

vector<int>hillclimgbing()
{
  vector<int>row;

  for (int i = 0 ; i < n ; i++)
    row.push_back(rand() % n);

  int curcost = findcost(row);
  while (curcost > 0)
  {
    int bestcost = curcost;

    for (int i = 0 ; i < n ; i++)
    {

      for (int j = 0 ; j < n ; j++)
      {
        if (j != row[i])
        {
          vector<int>temp;
          temp = row;
          temp[i] = j;

          int tempcost = findcost(temp);

          if (tempcost < bestcost)
          {
            bestcost = tempcost;
            row = temp;
          }
        }
      }
    }

    if (bestcost >= curcost)
    {

      row.clear();
      for (int i = 0 ; i < n ; i++)
        row.push_back(rand() % n);
      curcost = findcost(row);
    }
    else
    {
      curcost = bestcost;
    }
  }

  return row;
}

void Solve()
{
  vector<int>ans;
  ans = hillclimgbing();

  for (int i = 0 ; i < n ; i++)
  {
    for (int j = 0 ; j < n ; j++)
    {
      if (ans[i] == j)
        cout << "Q ";
      else
        cout << ". ";
    }
    cout << endl;
  }
}

int main()
{

  ios::sync_with_stdio(false);
  cin.tie(0);


  //freopen("input.in", "r", stdin);
  //freopen("output.out", "w", stdout);

  int tt = 1, testcae = 1;

  //  cin>>tt;

  while (tt--)
  {

    //cout<<"Case "<<testcae++<<": ";

    Solve();
  }

  return 0;

}