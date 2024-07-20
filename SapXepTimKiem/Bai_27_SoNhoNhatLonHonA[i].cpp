/*
Cho mảng A[] gồm n phần tử. Nhiệm vụ của bạn là tìm giá trị nhỏ nhất (phải thuộc mảng A[]) lớn hơn A[i] (i=0, 1, 2,.., n-1). Đưa ra "_" nếu A[i] không có phần tử lớn hơn nó.

Ví dụ : với mảng A[] = {13, 6, 7, 12}, ta có kết quả là { _ , 7 . 12, 13}.

Đầu vào
Dòng đầu tiên đưa vào n là số phần tử của mảng A[]

Dòng kế tiếp đưa vào n số A[i] của mảng

Giới hạn
1≤ N ≤10^5

1≤ A[i] ≤10^5

Đầu ra
Đưa ra kết quả trên 1 dòng

Ví dụ :
Input 01
9
6 3 9 8 10 2 1 15 7
Output 01
7 6 10 9 15 3 2 _ 8
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

    set<int> s(a.begin(), a.end());

    for(int x : a)
    {
        auto it = s.upper_bound(x);
        if(it != s.end())
        {
            cout << *it << " ";
        }else {
            cout << "_ ";
        }
    }
    return 0;
}
