/*
Nhiệm vụ của bạn là hãy tìm số nhỏ nhất có K chữ số và có tổng các chữ số là S. Nếu không thể tìm được số thỏa mãn yêu cầu thì in ra -1.

Đầu vào
Dòng duy nhất chứa 2 số S và K

Giới hạn
1<=S,D<=10^6

Đầu ra
In ra số nhỏ nhất có K chữ số và có tổng bằng S hoặc in ra -1 nếu không thể tìm thấy.

Ví dụ :
Input 01
12 11
Output 01
10000000029
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int s, k;
    cin >> s >> k;
    if(9 * k < s || (s == 0 && k > 1))
    {
        cout << -1;
        return 0;
    }
    string ans;
    while(k--)
    {
        if(s > 9)
        {
            ans = "9" + ans;
            s -= 9;
        }else
        {
            if(k == 0)
            {
                ans = to_string(s) + ans;
            }else {
                ans = to_string(s - 1) + ans;
            }
            s = 1;
        }
    }
    cout << ans;
    return 0;
}