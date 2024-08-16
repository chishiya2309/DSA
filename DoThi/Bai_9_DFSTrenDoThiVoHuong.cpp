#include <bits/stdc++.h>

using namespace std;

vector<int> ke[1005];
bool visited[1005];

void dfs(int u)
{
    cout << u << " ";
    visited[u] = true;
    for(int v : ke[u])
    {
        if(!visited[v])
        {
            dfs(v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, s;
    cin >> n >> m >> s;
    //So dinh, canh, va dinh bat dau
    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }

    for(int i = 1; i <= n; i++)
    {
        sort(ke[i].begin(), ke[i].end());
    }

    dfs(s);

    return 0;
}