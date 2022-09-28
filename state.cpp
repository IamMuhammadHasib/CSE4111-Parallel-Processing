#include <bits/stdc++.h>
using namespace std;

int n, m;
int resv[10][1000] = {0};
map<int, set<int>> rp;
int x;
set<int> fb;
int col[10] = {0};
set<int> pr;

void sol(int n, int m)
{
    int k = 1, j = 2;
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

    for (int i = 1; i <= max(*fb.rbegin(), m); i++)
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

    for (auto ii : fb)
    {
        col[ii] = 1;
    }

    cout << "Collision vector: ";
    for (int i = 1; i <= *fb.rbegin(); i++)
        cout << col[i] << ' ';
    cout << endl;
}

string toBinary(int num)
{
    string bin;
    while (num != 0)
    {
        bin = (num % 2 == 0 ? "0" : "1") + bin;
        num /= 2;
    }
    return bin;
}

void bfs(int st)
{
    vector<int> pl;
    // for(auto i:pr) pl.push_back(i);

    queue<int> q;
    q.push(st);
    bool vis[512] = {0};
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if (vis[u] == 0)
        {
            vis[u] = 1;
            string bs = toBinary(u);
            for (int i = bs.size() - 1; i >= 0; i--)
            {
                if (bs[i] == '0')
                    pl.push_back(bs.size() - i);
            }
            pl.push_back(m);

            int t;
            for (auto i : pl)
            {
                t = u >> i;
                if (vis[st | t] == 0)
                    q.push(u | t);
                string tt = toBinary(st | t);
                cout << i << ' ' << tt << endl;
            }
            pl.clear();
        }
    }
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

    int x = *fb.rbegin();
    // cout << x << endl;
    int icv[x];
    int ic = 0;
    for (int i = 1; i <= x; i++)
    {
        icv[x - i] = col[i];
        ic += (col[i] * (pow(2, i - 1)));
    }

    cout << ic << endl;
    for (int i : icv)
        cout << i << ' ';
    cout << endl;

    // for (auto i : pr)
    // {
    //     cout << i << ' ';
    // }

    bfs(ic);
}