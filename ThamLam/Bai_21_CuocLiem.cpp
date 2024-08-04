/*
Tèo đang chơi một game là nông trại vui vẻ, để tham gia game nông trại vui vẻ, các game thủ phải sử dụng 2 công vụ là cuốc và liềm. Biết rằng để đổi lấy 1 cái cuốc thì cần 2 đồng xu và 1 kim cương, để đổi lấy 1 cái liềm thì cần 1 đồng xu và 2 kim cương. Hãy xác định tổng số cuốc và liềm lớn nhất mà Tèo có thể đổi được biết rằng Tèo có a đồng xu và b kim cương.

Đầu vào
Dòng duy nhất chứa 2 số a và b

Giới hạn
0<=a,b<=10^9

Đầu ra
In ra đáp án của bài toán

Ví dụ :
Input 01
6 8
Output 01
4
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool canExchange(ll a, ll b, ll x)
{
    return (2 * x <= a + b) && (x <= a) && (x <= b);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll xu, kimCuong;
    cin >> xu >> kimCuong;

    ll left = 0, right = (xu + kimCuong) / 3;
    ll result = 0;

    while(left <= right)
    {
        ll mid = (left + right) / 2;
        if(canExchange(xu, kimCuong, mid))
        {
            result = mid;
            left = mid + 1;
        }else {
            right = mid - 1;
        }
    }
    cout << result;
    return 0;
}