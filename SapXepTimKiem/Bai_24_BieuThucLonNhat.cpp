/*
Một dãy gồm n số nguyên không âm a1, a2,..., an được viết thành một hàng ngang, giữa hai số liên tiếp có một khoảng trắng, như vậy có tất cả (n-1) khoảng trắng. Người ta muốn đặt k dấu cộng và (n-1-k) dấu trừ vào (n-1) khoảng trắng đó để nhận được một biểu thức có giá trị lớn nhất.

Ví dụ, với dãy gồm 5 số nguyên 28, 9, 5, 1, 69 và k = 2 thì cách đặt 28+9-5-1+69 là biểu thức có giá trị lớn nhất. Yêu cầu: Cho dãy gồm n số nguyên không âm a1, a2,..., an và số nguyên dương k, hãy tìm cách đặt k dấu cộng và (n-1-k) dấu trừ vào (n-1) khoảng trắng để nhận được một biểu thức có giá trị lớn nhất.

Gợi ý : Đưa dấu + vào số lớn, dấu - vào số nhỏ nhưng ko được sử dụng số đầu tiên của dãy số để đặt dấu + hoặc -.

Đầu vào
Dòng đầu chứa hai số nguyên dương n, k

Dòng thứ hai chứa n số nguyên không âm a1, a2,..., an

Giới hạn
1<= k < n ≤ 10^5

0 <= a[i] ≤ 10^6

Đầu ra
In ra giá trị lớn nhất của biểu thức

Ví dụ :
Input 01
5 2
10 2 1 8 9
Output 01
24
Giải thích : 10 - 2 - 1 + 8 + 9 = 24
*/

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long res = a[0];

    vector<int> b(a.begin() + 1, a.end());

    sort(b.begin(), b.end(), greater<int>());

    for (int i = 0; i < k; i++) {
        res += b[i];
    }

    for (int i = k; i < b.size(); i++) {
        res -= b[i];
    }

    cout << res;
    return 0;
}
