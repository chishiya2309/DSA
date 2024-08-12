/*
28Tech cung cấp cho bạn N hình chữ nhật với chiều dài và chiều rộng là các số nguyên.

Bây giờ hình chữ nhật X sẽ lồng được vào trong hình chữ nhật Y nếu chiều dài của X nhỏ hơn chiều dài của Y và chiều rộng của X cũng nhỏ hơn chiều rộng của Y.

Bây giờ bạn hãy tìm số lượng hình chữ nhật lớn nhất có thể lồng vào nhau từ N hình chữ nhật đã cho

Ví dụ các HCN [2, 3], [5, 4], [6, 7], [6, 4], [8, 9] thì số HCN có thể lồng vào nhau tối đa là 4 gồm [2, 3], [5, 4], [6, 7], [8, 9]

Đầu vào
Dòng 1 là N : số lượng HCN

N dòng tiếp theo mỗi dòng là chiều rộng, dài của 1 HCN

Giới hạn
1<=N<=10^5

Chiều dài, rộng của HCN là số nguyên dương 32 bit

Đầu ra
In ra số lượng HCN lớn nhất có thể lồng vào nhau

Ví dụ :
Input 01
5
2 3
5 4
6 4
6 7
8 9
Output 01
4
*/

#include <bits/stdc++.h>

using namespace std;

struct HCN
{
    int chieuRong, chieuDai;
};

bool cmp(HCN a, HCN b)
{
    if(a.chieuRong != b.chieuRong)
    {
        return a.chieuRong < b.chieuRong;
    }
    return a.chieuDai > b.chieuDai;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    vector<HCN> X(n);
    for(int i = 0; i < n; i++)
    {
        cin >> X[i].chieuRong >> X[i].chieuDai;
    }
    sort(X.begin(), X.end(), cmp);

    vector<int> v;
    for(auto R : X)
    {
        auto it = lower_bound(v.begin(), v.end(), R.chieuDai);
        if(it == v.end())
        {
            v.push_back(R.chieuDai);
        }else {
            *it = R.chieuDai;
        }
    }

    cout << v.size();

    return 0;
}