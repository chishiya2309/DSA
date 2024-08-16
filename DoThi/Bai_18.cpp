#include <bits/stdc++.h>

using namespace std;

vector<int> ke[1005];
bool visited[1005];
int mark[1005];

void dfs(int u, int com)
{
    visited[u] = true;
    mark[u] = com;
    for(int v : ke[u])
    {
        if(!visited[v])
        {
            dfs(v, com);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }

    int com = 0;
    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            com++;
            dfs(i, com);
        }
    }

    int q;
    cin >> q;
    while(q--)
    {
        int s, t;
        cin >> s >> t;
        if(mark[s] == mark[t])
        {
            cout << 1 << '\n';
        }else {
            cout << -1 << '\n';
        }
    }

    return 0;
}