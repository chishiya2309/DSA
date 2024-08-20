/*
Cho đồ thị có hướng G = (V, E) được biểu diễn dưới dạng danh sách cạnh.

Hãy xác định xem đồ thị có tồn tại chu trình hay không? Bài này các bạn cài đặt bằng 3 phương pháp : DFS, BFS và DSU.

Đầu vào
Dòng đầu tiên là 2 số n, m, tương ứng với số lượng đỉnh, cạnh của đồ thị.

Các đỉnh của đồ thị được đánh số từ 1 tới n. m dòng tiếp theo mỗi dòng chứa đỉnh u, v (u != v) tương ứng với một cạnh của đồ thị.

Giới hạn
1<=n<=1000

1<=m<=n*(n-1)/2

Đầu ra
In ra 1 nếu đồ thị tồn tại chu trình, ngược lại in ra 0.

Ví dụ :
Input 01
Copy
4 4
1 2
2 3
3 1
1 4
Output 01
Copy
1
*/

#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> ke[1003];
int color[1003];
int chutrinh = 0;

void dfs(int u)
{
    color[u] = 1;
    for(int j : ke[u])
    {
        if(color[j] == 0)
        {
            dfs(j);
        }else if(color[j] == 1)
        {
            chutrinh = 1;
        }
    }
    color[u] = 2;
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
    }

    for(int i = 1; i <= n; i++)
    {
        if(color[i] == 0)
        {
            dfs(i);
            if(chutrinh)
            {
                cout << 1;
                return 0;
            }
        }
    }

    cout << 0;

    return 0;
}