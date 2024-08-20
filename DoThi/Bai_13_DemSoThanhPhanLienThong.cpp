/*
Cho đồ thị vô hướng G = (V, E) được biểu diễn dưới dạng danh sách cạnh.

Hãy đếm số thành phần liên thông của đồ thị.

Gợi ý : Số thành phần liên thông của đồ thị tương ứng với số lần gọi DFS (BFS) để đi thăm hết mọi đỉnh của đồ thị

Copy
int dem = 0;
for(int i = 1; i <= n; i++){
    if(!visited[i]){
        DFS(i);
        ++dem;
    }
}

Đầu vào
Dòng đầu tiên là 2 số n và m, tương ứng với số lượng đỉnh, cạnh của đồ thị.

Các đỉnh của đồ thị được đánh số từ 1 tới n. m dòng tiếp theo mỗi dòng chứa đỉnh u, v (u != v) tương ứng với một cạnh của đồ thị.

Giới hạn
1<=n<=1000

1<=m<=n*(n-1)/2

Đầu ra
In ra số thành phần liên thông của đồ thị

Ví dụ :
Input 01
Copy
5 4
4 1
2 1
3 2
4 3
Output 01
Copy
2
*/

#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> ke[1003];
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
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }

    int soThanhPhanLienThong = 0;

    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            dfs(i);
            soThanhPhanLienThong++;
        }
    }

    cout << soThanhPhanLienThong;

    return 0;
}