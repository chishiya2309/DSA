/*
Có n vé xem hòa nhạc có sẵn, mỗi vé có một mức giá nhất định. Sau đó, m khách hàng lần lượt đến. Mỗi khách hàng thông báo mức giá tối đa mà họ sẵn sàng trả cho một vé và sau đó, họ sẽ nhận được một vé với mức giá gần nhất có thể sao cho không vượt quá mức giá tối đa.

Gợi ý : Dùng multiset lưu lại các vé, dùng hàm upperbound sau đó dịch trái 1 vị trí đề tìm được vé lớn nhất <= mức giá tối đa. Nhớ xóa vé đó đi sau khi sử dụng. Khi dùng hàm upperbound thì sử dụng cú pháp ms.upperbound(x) thay vì upperbound(ms.begin(), ms.end(), x) sẽ chạy nhanh hơn

Đầu vào
Dòng đầu tiên chứa các số nguyên n và m: số lượng vé và số lượng khách hàng.

Dòng tiếp theo ghi n số nguyên h1, h2,…, hn : giá của từng vé.

Dòng cuối cùng chứa m số nguyên t1, t2,…, tm: giá tối đa cho mỗi khách hàng theo thứ tự họ đến.

Giới hạn
1≤ n, m ≤2.10^5

1≤ ti, hi ≤10^9

Đầu ra
In, cho mỗi khách hàng, giá mà họ sẽ trả cho vé của họ. Sau đó, vé không thể được mua lại lần nữa. Nếu khách hàng không lấy được vé nào, hãy in -1.

Ví dụ :
Input 01
Copy
5 3
5 3 7 8 5
4 8 3
Output 01
Copy
3
8
-1
*/

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    multiset<int> h;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        h.insert(x);
    }
    vector<int> t(m);
    for(int i = 0; i < m; i++)
    {
        cin >> t[i];
    }
    for(int i = 0; i < m; i++)
    {
        auto it = h.upper_bound(t[i]);
        if(it == h.begin())
        {
            cout << -1 << endl;
        }else {
            it--;
            cout << *it << endl;
            h.erase(it);
        }
    }
    return 0;
}