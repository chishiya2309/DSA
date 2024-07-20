/*
Cho mảng A[] gồm n phần tử. Nhiệm vụ của bạn là hãy sắp đặt lại các phần tử của mảng sao cho các số 0 để ở cuối cùng, các phần tử khác 0 được bảo toàn thứ tự trước sau.

Ví dụ : A[] = {28, 2, 1, 2, 0, 0, 0, 3, 6} ta có kết quả A[] = {28, 2, 1, 2, 3, 6, 0, 0, 0}.

Đầu vào
Dòng đầu tiên đưa vào n là số phần tử của mảng A[]

Dòng kế tiếp đưa vào n số A[i] của mảng

Giới hạn
1≤ N ≤10^6

1≤ A[i] ≤10^6.

Đầu ra
In ra kết quả trên một dòng

Ví dụ :
Input 01
Copy
28 1 1 2 0 0 0 3 6
Output 01
28 1 1 2 3 6 0 0 0
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i] != 0)
        {
            cout << a[i] << " ";
        }else {
            cnt++;
            continue;
        }
    }
    for(int i = 0; i < cnt; i++)
    {
        cout << 0 << " ";
    }
    return 0;
}
