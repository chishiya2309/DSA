#include <bits/stdc++.h>
using namespace std;

using ll = long long;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int n, m;
int a[503][503];
int d[503][503];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void nhap(){
	cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            d[i][j] = 1e9;
        }
    }
}

void Dijkstra(){
	priority_queue<iii, vector<iii>, greater<iii>> Q;
	Q.push({a[1][1], {1, 1}});
    d[1][1] = a[1][1];

	while(!Q.empty()){
		iii p = Q.top(); Q.pop();
		
		int cost = p.first;
        int x = p.second.first;
        int y = p.second.second;

        if(cost > d[x][y]) continue;

        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m) {
                int new_cost = cost + a[nx][ny];
                if (new_cost < d[nx][ny]) {
                    d[nx][ny] = new_cost;
                    Q.push({new_cost, {nx, ny}});
                }
            }
        }
    }

    cout << d[n][m];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	nhap();
	Dijkstra();
    return 0;
}