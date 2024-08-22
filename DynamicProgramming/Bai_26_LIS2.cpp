/*
Bạn được cung cấp một mảng chứa n số nguyên. Nhiệm vụ của bạn là xác định dãy con dài nhất tăng dần trong mảng, tức là dãy con dài nhất mà mọi phần tử đều lớn hơn phần tử trước đó. Một dãy con là một dãy có thể được dẫn xuất từ mảng bằng cách xóa một số phần tử mà không làm thay đổi thứ tự của các phần tử còn lại.

Đầu vào
Dòng đầu tiên chứa số nguyên n: kích thước của mảng.

Sau đó có n số nguyên x1, x2,…, xn: nội dung của mảng.

Giới hạn
1≤n≤2⋅10^5

1≤xi≤10^9

Đầu ra
In ra chiều dài của dãy con tăng dài nhất

Ví dụ :
Input 01
Copy
6
1 2 4 1 5 2
Output 01
Copy
4
*/

#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> a;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    a.resize(n);

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