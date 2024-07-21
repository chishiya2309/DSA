#include <bits/stdc++.h>
#define ll long long 

using namespace std;

int n;
ll a[21];
set<ll> sums;

void taoSum(int index, ll currentSum) {
    if (index > n) {
        if (currentSum > 0) {
            sums.insert(currentSum);
        }
        return;
    }
    
    taoSum(index + 1, currentSum);
    
    taoSum(index + 1, currentSum + a[index]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    taoSum(1, 0);
    
    for(ll sum : sums) {
        cout << sum << " ";
    }
    
    return 0;
}