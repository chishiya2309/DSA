/*
Cho xâu S chỉ bao gồm dấu đóng mở ngoặc, hãy tìm số lượng dấu ngoặc tối thiểu cần phải đổi chiều để tạo thành một xâu hợp lệ.

Đầu vào
Dòng duy nhất chứa xâu S

Giới hạn
Xâu S có độ dài là số chẵn và có không quá 1000 kí tự

Đầu ra
In ra số lượng dấu ngoặc cần phải đổi chiều

Ví dụ :
Input 01
Copy
)))())()()
Output 01
Copy
2
*/

#include <bits/stdc++.h>

using namespace std;

int xuly(string s)
{
    stack<int> st;
    int cnt = 0;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == '(')
        {
            st.push(i);
        }else
        {
            if(st.empty())
            {
                st.push(i);
                cnt++;
            }else
            {
                st.pop();
            }
        }
    }
    cnt += st.size() / 2;
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin >> s;

    cout << xuly(s);

    return 0;
}