/*
Cơ chế hoạt động: Đỉnh nào không đi được nửa thì đẩy vào vector rồi lật ngược, cơ chế giống ngăn xếp, xếp chồng lên nhau rồi lấy ra từ trên đến hết
*/

#include<bits/stdc++.h>
using namespace std;

int n, m;
set<int> ke[1003];
vector<int> topo;
bool visited[1003];

void sapXepTopo(int u)
{
    visited[u] = 1;
    for(int j : ke[u])
    {
        if(!visited[j])
        {
            sapXepTopo(j);
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
        ke[x].insert(y);
    }

    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            sapXepTopo(i);
        }
    }

    reverse(topo.begin(), topo.end());
    for(int num : topo)
    {
        cout << num << " ";
    }
}