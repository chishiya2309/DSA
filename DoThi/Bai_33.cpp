#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> ke[100003];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }

    for(int i = 1; i <= n; i++)
    {
        if(ke[i].size() != n - 1)
        {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";

    return 0;
}