#include <bits/stdc++.h>

using namespace std;

int n, m;
int parent[100003];
int sz[100003];
int ans = INT_MIN;

void init()
{
    for(int i = 1; i <= n; i++)
    {
        parent[i] = i;
        sz[i] = 1;
    }
}

int Find(int u)
{
    if(u == parent[u])
    {
        return u;
    }

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
            ans = max(ans, sz[y]);
		}
		else{
			parent[y] = x;
			sz[x] += sz[y];
            ans = max(ans, sz[x]);
		}
		return true;
	}
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    init();
    int stplt = n;

    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        if(Union(x, y))
        {
            --stplt;
            cout << stplt << " " << ans << endl;
        }
    }

    return 0;
}