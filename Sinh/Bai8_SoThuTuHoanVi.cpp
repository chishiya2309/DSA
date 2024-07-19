/*
Cho số tự nhiên N và các số từ 1 tới N, bạn được cung cấp một hoán vị của N phần tử các số từ 1 đến N. Nhiệm vụ của bạn là xác định xem hoán vị này là hoán vị thứ bao nhiêu nếu bạn sinh ra tất cả các hoán vị của tập N phần tử theo thuật toán sinh kế tiếp.

Ví dụ với N = 3, thì hoán vị 312 là hoán vị thứ 5.

Gợi ý : Sinh hoán vị như thông thường, mỗi lần sinh 1 cấu hình thì so sánh cấu hình hiện tại vs cấu hình được cho, nếu giống nhau thì in ra số thự tự cấu hình đang xét
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> cmp(n);
    for(int i = 0; i < n; i++)
    {
        cin >> cmp[i];
    }
    vector<int> x(n);
    for(int i = 0; i < n; i++)
    {
        x[i] = i + 1;
    }
    int cnt = 0;
    do
    {
        cnt++;
        if(cmp == x)
        {
            cout << cnt;
            return 0;
        }
    }while(next_permutation(x.begin(), x.end()));
    return 0;
}