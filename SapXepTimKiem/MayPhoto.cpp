/*
Kì thì cuối kì môn Triết ở trường đại học 28tech sắp diễn ra. Tèo và bạn bè có ý định sẽ photo phao thi để bán kiếm tiền, hiện tại Tèo và bạn của mình 
đã có bản gốc của phao thi. Theo ước tính của Tèo thì có n bạn sẽ mua phao thi của tèo. Tèo không có ý định bán bản phao gốc của mình 
nên sẽ đi photo n bản nữa để bán, tới quán photo chỉ còn 2 máy photo có thể hoạt động. Trong đó máy photo 1 cần x giây để photo xong phao 
thi cho Tèo, máy thứ 2 cần y giây. Vì muốn nhanh chóng đem phao đi bán nên Tèo muốn nhờ bạn tính hộ là anh ấy cần ít nhất bao nhiêu giây để có thể photo ra n bản khác từ 1 bản gốc ban đầu. Chú ý các máy photo có thể photo từ bản gốc hoặc có thể photo từ bản đã sao đã được in từ bản gốc. 2 máy này có thể hoạt động một cách đồng thời.
*/


#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool check(int n, int x, int y, ll Time)
{
    Time -= min(x, y);
    return (Time / x + Time / y) >= n - 1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x, y;
    cin >> n >> x >> y;
    ll l = 0, r = 1e18;
    ll res = -1;
    while(l <= r)
    {
        ll mid = (l + r) / 2;
        if(check(n, x, y, mid))
        {
            res = mid;
            r = mid - 1;
        }else {
            l = mid + 1;
        }
    }
    cout << res;
    return 0;
}