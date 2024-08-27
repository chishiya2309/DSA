/*
Ý tưởng thuật toán:
Thuật toán duy trì tập S chứa những đỉnh đã xác
định được đường đi ngắn nhất từ đỉnh nguồn,
thuật toán lần lượt lựa chọn đỉnh u thuộc tập V - S
có đường đi tới đỉnh nguồn là ngắn nhất, sau đó
đưa đỉnh u vào tập S và cập nhật (relax) đường đi
ngắn nhất cho các đỉnh kề với đỉnh u.
Để có thể lựa chọn nhanh đỉnh u có đường đi
ngắn nhất từ đỉnh nguồn ta sử dụng hàng đợi ưu tiên trong C++
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

typedef pair<int, int> ii;

int n, m, s;
vector<ii> ke[1005];
bool visited[1005];

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
	vector<int> d(n + 1, 1e9);
	d[s] = 0;
	priority_queue<ii, vector<ii>, greater<ii>> Q;
	Q.push({0, s});
	while(!Q.empty())
	{
		ii p = Q.top();
		Q.pop();
		if(d[p.second] < p.first) continue;
		int u = p.second;
		for(ii it : ke[u])
		{
			int w = it.first, v = it.second;
			if(d[v] > d[u] + w)
			{
				d[v] = d[u] + w;
				Q.push({d[v], v});
			}
		}
	}

	for(int i = 1; i <= n; i++)
	{
		cout << d[i] << " ";
	}
}

int main()
{
	nhap();
	Dijkstra(s);
	return 0;
}