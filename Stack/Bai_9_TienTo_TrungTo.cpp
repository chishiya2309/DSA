/*
Cho biểu thức S ở dạng tiền tố, hãy biến đổi S về dạng trung tố và in ra màn hình

Đầu vào
Dòng duy nhất chứa xâu S

Giới hạn
1<=len(S)<=1000

Đầu ra
In ra biểu thức trung tố tương ứng

Ví dụ :
Input 01
Copy
-*AB+CD
Output 01
Copy
((A*B)-(C+D))
*/

#include <bits/stdc++.h>

using namespace std;

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

string solve(string s)
{
    stack<string> st;
    for(int i = s.size() - 1; i >= 0; i--)
    {
        if(isOperator(s[i]))
        {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            string tmp = "(" + t1 + s[i] + t2 + ")";
            st.push(tmp);
        }else 
        {
            st.push(string(1, s[i]));
        }
    }
    return st.top();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin >> s;

    cout << solve(s);

    return 0;
}