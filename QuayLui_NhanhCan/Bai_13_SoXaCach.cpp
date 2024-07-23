/*
Cho số nguyên dương N . Một số nguyên dương K có N chữ số được gọi là số xa cách nếu thỏa mãn:

K không chứa chữ số 0.

Tất cả các chữ số từ 1 đến N đều xuất hiện trong K đúng 1 lần.

Không có hai chữ số liên tiếp nào trong K có hiệu bằng 1.

Đầu vào
1 dòng duy nhất chứa số nguyên dương N

Giới hạn
3<=N<=9

Đầu ra
In ra các số thỏa mãn theo thứ tự tăng dần

Ví dụ :
Input 01
Copy
4
Output 01
Copy
2413
3142
*/

#include <bits/stdc++.h>

using namespace std;
int n, x[10];
void khoitao()
{
    for(int i = 1; i <= n; i++)
    {
        x[i] = i;
    }
}
bool check()
{
    for(int i = 2; i <= n; i++)
    {
        if(abs(x[i] - x[i - 1]) == 1)
        {
            return false;
        }
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    khoitao();
    do
    {
        if(check())
        {
            for(int i = 1; i <= n; i++)
            {
                cout << x[i];
            }
            cout << endl;
        }
    } while (next_permutation(x + 1, x + n + 1));
    
    return 0;
}