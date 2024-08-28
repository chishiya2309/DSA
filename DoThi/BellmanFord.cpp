/*
Ý tưởng thuật toán:
Ban đầu ta sử dụng một mảng d[] để lưu khoảng 
cách từ đỉnh nguồn s tới mọi đỉnh còn lại trên đồ thị,
d[s] = 0 và d[u] = INF (vô cùng lớn) với mọi đỉnh u còn lại trên đồ thị

Thuật toán lặp n - 1 bước, mỗi bước sẽ xét tất cả các
cặp cạnh (u, v) có trọng số w. Nếu d[v] > d[u] + w, thì sẽ cập nhật d[v];
*/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
struct canh
{
	int u, v, w;
};

int n, m, s;
vector<ii> ke[1005];
bool visited[1005];
vector<canh> dscanh; 

void nhap()
{
	cin >> n >> m >> s;
	for(int i = 0; i < m; i++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		ke[x].push_back({y, w});
		ke[y].push_back({x, w});
		dscanh.push_back({x, y, w});
		dscanh.push_back({y, x, w});
	}
}

void Bellman(int s)
{
	vector<int> d(n + 1, 1e9);
	d[s] = 0;
	for(int i = 1; i <= n - 1; i++)
	{
		for(canh e : dscanh)
		{
			int u = e.u, v = e.v, w = e.w;
			if(d[u] < 1e9)
			{
				d[v] = min(d[v], d[u] + w);
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
	Bellman(s);
    return 0;
}