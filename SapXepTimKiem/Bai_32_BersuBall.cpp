/*
Đại học Bang Berland đang tổ chức một buổi khiêu vũ trong lễ kỷ niệm 100500 năm thành lập! n các chàng trai và m cô gái đã bận rộn luyện tập các động tác nhảy múa. Chúng tôi biết rằng một số cặp nam và nữ sẽ được mời tham dự vũ hội. Tuy nhiên, kỹ năng khiêu vũ của các đối tác trong mỗi cặp khác nhau nhiều nhất là một đơn vị. Đối với mỗi cậu bé, chúng tôi biết kỹ năng nhảy của cậu ấy. Tương tự, đối với mỗi cô gái, chúng tôi biết kỹ năng khiêu vũ của cô ấy. Viết mã xác định số cặp lớn nhất có thể được hình thành từ n trai và m gái.

Đầu vào
Dòng đầu tiên chứa số nguyên n và m (1 ≤ n, m ≤ 10^5) - số bé trai và số bé gái.

Dòng thứ hai chứa dãy a1, a2, ...an

Dòng thứ ba chứa dãy b1, b2, ..., bm

Giới hạn
1 ≤ n, m ≤ 10^5

0 ≤ ai ≤ 10^5

0 ≤ bj ≤ 10^5

Đầu ra
In một số duy nhất - số cặp tối đa được yêu cầu.

Ví dụ :
Input 01
4 5
1 4 6 2
5 1 5 7 9
Output 01
3
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for(int &x : a)
    {
        cin >> x;
    }

    vector<int> b(m);
    for(int &x : b)
    {
        cin >> x;
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int cnt = 0;
    int i = 0, j = 0;
    while(i < n && j < m)
    {
        if(abs(b[j] - a[i]) <= 1)
        {
            cnt++;
            i++;
            j++;
        }else if(b[j] > a[i])
        {
            i++;
        }else {
            j++;
        }
    }
    cout << cnt;
    return 0;
}
