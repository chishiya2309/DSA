/*
Cho một xâu kí tự chỉ bao gồm dấu đóng mở ngoặc tròn.

Hãy tìm số lượng dấu đóng mở ngoặc cần thêm tối thiểu để tạo thành một xâu cân bằng, bạn có thể thêm các kí tự đóng mở ngoặc vào bất kì vị trí nào của xâu.

Đầu vào
Xâu kí tự S trên 1 dòng

Giới hạn
1<=len(S)<=10000

Đầu ra
In ra số lượng dấu ngoặc cần bổ sung để xâu cân bằng

Ví dụ :
Input 01
Copy
))))()
Output 01
Copy
4
*/

#include <bits/stdc++.h>

using namespace std;

int xuly(string s)
{
    stack<int> st;
    int n = s.length();
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == '(')
        {
            st.push(i);
        }else if(st.empty()) cnt++;
        else
        {
            st.pop();
        }
    }
    cnt += st.size();
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