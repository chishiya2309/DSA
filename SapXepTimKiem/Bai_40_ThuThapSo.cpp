#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int a[n], pos[n + 1];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        pos[a[i]] = i;
    }
    int ans = 1, last = 0;
    for(int i = 1; i <= n; i++)
    {
        if(pos[i] < last)
        {
            ans++;
        }
        last = pos[i];
    }
    cout << ans;
    return 0;
}