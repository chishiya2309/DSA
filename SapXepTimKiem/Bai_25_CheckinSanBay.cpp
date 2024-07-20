/*
Tại sân bay, mọi người đang làm thủ tục để check in. Có tất cả N vị khách. Vị khách thứ i tới làm thủ tục tại thời điểm T[i] và cần D[i] thời gian để check in xong. Các bạn hãy xác định xem thời điểm nào tất cả các vị khách làm xong thủ tục để lên máy bay?

Gợi ý : Sắp xếp theo thời gian đến check in tăng dần, đối với mỗi khách hàng bạn cần tìm ra thời gian mà anh ta thực sự check in = max(thời gian đến check in, thời gian người trước đó check in xong)

Đầu vào
Dòng đầu tiên là số nguyên dương N

N dòng tiếp theo, mỗi dòng gồm 2 số nguyên cho biết thời điểm đến của vị khách thứ i và thời gian vị khách này làm xong thủ tục check in.

Giới hạn
1<=N<=10^5

1<=T[i], D[i]<=10^6

Đầu ra
In ra đáp án tìm được.

Ví dụ :
Input 01
Copy
3
2 1
8 3
5 7
Output 01
Copy
15
Giải thích :
Người thứ 1 đến lúc 2h và làm thủ tục hết 1h => 3h xong Người thứ 2 đến lúc 5h và làm thủ tục hết 7h => 12h xong Người thứ 3 đến lúc 8h nhưng người thứ 2 12h mới làm xong nên bắt đầu làm từ 12h => 15h xong
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end(), cmp);

    ll currentTime = 0;
    for (int i = 0; i < n; i++) {
        currentTime = max(currentTime, (ll)v[i].first);
        currentTime += v[i].second;
    }

    cout << currentTime << endl;
    return 0;
}
