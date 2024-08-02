/*
Cho dãy số A[] gồm có N phần tử và số nguyên dương k. Hãy tìm dãy con liên tiếp có k phần tử sao cho dãy con đó có tổng các phần tử lớn nhất.

Đầu vào
Dòng đầu tiên là số nguyên N và K.

Dòng tiếp theo gồm N số nguyên A[i]

Giới hạn
1≤ K ≤ N ≤ 10^7

1 ≤ A[i] ≤ 10^9

Đầu ra
Dòng 1 in ra tổng lớn nhất của dãy con K phần tử liền kề.

Dòng 2 in ra dãy con đó, nếu có nhiều dãy con có cùng tổng lớn nhất thì in ra dãy con xuất hiện đầu tiên.

Ví dụ :
Input 01
59 4
72 39 5 74 29 83 63 67 69 10 50 86 32 66 96 100 47 32 41 96 9 7 58 97 87 26 21 23 100 52 31 76 43 74 17 72 104 40 99 8 16 27 38 78 69 46 16 58 73 52 49 67 62 42 64 28 46 34 83
Output 01
315
72 104 40 99
*/

#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int &x : a)
    {
        cin >> x;
    }
    ll sum = 0;
    for(int i = 0; i < k; i++)
    {
        sum += a[i];
    }
    ll maxSum = sum;
    int start = 0;
    for(int i = k; i < n; i++)
    {
        sum = sum - a[i - k] + a[i];
        if(sum > maxSum)
        {
            maxSum = sum;
            start = i - k + 1;
        }
    }
    cout << maxSum << endl;
    for(int i = start; i < start + k; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}