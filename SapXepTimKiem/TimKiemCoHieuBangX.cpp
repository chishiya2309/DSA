/*
Cho mảng A[] gồm N phần tử và số X. Nhiệm vụ của bạn là tìm cặp phần tử A[i] - A[j] = X. Nếu tồn tại A[i] - A[j] = X đưa ra 1, ngược lại đưa ra -1.
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    set<int> se;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        se.insert(a[i]);
    }
    for(int i = 0; i < n; i++)
    {
        if(se.find(a[i] + x) != se.end() || se.find(a[i] - x) != se.end())
        {
            cout << 1;
            return 0;
        } 
    }
    cout << -1;
    return 0;
}
