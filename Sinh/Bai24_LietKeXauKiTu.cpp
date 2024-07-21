/*
Cho chữ cái c in hoa và số nguyên K

Hãy tìm cách liệt kê tất cả các xâu có K ký tự khác nhau được tạo ra bởi các chữ cái tính từ "A" đến ký tự c.

Các ký tự trong xâu kết quả có thể được lặp lại, xem ví dụ mẫu để rõ hơn.

Đầu vào
Chữ cái c và K

Giới hạn
'A' < c <='G'

0 < K < (c – 'A')

Đầu ra
Ghi ra lần lượt các xâu ký tự kết quả theo thứ tự từ điển trên từng dòng.

Ví dụ :
Input 01
Copy
C 2
Output 01
Copy
AA
AB
AC
BA
BB
BC
CA
CB
CC
*/

#include <bits/stdc++.h>

using namespace std;
char c;
int k;
char x[10];
bool final = false;
void khoitao()
{
    for(int i = 1; i <= k; i++)
    {
        x[i] = 'A';
    }
}
void sinh()
{
    int i = k;
    while(i >= 1 && x[i] == c)
    {
        i--;
    }
    if(i == 0)
    {
        final = true;
    }else {
        x[i]++;
        for(int j = i + 1; j <= k; j++)
        {
            x[j] = 'A';
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> c >> k;
    khoitao();
    while(!final)
    {
        for(int i = 1; i <= k; i++)
        {
            cout << x[i];
        }
        cout << endl;
        sinh();
    }
    return 0;
}