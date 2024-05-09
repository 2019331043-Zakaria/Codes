#include <bits/stdc++.h>
using namespace std;

vector<int> use(10);
map<char, int>res;

struct node
{
    char c;
    int v;
};


int check(node* nodeArr, const int count, string s1, string s2, string s3)
{
    int val1 = 0, val2 = 0, val3 = 0, m = 1, j, i;

    int last = 0;

    for (i = s1.length() - 1; i >= 0; i--)
    {
        char ch = s1[i];
        for (j = 0; j < count; j++)
            if (nodeArr[j].c == ch)
                break;

        val1 += m * nodeArr[j].v;
        last = nodeArr[j].v + nodeArr[j].v;
        m *= 10;
    }


    m = 1;

    for (i = s2.length() - 1; i >= 0; i--)
    {
        char ch = s2[i];
        for (j = 0; j < count; j++)
            if (nodeArr[j].c == ch)
                break;

        val2 += m * nodeArr[j].v;
        last = nodeArr[j].v + nodeArr[j].v;
        m *= 10;
    }



    m = 1;

    last = 0;
    for (i = s3.length() - 1; i >= 0; i--)
    {
        char ch = s3[i];
        for (j = 0; j < count; j++)
            if (nodeArr[j].c == ch)
                break;

        val3 += m * nodeArr[j].v;
        last = nodeArr[j].v;

        m *= 10;
    }


    bool ok = 1;
    int carry = 0;
    for (int i = s1.size() - 1 ; i >= 0 ; i--)
    {
        int sum = 0;


        for (j = 0; j < count; j++)
            if (nodeArr[j].c == s1[i])
                break;

        sum += nodeArr[j].v;


        for (j = 0; j < count; j++)
            if (nodeArr[j].c == s2[i])
                break;

        sum += nodeArr[j].v;

        sum += carry;

        if (sum < 10)
            ok = 0;
        else
            carry = 1;
    }


    if (val3 == (val1 + val2) && last && ok)
    {
        return 1;
    }

    return 0;
}

bool permutation(const int count, node* nodeArr, int n, string s1, string s2, string s3)
{

    if (n == count - 1)
    {

        for (int i = 0; i < 10; i++)
        {

            if (use[i] == 0)
            {

                nodeArr[n].v = i;

                if (check(nodeArr, count, s1, s2, s3) == 1)
                {
                    cout << "Solution found: " << endl;
                    for (int j = 0; j < count; j++)
                        res[nodeArr[j].c] = nodeArr[j].v;

                    for (auto i : s1)
                        cout << res[i];
                    cout << endl;

                    for (auto i : s2)
                        cout << res[i];
                    cout << endl;

                    for (auto i : s3)
                        cout << res[i];
                    cout << endl;
                    return true;
                }
            }
        }
        return false;
    }

    for (int i = 0; i < 10; i++)
    {

        if (use[i] == 0)
        {

            nodeArr[n].v = i;

            use[i] = 1;

            if (permutation(count, nodeArr, n + 1, s1, s2, s3))
                return true;

            use[i] = 0;
        }
    }
    return false;
}

bool solveCryptographic(string s1, string s2, string s3)
{

    int count = 0;

    int l1 = s1.length();
    int l2 = s2.length();
    int l3 = s3.length();

    vector<int> freq(26);

    for (int i = 0; i < l1; i++)
        ++freq[s1[i] - 'A'];

    for (int i = 0; i < l2; i++)
        ++freq[s2[i] - 'A'];

    for (int i = 0; i < l3; i++)
        ++freq[s3[i] - 'A'];


    for (int i = 0; i < 26; i++)
        if (freq[i] > 0)
            count++;

    if (count > 10)
    {
        cout << "Invalid strings";
        return 0;
    }

    node nodeArr[count];


    for (int i = 0, j = 0; i < 26; i++)
    {
        if (freq[i] > 0)
        {
            nodeArr[j].c = char(i + 'A');
            j++;
        }
    }
    return permutation(count, nodeArr, 0, s1, s2, s3);
}

int main()
{

    string s1, s2, s3;

    cin >> s1 >> s2 >> s3;

    if (solveCryptographic(s1, s2, s3) == false)
        cout << "No solution";


    return 0;
}
