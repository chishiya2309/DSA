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
Copy
28TeCH
Output 01
Copy
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

using namespace std;

string s;

void Try(int index, string tmp)
{
    if(tmp.size() == s.size())
    {
        cout << tmp << endl;
        return;
    }

    if(isalpha(s[index]))
    {
        Try(index + 1, tmp + (char)toupper(s[index]));
        Try(index + 1, tmp + (char)tolower(s[index]));
    }else 
    {
        Try(index + 1, tmp + s[index]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> s;
    
    Try(0, "");

    return 0;
}