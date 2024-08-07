/*
Cho dãy số nguyên A[] gồm N phần tử, bạn hãy là tính tổng của dãy con liên tiếp có tổng lớn nhất.

Đầu vào
Dòng đầu tiên chứa số nguyên dương N

Dòng thứ 2 chứa N số nguyên của dãy A[]

Giới hạn
1<=N<=10^5

1<=abs(A[i])<=10^6

Đầu ra
In ra đáp án của bài toán

Ví dụ :
Input 01
5
-3 6 1 -3 6
Output 01
10
*/

#include <bits/stdc++.h>
#define ll long long
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

    ll maxSumHere = 0, maxSoFar = INT_MIN;
    for(int num : a)
    {
        maxSumHere += num;

        if(maxSumHere > maxSoFar)
        {
            maxSoFar = maxSumHere;
        }

        if(maxSumHere < 0)
        {
            maxSumHere = 0;
        }
    }

    cout << maxSoFar;
    return 0;
}