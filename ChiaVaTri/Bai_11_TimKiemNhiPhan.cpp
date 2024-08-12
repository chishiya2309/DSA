/*
Cho dãy A[] gồm N phần tử đã được sắp xếp và số nguyên dương K. Hãy kiểm tra xem K có xuất hiện trong mảng hay không, nếu có in ra YES, ngược lại in ra NO

Đầu vào
Dòng 1 chứa 2 số N và K

Dòng 2 chứa N số nguyên của mảng A[]

Giới hạn
1<=N<=10^5

1<=A[i], K<=10^6

Đầu ra
In ra đáp án của bài toán

Ví dụ :
Input 01
Copy
6 4
4 8 9 16 19 20
Output 01
Copy
YES
*/

#include <bits/stdc++.h>

using namespace std;

bool find(int a[], int l, int r, int k)
{
    if(l > r)
    {
        return false;
    }

    int mid = (l + r) / 2;
    if(a[mid] == k)
    {
        return true;
    }else if(a[mid] > k)
    {
        return find(a, l, mid - 1, k);
    }else
    {
        return find(a, mid + 1, r, k);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;

    int a[n];
    for(int &x : a)
    {
        cin >> x;
    }

    if(find(a, 0, n - 1, k))
    {
        cout << "YES";
    }else 
    {
        cout << "NO";
    }
    return 0;
}