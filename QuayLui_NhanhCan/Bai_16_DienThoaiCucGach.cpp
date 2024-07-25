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
string d[10];
char x[10];
void xuly()
{
    d[2] = "abc";
    d[3] = "def";
    d[4] = "ghi";
    d[5] = "jkl";
    d[6] = "mno";
    d[7] = "pqrs";
    d[8] = "tuv";
    d[9] = "wxyz";
}
void Try(int i)
{
    int num = s[i] - '0';
    for(char c : d[num])
    {
        x[i] = c;
        if(i == n)
        {
            for(int i = 1; i <= n; i++)
            {
                cout << x[i];
            }
            cout << " ";
        }else {
            Try(i + 1);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    xuly();
    cin >> s;
    sort(s.begin(), s.end());
    n = s.size();
    s = "0" + s;
    Try(1);
    return 0;
}