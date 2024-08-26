#include <bits/stdc++.h>
using namespace std;

using ll = long long;

typedef pair<int, int> ii;

struct canh{
	int u, v, w;
};

int n, m, s;
vector<ii> ke[200005];
int visited[200005];
vector<canh> dscanh;

void nhap(){
	cin >> n >> m >> s;
	for(int i = 0; i < m; i++){
		int x, y, w; cin >> x >> y >> w;
		ke[x].push_back({y, w});
		ke[y].push_back({x, w});
		dscanh.push_back({x, y, w});
		dscanh.push_back({y, x, w});
	}
}

void Bellman(int s){
	vector<int> d(n + 1, 1e9);
	d[s] = 0;
	for(int i = 1; i <= n - 1; i++){
		for(canh e : dscanh){
			int u = e.u, v = e.v, w = e.w;
			if(d[u] < 1e9){
				d[v] = min(d[v], d[u] + w);
			}
		}
	}
	for(int i = 1; i <= n; i++){
		cout << d[i] << " ";
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	nhap();
	Bellman(s);
}