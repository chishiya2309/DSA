#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n, m;

int parent[1005], sz[1005];

void init(){
	for(int i = 1; i <= n; i++){
		parent[i] = i;
		sz[i] = 1;
	}
}

int Find(int u){
	if(u == parent[u]) 
		return u;
	return parent[u] = Find(parent[u]);
}

bool Union(int x, int y){
	x = Find(x); // tim nguoi dai dien cho x
	y = Find(y); // tim nguoi dai dien cho y
	if(x == y)
		return false;
	else{
		if(sz[x] < sz[y]){
			parent[x] = y;
			sz[y] += sz[x];
		}
		else{
			parent[y] = x;
			sz[x] += sz[y];
		}
		return true;
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	cin >> n >> m;
	init();
	bool ok = false;
	for(int i = 0; i < m; i++){
		int x, y; cin >> x >> y;
		if(!Union(x, y)) ok = true;
	}
	if(ok) cout << 1 << endl;
	else cout << 0 << endl;
}