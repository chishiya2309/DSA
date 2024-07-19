#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll cnt = 0, sum = 0;
    map<ll, int> sum_count;
    sum_count[0] = 1;
    for(int i = 0; i < n; i++) {
        sum += a[i];
        cnt += sum_count[sum - x];
        sum_count[sum]++;
    }
    cout << cnt;
    return 0;
}