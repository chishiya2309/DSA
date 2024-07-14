/*
Lớp cấu trúc dữ liệu và giải thuật của 28Tech có N bạn tham gia với chiều cao khác nhau đôi một, ban đầu N bạn này được xếp vào 1 hàng ngang với thứ tự ngẫu nhiên.

Tuy nhiên thì 28Tech muốn rằng các bạn này cần phải xếp thành 1 hàng theo chiều cao tăng dần, để đạt được điều này thì cần phải hoán đổi vị trí 1 số bạn trong hàng.

Nhiệm vụ của bạn là hãy giúp 28Tech đếm xem cần tối thiểu bao nhiêu hoán đổi vị trí các bạn học viên để hàng người tăng dần về chiều cao.
*/

#include <bits/stdc++.h>
using namespace std;

int minSwaps(vector<int>& a, int n) {
    vector<pair<int, int>> heightPos(n);
    for (int i = 0; i < n; ++i) {
        heightPos[i] = {a[i], i};
    }

    sort(heightPos.begin(), heightPos.end());

    vector<bool> visited(n, false);
    int swapCount = 0;

    for (int i = 0; i < n; ++i) {
        if (visited[i] || heightPos[i].second == i) {
            continue;
        }
        
        int cycleLength = 0;
        int j = i;
        while (!visited[j]) {
            visited[j] = true;
            j = heightPos[j].second;
            cycleLength++;
        }

        if (cycleLength > 0) {
            swapCount += (cycleLength - 1);
        }
    }
    return swapCount;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cout << minSwaps(a, n);
    return 0;
}
