/*
Nhà Tèo ở gần bờ sông, trên bờ sông có trồng N cây phi lao, tuy nhiên có những cây không thể sống được do thời tiết khắc nghiệt của mùa đông miền Bắc. Một ngày nọ Tèo đi dọc bờ sông và tự hỏi, liệu rằng có thể tìm được K cây phi lao con còn sống liên tiếp dọc bờ sông hay không. Có thể sẽ không tồn tại K cây phi lao con còn sống liên tiếp, vì thế Tèo sẽ chuyển những cây phi lao con còn sống ở những ô khác để tạo ra một dãy các cây phi lao sống liên tiếp. Bạn hãy giúp Tèo di chuyển ít nhất cây phi lao nhất có thể, hoặc xác định rằng không thể di chuyển các cây phi lao còn sống lại gần nhau để tạo ra K cây phi lao liên tiếp còn sống.

Đầu vào
• Dòng 1 là N và K

• Dòng 2 mô tả N cây phi lao, 0 tương ứng với cây phi lao chết, 1 tương ứng với cây phi lao sống.

Giới hạn
• 1<=K<=N<=10^6

Đầu ra
In ra số cây phi lao ít nhất cần di chuyển hoặc in ra -1 nếu không thể tạo ra 1 dãy K cây phi lao còn sống.

Ví dụ :
Input 01
11 3
0 0 0 0 1 0 1 0 0 0 1
Output 01
1
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int sum = 0;
    for(int &x : a)
    {
        cin >> x;
        sum += x;
    }

    if(sum < k)
    {
        cout << -1;
        return 0;
    }
    int dem = 0;
    for(int i = 0; i < k; i++)
    {
        dem += a[i];
    }

    int maxcnt = dem;
    for(int i = k; i < n; i++)
    {
        dem += a[i];
        dem -= a[i - k];
        maxcnt = max(maxcnt, dem);
    }

    cout << k - maxcnt;
    return 0;
}