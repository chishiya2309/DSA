/*
Lớp cấu trúc dữ liệu và giải thuật của 28Tech có N bạn tham gia với chiều cao khác nhau đôi một, ban đầu N bạn này được xếp vào 1 hàng ngang với thứ tự ngẫu nhiên.

Tuy nhiên thì 28Tech muốn rằng các bạn này cần phải xếp thành 1 hàng theo chiều cao tăng dần, để đạt được điều này thì cần phải hoán đổi vị trí 1 số bạn trong hàng.

Nhiệm vụ của bạn là hãy giúp 28Tech đếm xem cần tối thiểu bao nhiêu hoán đổi vị trí các bạn học viên để hàng người tăng dần về chiều cao.

Đầu vào
Dòng 1 là N : số lượng học viên lớp CTDL & GT

Dòng 2 gồm N số khác nhau tương ứng với chiều cao của các bạn trong lớp

Giới hạn
1<=N<=2.10^5

Chiều cao là số nguyên dương 32bit

Đầu ra
In ra số hoán đổi tối thiểu để sắp tăng dần chiều cao của các bạn học viên

Ví dụ :
Input 01
5
1 5 4 3 2
Output 01
2
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    vector<int> pos(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
        pos[a[i]] = i;
    }

    sort(b.begin(), b.end());
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i] != b[i])
        {
            cnt++;
            int old_value = a[i];
            int j = pos[b[i]];
            swap(a[i], a[j]);
            pos[old_value] = j;
            pos[a[i]] = i;
        }
    }
    cout << cnt;
    return 0;
}