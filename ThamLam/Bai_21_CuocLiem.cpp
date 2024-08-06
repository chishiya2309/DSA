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

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b;
    cin >> a >> b;
    if(a >= 2 * b)
    {
        cout << b;
    }else if(b >= 2 * a)
    {
        cout << a;
    }else 
    {
        cout << (a + b) / 3;
    }
    return 0;
}