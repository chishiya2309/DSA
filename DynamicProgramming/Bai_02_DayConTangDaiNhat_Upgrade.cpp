/*
Cho mảng số nguyên A[] gồm N phần tử, hãy tìm dãy con tăng dài nhất của mảng A.

Đầu vào
Dòng đầu tiên là N

Dòng thứ 2 gồm N phần tử của mảng A

Giới hạn
1<=N<=1000

1<=A[i]<=1000

Đầu ra
In ra độ dài của dãy con tăng dài nhất

Ví dụ :
Input 01
Copy
10
1 1 3 4 2 4 5 5 1 2
Output 01
Copy
4
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

    vector<int> v;
    for(int num : a)
    {
        auto it = lower_bound(v.begin(), v.end(), num);
        if(it == v.end())
        {
            v.push_back(num);
        }else 
        {
            *it = num;
        }
    }

    cout << v.size();

    return 0;
}