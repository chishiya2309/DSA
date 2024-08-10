/*
Cho mảng A[] gồm N phần tử và số X. Nhiệm vụ của bạn là tìm cặp phần tử A[i] - A[j] = X. Nếu tồn tại A[i] - A[j] = X đưa ra 1, ngược lại đưa ra -1.

Đầu vào
Dòng thứ nhất là cặp số N, X

Dòng tiếp theo là N số A[i] là các phần tử của mảng A[].

Giới hạn
1≤ N ≤10^5

1≤ X, A[i] ≤10^5.

Đầu ra
In ra 1 nếu tìm thấy một cặp số có hiệu bằng X, ngược lại in ra -1.

Ví dụ :
Input 01
Copy
5 3
1 1 2 3 5
Output 01
Copy
1
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
    for(int &x : a)
    {
        cin >> x;
        se.insert(x);
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