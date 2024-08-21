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

void in()
{
    for(int i = 1; i <= k; i++)
    {
        cout << x[i];
    }
    cout << endl;
}

void Try(int i)
{
    for(char j = 'A'; j <= c; j++)
    {
        x[i] = j;
        if(i == k)
        {
            in();
        }else 
        {
            Try(i + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> c >> k;
    Try(1);

    return 0;
}