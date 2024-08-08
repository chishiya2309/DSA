/*
Cho mảng A[] gồm N phần tử đã được sắp xếp theo thứ tự tăng dần và số nguyên X, bạn hãy tìm số lớn nhất không vượt quá X nằm trong mảng A[]

Đầu vào
Dòng 1 chứa 2 số N và X

Dòng 2 chứa N số của mảng A[]

Giới hạn
1<=N<=10^5

1<=X,A[i]<=10^6

Đầu ra
In ra đáp án của bài toán nếu tìm thấy số lớn hơn X, trường hợp không tìm thấy in -1

Ví dụ :
Input 01
Copy
9 8
1 2 3 4 5 6 7 8 9
Output 01
Copy
8
*/

#include <bits/stdc++.h>

using namespace std;

int last_pos(int a[], int l, int r, int x)
{
    if(l > r) return -1;
    int mid = (l + r) / 2;
    if(a[mid] <= x)
    {
        int tmp = last_pos(a, mid + 1, r, x);
        if(tmp != -1) return tmp;
        return mid;
    }

    return last_pos(a, l, mid - 1, x);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, x;
    cin >> n >> x;

    int a[n];
    for(int &x : a)
    {
        cin >> x;
    }

    int res = last_pos(a, 0, n - 1, x);
    if(res != -1)
    {
        cout << a[res];
    }else {
        cout << -1;
    }
    return 0;
}