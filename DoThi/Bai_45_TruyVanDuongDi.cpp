#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;  // Giá trị vô cùng để đại diện cho khoảng cách không tồn tại

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    
    // Khởi tạo ma trận khoảng cách với INF
    vector<vector<int>> dist(N + 1, vector<int>(N + 1, INF));
    
    // Đọc cạnh và cập nhật ma trận khoảng cách
    for (int i = 1; i <= N; ++i) {
        dist[i][i] = 0;  // Khoảng cách từ một đỉnh đến chính nó là 0
    }
    
    for (int i = 0; i < M; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        dist[u][v] = min(dist[u][v], c);  // Cập nhật độ dài cạnh nếu cần thiết
        dist[v][u] = min(dist[v][u], c);  // Vì đồ thị vô hướng
    }
    
    // Thuật toán Floyd-Warshall
    for (int k = 1; k <= N; ++k) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    
    int Q;
    cin >> Q;
    while (Q--) {
        int X, Y;
        cin >> X >> Y;
        if (dist[X][Y] == INF) {
            cout << -1 << '\n';  // Nếu không có đường đi
        } else {
            cout << dist[X][Y] << '\n';
        }
    }
    
    return 0;
}
