/*
Cơ chế hoạt động: Đỉnh nào không đi được nửa thì đẩy vào vector rồi lật ngược, cơ chế giống ngăn xếp, xếp chồng lên nhau rồi lấy ra từ trên đến hết
*/

#include<bits/stdc++.h>
using namespace std;

int n, m;
set<int> ke[1003];
bool visited[1003];
vector<int> v;

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
    v.push_back(u);
}

signed main()
{
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        ke[x].insert(y);
    }

    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            dfs(i);
        }
    }

    reverse(v.begin(), v.end());

    for(int num : v)
    {
        cout << num << " ";
    }
}
