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
#define endl '\n'
using namespace std;
char c;
int k;
string s;
bool final = false;
void sinh()
{
    int i = k - 1;
    while(i >= 0 && s[i] == c)
    {
        i--;
    }
    if(i == -1)
    {
        final = true;
    }else {
        s[i]++;
        for(int j = i + 1; j < k; j++)
        {
            s[j] = 'A';
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> c >> k;
    s = string(k, 'A');
    while(!final)
    {
        cout << s << endl;
        sinh();
    }
    return 0;
}