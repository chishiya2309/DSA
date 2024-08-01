/*
Cho mảng A[] gồm N phần tử và số nguyên K, bạn hãy xác định xem trong mảng có tồn tại 2 phần tử A[i], A[j] với i khác j sao cho A[i] = A[j] và abs(i - j) <= K hay không. Nếu có in ra YES, ngược lại in ra NO. Bài này các bạn có thể sử dụng sort hoặc sliding window

Đầu vào
• Dòng 1 gồm N và K

• Dòng 2 gồm N số trong mảng A[]

Giới hạn
• 1<=K<=N<=10^6

• 1<=A[i]<=10^6

Đầu ra
In ra đáp án của bài toán

Ví dụ :
Input 01
5 5
9 10 7 8 4
Output 01
NO
*/

#include <bits/stdc++.h>

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
    bool final = false;
    set<int> se;
    for(int i = 0; i < n; i++)
    {
        if(se.find(a[i]) != se.end())
        {
            final = true;
            break;
        }

        se.insert(a[i]);

        if(i >= k)
        {
            se.erase(a[i - k]);
        }
    }
    if(final)
    {
        cout << "YES";
    }else {
        cout << "NO";
    }
    return 0;
}