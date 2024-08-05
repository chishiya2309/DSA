/*
Cho mảng A[] gồm N số và thực hiện 2 thao tác sau :

Chọn mảng con (dãy con liên tiếp) sao cho phần tử ở giữa của mảng con cũng là phần tử ở giữa của mảng A[]

Lật ngược mảng con liên tiếp đã chọn

Ta được phép chọn mảng con và phép đảo ngược mảng con bao nhiêu lần tùy ý. Bạn hãy xác định xem có thể tạo ra mảng tăng dần từ mảng A[] đã cho và các thao tác trên hay không?

Đầu vào
Dòng 1 chứa số nguyên dương N là số lẻ.

Dòng 2 chứa N số nguyên của mảng A[]

Giới hạn
1<=N<=10^6

0<=A[i]<=10^9

Đầu ra
In ra YES nếu có thể tạo mảng tăng dần hoặc NO trong trường hợp ngược lại

Ví dụ :
Input 01
7
1 6 5 4 3 2 7
Output 01
YES
Giải thích :
Lật ngược đoạn [6, 5, 4, 3, 2] ta được mảng A[] = [1, 2, 3, 4, 5, 6, 7]
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x : a)
    {
        cin >> x;
    }
    for(int i = 0; i < n /2; i++)
    {
        if(a[i] > a[n - i - 1])
        {
            swap(a[i], a[n - i - 1]);
        }
    }
    for(int i = 1; i < n; i++)
    {
        if(a[i] <= a[i - 1])
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}