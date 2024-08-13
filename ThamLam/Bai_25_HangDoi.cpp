/*
Cô bé Anna đi mua sắm cùng mẹ và cô băn khoăn không biết làm thế nào để cải thiện chất lượng dịch vụ.

Có n người trong hàng đợi. Đối với mỗi người, chúng tôi biết thời gian cần thiết t để phục vụ anh ta. Một người sẽ thất vọng nếu thời gian anh ta chờ đợi nhiều hơn thời gian cần thiết để phục vụ anh ta.

Thời gian một người chờ là tổng thời gian tất cả những người đứng trong hàng đợi trước mặt anh ta được phục vụ. Anna nghĩ rằng nếu chúng ta hoán đổi một số người trong hàng đợi, thì chúng ta có thể giảm số người thất vọng.

Giúp Anna tìm ra con số tối đa mà những người không thất vọng có thể đạt được bằng cách hoán đổi những người trong hàng đợi.

Đầu vào
Dòng đầu tiên chứa số N là số người trong hàng đợi

Dòng thứ 2 chứa N số là thời gian cần phục vụ của N người

Giới hạn
1<=N<=10^5

1<=t<=10^9

Đầu ra
In ra đáp án của bài toán

Ví dụ :
Input 01
7
4 3 17 4 5 14 20
Output 01
3
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
    sort(a.begin(), a.end());

    int soNguoi = 1;
    int Time = a[0];

    for(int i = 1; i < n; i++)
    {
        if(a[i] >= Time)
        {
            soNguoi++;
            Time += a[i];
        }
    }

    cout << soNguoi;

    return 0;
}