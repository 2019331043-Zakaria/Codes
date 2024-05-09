#include <bits/stdc++.h>

using namespace std;

int main()
{
    int coins[] = { 1, 2, 3 };
    int n = 3;
    int sum = 4;


    int table[sum + 1];
    memset(table, 0, sizeof(table));

    table[0] = 1;

    for (int i = 0; i < n; i++)
        for (int j = coins[i]; j <= sum; j++)
            table[j] += table[j - coins[i]];
    

    cout<<table[sum]<<endl;

    return 0;
}
