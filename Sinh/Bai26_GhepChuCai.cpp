/*
Trong 8 chữ cái Tiếng Anh đầu tiên (ABCDEFGH) thì có 2 nguyên âm là A và E, còn lại là phụ âm. Người ta muốn ghép các chữ cái bắt đầu từ chữ cái A cho đến chữ cái c (D <= c <= H) sao cho mỗi chữ cái được sử dụng đúng một lần và xâu kết quả không có nguyên âm nào bị kẹp giữa bởi hai phụ âm. Hãy liệt kê các xâu thỏa mãn theo thứ tự từ điển.

Đầu vào
Chỉ có một dòng ghi chữ cái c

Giới hạn
'D' <= c <= 'H'

Đầu ra
Liệt kê các xâu thỏa mãn, mỗi xâu trên một dòng.

Ví dụ :
Input 01
Copy
D
Output 01
Copy
ABCD
ABDC
ACBD
ACDB
ADBC
ADCB
BCDA
BDCA
CBDA
CDBA
DBCA
DCBA
*/

#include <bits/stdc++.h>

using namespace std;
vector<char> c;
bool nguyenAm(char c)
{
    if(c == 'A' || c == 'E')
    {
        return true;
    }
    return false;
}
bool check()
{
    for(int i = 1; i < c.size() - 1; i++)
    {
        if(nguyenAm(c[i]) && !nguyenAm(c[i - 1]) && !nguyenAm(c[i + 1]))
        {
            return false;
        }
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    char a;
    cin >> a;

    int n = (int)a - 64;

    c.resize(n);

    for(int i = 0; i < n; i++)
    {
        c[i] = 'A' + i;
    }
    do
    {
        if(check())
        {
            for(int i = 0; i < n; i++)
            {
                cout << c[i];
            }
            cout << endl;
        }
    } while (next_permutation(c.begin(), c.end()));
    return 0;
}

