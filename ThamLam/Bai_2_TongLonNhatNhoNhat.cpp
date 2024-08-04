/*
rong một buổi học toán, giáo viên viết 2 số nguyên, A và B, và yêu cầu Tèo thực hiện phép cộng. Tèo không bao giờ tính toán sai, nhưng thỉnh thoảng cậu ta chép các con số một cách không chính xác. Lỗi duy nhất của là ghi nhầm '5' thành '6' hoặc số '6' thành số '5'. Cho hai số, A và B, tính tổng nhỏ nhất và lớn nhất mà Tèo có thể nhận được.

Đầu vào
Dòng duy nhất chứa 2 số A và B

Giới hạn
1<=A<=B<=10^16

Đầu ra
In ra tổng lớn nhất, nhỏ nhất tìm được

Ví dụ :
Input 01
607 53
Output 01
670 560
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll solveMin(ll a)
{
    string tmp = to_string(a);
    for(int i = 0; i < tmp.size(); i++)
    {
        if(tmp[i] == '6')
        {
            tmp[i] = '5';
        }
    }
    return stoll(tmp);
}

ll solveMax(ll a)
{
    string tmp = to_string(a);
    for(int i = 0; i < tmp.size(); i++)
    {
        if(tmp[i] == '5')
        {
            tmp[i] = '6';
        }
    }
    return stoll(tmp);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a, b;
    cin >> a >> b;
    ll x, y, z, t;
    x = solveMax(a);
    y = solveMax(b);
    z = solveMin(a);
    t = solveMin(b);
    cout << x + y << " " << z + t;
    return 0;
}