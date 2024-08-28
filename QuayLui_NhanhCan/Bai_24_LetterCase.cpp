/*
Cho xâu kí tự S chỉ bao gồm chữ cái và chữ số, bạn có thể thay đổi các chữ cái trong xâu thành kiểu in hoa hoặc in thường tương ứng của nó nhưng không được thay đổi vị trí ban đầu. Bạn hãy liệt kê mọi xâu khác nhau có thể tạo thành bằng cách trên và liệt kê theo thứ tự từ điển tăng dần.

Đầu vào
• Dòng duy nhất chứa xâu S

Giới hạn
• 1<=len(S)<=12

Đầu ra
In ra đáp án của bài toán

Ví dụ :
Input 01
28TeCH
Output 01
28TECH
28TECh
28TEcH
28TEch
28TeCH
28TeCh
28TecH
28Tech
28tECH
28tECh
28tEcH
28tEch
28teCH
28teCh
28tecH
28tech
*/

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

string s;
int n;

void Try(int i, string x)
{
    if(i == n)
    {
        cout << x << endl;
        return;
    }

    if(isalpha(s[i]))
    {
        Try(i + 1, x + (char)toupper(s[i]));
        Try(i + 1, x + (char)tolower(s[i]));
    }else
    {
        Try(i + 1, x + s[i]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> s;
    n = s.size();

    Try(0, "");

    return 0;
}