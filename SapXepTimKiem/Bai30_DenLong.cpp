/*
Vanya đi bộ vào ban đêm dọc theo một con đường thẳng dài có độ dài l, được thắp sáng bởi n chiếc đèn lồng. Xét hệ trục tọa độ với điểm đầu của đường phố tương ứng với điểm 0 và điểm cuối của nó tương ứng với điểm l. Khi đó đèn lồng thứ i ở điểm a[i]. Đèn lồng chiếu sáng tất cả các điểm trên đường phố cách nó nhiều nhất là d, trong đó d là một số dương, chung cho tất cả các đèn lồng. Vanya tự hỏi: bán kính ánh sáng tối thiểu d mà những chiếc đèn lồng phải có để thắp sáng cả con phố?

Gợi ý : Sort => Xét 2 đèn lồng đứng cạnh nhau => khoảng cách giữa 2 đèn này sẽ là 2 lần bán kính. Xét cả khoảng cách giữa đèn lồng đầu tiên tới đầu đường (1d) và từ đèn lồng cuối tới cuối đường (d). Chọn ra bán kinh lớn nhất.

Đầu vào
Dòng đầu tiên chứa hai số nguyên n, l (1 ≤ n ≤ 10^5, 1 ≤ l ≤ 10^9) - số lượng đèn lồng và chiều dài đường phố tương ứng. Dòng tiếp theo chứa n số nguyên a[i] (0 ≤ ai ≤ l).

Nhiều đèn lồng có thể được đặt tại cùng một điểm. Đèn lồng có thể nằm ở cuối phố.

Giới hạn
1 ≤ n ≤ 10^5, 1 ≤ l ≤ 10^9

0 ≤ ai ≤ l

Đầu ra
In bán kính ánh sáng tối thiểu d, cần thiết để chiếu sáng cả đường phố.

In ra kết quả với độ chính xác là 10 số sau dấu phây

Ví dụ :
Input 01
Copy
7 15
15 5 3 7 9 14 0
Output 01
Copy
2.5000000000
*/

#include <bits/stdc++.h>

using namespace std;
double min_lantern_radius(int n, int l, vector<int>& positions)
{
    sort(positions.begin(), positions.end());

    double max_radius = max(positions[0], l - positions[n - 1]);

    for(int i = 1; i < n; i++)
    {
        double distance = positions[i] - positions[i - 1];
        max_radius = max(max_radius, distance / 2.0);
    }
    return max_radius;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, l;
    cin >> n >> l;
    vector<int> positions(n);
    for(int i = 0; i < n; i++)
    {
        cin >> positions[i];
    }
    double result = min_lantern_radius(n, l, positions);
    cout << fixed << setprecision(10) << result;
    return 0;
}


