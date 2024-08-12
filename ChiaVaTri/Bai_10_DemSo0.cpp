/*
Cho mảng A[] gồm N phần tử chỉ bao gồm các số 0 và 1. Các số 0 được đặt trước các số 1. Hãy đếm các số 0 với thời gian log(N).

Đầu vào
Dòng 1 chứa số nguyên dương N

Dòng thứ 2 chứa N số nguyên của mảng A[]

Giới hạn
1<=N<=10^6

0<=A[i]<=1

Đầu ra
In ra đáp án của bài toán, nếu số 0 không xuất hiện in ra 0

Ví dụ :
Input 01
Copy
6
0 0 1 1 1 1
Output 01
Copy
2
*/

#include <bits/stdc++.h>

using namespace std;

int find(int a[], int l, int r)
{
    if(l > r)
    {
        return -1;
    }

    int mid = (l + r) / 2;
    if(a[mid] == 0)
    {
        int tmp = find(a, mid + 1, r);
        if(tmp != -1)
        {
            return tmp;
        }
        return mid;
    }

    return find(a, l, mid - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    int a[n];
    for(int &x : a)
    {
        cin >> x;
    }

    int last_pos = find(a, 0, n - 1);
    if(last_pos == -1)
    {
        cout << 0;
    }else {
        cout << last_pos + 1;
    }

    return 0;
}