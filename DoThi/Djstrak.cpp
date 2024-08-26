#include <bits/stdc++.h>
using namespace std;

using ll = long long;

typedef pair<int, int> ii;

int n, m, s;
vector<ii> ke[200005];
int visited[200005];

void nhap(){
	cin >> n >> m >> s;
	for(int i = 0; i < m; i++){
		int x, y, w; cin >> x >> y >> w;
		ke[x].push_back({y, w});
		ke[y].push_back({x, w});
	}
}

void Dijkstra(int s){
	vector<int> d(n + 1, 1e9);
	d[s] = 0;
	priority_queue<ii, vector<ii>, greater<ii>> Q;
	Q.push({0, s});
	while(!Q.empty()){
		ii p = Q.top(); Q.pop();
		//p.first : chi phi duong di, p.second : dinh 
		if(d[p.second] < p.first) continue;
		int u = p.second;
		for(ii it : ke[u]){
			int v = it.first, w = it.second;
			if(d[v] > d[u] + w){
				d[v] = d[u] + w;
				Q.push({d[v], v});
			}
		}
	}
	for(int i = 1; i <= n; i++){
		cout << d[i] << " ";
	}
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	nhap();
	Dijkstra(s);
}