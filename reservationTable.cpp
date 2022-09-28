#include <bits/stdc++.h>
using namespace std;

int n, m;
int resv[10][1000] = {0};
map<int, set<int>> rp;
int x;
set<int> fb;

void sol(int n, int m)
{
    int k = 1;
    for (auto ii : rp)
    {
        for (auto jj : rp[k])
        {
            for (auto kk : rp[k])
            {
                if (kk - jj > 0)
                    fb.insert(kk - jj);
            }
        }
        // cout<<ii.first<<endl;
        k++;
    }

    set<int> pr;
    for (int i = 1; i <= m; i++)
    {
        pr.insert(i);
    }
    // pr.insert(x+m);

    cout << "Forbidden latency: ";
    for (auto ii : fb)
    {
        if (ii > 0)
            cout << ii << ' ';
        pr.erase(ii);
    }
    cout << endl;

    cout << "Permissible latency: ";
    for (auto ii : pr)
    {
        cout << ii << ' ';
    }
    cout << endl;

    int col[*pr.rbegin() + 1] = {0};
    for (auto ii : fb)
    {
        col[ii] = 1;
    }

    cout << "Collision vector: ";
    for (int i = 1; i <= *pr.rbegin(); i++)
        cout << col[i] << ' ';
    cout << endl;
}

int main()
{
    cin >> n >> m;

    int ref[10][100] = {0};
    int in = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> resv[i][j];
            ref[i][j] = resv[i][j];
            // cout<<'.'<<endl;
            if (resv[i][j] == 1)
                rp[i].insert(j);
        }
    }

    sol(n, m);

    while (cin >> x)
    {
        if (fb.find(x) != fb.end())
        {
            cout << "Not permissible" << endl;
            continue;
        }

        int nresv[10][1000] = {0};
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                nresv[i][j + x] = ref[i][j];
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m + x; j++)
            {
                resv[i][j] = resv[i][j] || nresv[i][j];
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = x + 1; j <= x + m; j++)
            {
                if (resv[i][j] == 1)
                    rp[i].insert(j);
            }
        }

        sol(n, x + m);
    }

    // for(auto ii: rp[1])
    // {
    //     cout<<ii<<' ';
    // }
    // cout<<endl;
}