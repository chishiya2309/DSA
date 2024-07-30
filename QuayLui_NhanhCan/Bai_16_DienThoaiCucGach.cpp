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
void solve()
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
void Try(int pos)
{
    int num = s[pos] - '0';
    for(char c : d[num])
    {
        x[pos] = c;
        if(pos == n)
        {
            for(int j = 1; j <= n; j++)
            {
                cout << x[j];
            }
            cout << " ";
        }else {
            Try(pos + 1);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    cin >> s;
    n = s.size();
    sort(s.begin(), s.end());
    s = "0" + s;
    Try(1);
    return 0;
}