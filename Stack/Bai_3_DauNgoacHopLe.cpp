/*
Cho một xâu kí tự chỉ bao gồm các kí tự '(', ')', '{', '}', ']', "]", hãy xác định xem các dấu ngoặc trong xâu có cân bằng hay không.

Một vài ví dụ về xâu cân bằng : ((())), {{((()))}}[][][], (())(()())...

Đầu vào
Xâu kí tự S trên 1 dòng

Giới hạn
1<=len(S)<=10000

Đầu ra
In ra YES hoặc NO nếu xâu kí tự cân bằng hoặc không.

Ví dụ :
Input 01
Copy
((((()))))
Output 01
Copy
YES
*/

#include <bits/stdc++.h>

using namespace std;

string s;

bool isOpen(char c)
{
    return (c == '(' || c == '{' || c == '[');
}

bool checkCanBang(string s)
{
    stack<int> st;
    for(char c : s)
    {
        if(isOpen(c))
        {
            st.push(c);
        }else 
        {
            if(st.empty())
            {
                return false;
            }

            char tmp = st.top();
            st.pop();
            if((c == '}' && tmp != '{')
            || (c == ']' && tmp != '[')
            || (c == ')' && tmp != '(')
            )
            {
                return false;
            }
        }
    }
    return st.empty();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;
    if(checkCanBang(s))
    {
        cout << "YES";
    }else 
    {
        cout << "NO";
    }

    return 0;
}