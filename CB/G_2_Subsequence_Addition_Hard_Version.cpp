#include<bits/stdc++.h>

using namespace std;

void solve()
{
    int len;
    cin >> len;
    int ara[len];
    long long  cumo[len];

    for(int i = 0; i < len; i++)
    {
        cin >> ara[i];
    }

    sort(ara,ara+len);

    if(ara[0]!=1)
    {
        cout<<"NO"<<endl;
        return ;
    }

    if(len == 1 && ara[0] == 1)
    {
        cout << "YES" << endl;
    }
    else if(len == 1 && ara[0] != 1)
    {
        cout << "NO" << endl;
    }
    else
    {
        

        cumo[0] = ara[0];
        int flag = 1;
        
        for(int i = 1; i < len; i++)
        {
            cumo[i] = ara[i] + cumo[i-1];
            if(ara[i] > cumo[i-1])
            {
                cout << "NO" << endl;
                flag = 0;
                break;
            }
        }
        if(flag)
        {
            cout << "YES" << endl;
        }

    }


    return;
}

int main()
{
    int len ;
    cin >> len;

    while(len--)
    {
        solve();
    }
    return 0;
}