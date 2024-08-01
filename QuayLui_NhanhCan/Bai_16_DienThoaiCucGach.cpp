/*
Cho xâu kí tự S chỉ bao gồm các số từ 2 tới 9, mỗi chữ số này trên bàn phím của điện thoại cục gạch tương ứng với 3 chữ cái như trong hình bên dưới. Bạn hãy in ra các xâu kí tự có thể tạo thành bằng cách ấn mỗi chữ số trong xâu S đúng 1 lần. Bạn hãy in ra các xâu kết quả theo thứ tự từ điển tăng dần.

Đầu vào
• Dòng duy nhất chứa xâu S

Giới hạn
• 2<=len(S)<=9

• Các kí tự trong S là khác nhau

Đầu ra
• In ra các xâu thỏa mãn

Ví dụ :
Input 01
23
Output 01
ad ae af bd be bf cd ce cf
*/

#include <bits/stdc++.h>

using namespace std;
string s;
int n;
string button[10];
char x[10];
void xuly()
{
    button[2] = "abc";
    button[3] = "def";
    button[4] = "ghi";
    button[5] = "jkl";
    button[6] = "mno";
    button[7] = "pqrs";
    button[8] = "tuv";
    button[9] = "wxyz";
}
void Try(int i)
{
    int num = s[i] - '0';
    for(char c : button[num])
    {
        x[i] = c;
        if(i == n)
        {
            for(int j = 1; j <= n; j++)
            {
                cout << x[j];
            }
            cout << " ";
        }else
        {
            Try(i + 1);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    xuly();
    cin >> s;
    n = s.size();
    sort(s.begin(), s.end());
    s = "0" + s;
    Try(1);
    return 0;
}