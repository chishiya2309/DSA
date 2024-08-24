#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> ke[1003];
vector<int> topo;
bool visited[1003];

void dfs(int u)
{
    visited[u] = 1;
    for(int j : ke[u])
    {
        if(!visited[j])
        {
            dfs(j);
        }
    }
    topo.push_back(u);
}

signed main()
{
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        ke[x].push_back(y);
    }

    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            dfs(i);
        }
    }

    reverse(topo.begin(), topo.end());
    for(int num : topo)
    {
        cout << num << " ";
    }
}