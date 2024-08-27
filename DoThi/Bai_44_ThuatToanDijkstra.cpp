/*
Cho đồ thị vô hướng có trọng số không âm G = (V, E) được biểu diễn dưới dạng danh sách cạnh trọng số.

Hãy viết chương trình tìm đường đi ngắn nhất từ đỉnh s đến tất cả các đỉnh còn lại trên đồ thị. Dữ liệu đảm bảo có đường đi từ đỉnh s tới mọi đỉnh khác trên đồ thị.

Đầu vào
Dòng đầu tiên là n m và s tương ứng với số lượng đỉnh, cạnh và đỉnh bắt đầu.

m dòng tiếp theo là các dòng mô tả cạnh của đồ thị.

Giới hạn
1<=n<=1000

1<=m<=n*(n-1)/2

Trọng số các cạnh là số nguyên không âm không vượt quá 100

Đầu ra
In ra đường đi ngắn nhất từ đỉnh u tới mọi đỉnh còn lại

Ví dụ :
Input 01
Copy
10 44 5
7 5 60
9 8 31
9 1 83
4 3 25
6 2 1
4 1 52
6 3 76
7 6 95
9 7 84
8 2 91
10 7 8
6 4 32
10 2 76
3 1 62
10 6 88
8 3 12
5 3 15
5 4 40
9 2 20
3 2 5
5 1 36
9 4 98
8 6 65
8 5 95
10 3 55
9 6 95
10 1 5
4 2 70
7 1 80
10 4 35
7 2 99
10 9 24
6 5 94
2 1 77
8 1 12
8 4 76
9 3 27
5 2 5
9 5 12
10 5 1
8 7 59
6 1 1
10 8 92
7 3 54
Output 01
Copy
6 5 10 35 0 6 9 18 12 1
*/

#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;

int n, m, s;
vector<ii> ke[1003];

void nhap()
{
    cin >> n >> m >> s;
    for(int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        ke[x].push_back({w, y});
        ke[y].push_back({w, x});
    }
}

void Dijkstra(int s)
{
    priority_queue<ii, vector<ii>, greater<ii>> q;
    vector<int> d(n + 1, 1e9);
    d[s] = 0;
    q.push({0, s});
    while(!q.empty())
    {
        ii p = q.top();
        q.pop();
        if(d[p.second] < p.first) continue;
        int u = p.second;
        for(ii it : ke[u])
        {
            int w = it.first, v = it.second;
            if(d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                q.push({d[v], v});
            }
        }
    }

    for(int i = 1; i <= n; i++)
    {
        cout << d[i] << " ";
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    nhap();
    Dijkstra(s);

    return 0;
}