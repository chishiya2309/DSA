/*
Ta gọi một cặp số (x, y) là tương tự nhau nếu chúng có cùng tính chất chẵn lẻ hoặc có abs(x - y) = 1. Bạn được cung cấp một mảng A[] có N phần tử, hãy kiểm tra xem có thể chia N phần tử này thành các cặp, sao cho mỗi cặp số đều tương tự

Đầu vào
Dòng đầu tiên chứa số nguyên dương N là số chẵn.

Dòng 2 chứa N số nguyên của mảng A[]

Giới hạn
1<=N<=10^6

1<=A[i]<=10^6

Đầu ra
In ra YES nếu có thể chia thành các cặp tương tự, ngược lại in ra NO

Ví dụ :
Input 01
6
78 17 17 42 11 43
Output 01
YES
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

    int cntChan = 0, cntLe = 0;
    for(int num : a)
    {
        if(num % 2 == 0)
        {
            cntChan++;
        }else
        {
            cntLe++;
        }
    }

    if(cntChan % 2 == 0 && cntLe % 2 == 0)
    {
        cout << "YES";
        return 0;
    }

    sort(a.begin(), a.end());
    for(int i = 1; i < n; i++)
    {
        if(a[i] - a[i - 1] == 1)
        {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
    
    return 0;
}