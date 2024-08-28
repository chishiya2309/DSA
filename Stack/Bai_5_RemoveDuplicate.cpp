/*
Cho một xâu kí tự S chỉ bao gồm kí tự in thường, nhiệm vụ của bạn là xóa các kí tự liền kề giống nhau khỏi xâu S.

Ví dụ xâu aabbccc sau khi xóa các kí tự liền kề sẽ thành c, xâu abba sau khi xóa các kí tự liền kề sẽ thành xâu rỗng.

Đầu vào
Dòng duy nhất chứa xâu kí tự S

Giới hạn
1<=len(S)<=10000

Đầu ra
In ra xâu S sau khi xóa các kí tự liền kề giống nhau, nếu xâu sau khi xóa rỗng thì in ra EMPTY.

Ví dụ :
Input 01
Copy
dddbbabcb
Output 01
Copy
dabcb
*/

#include <bits/stdc++.h>

using namespace std;

void solve(string s)
{
    stack<char> st;
    for(int i = 0; i < s.size(); i++)
    {
        if(st.size() && s[i] == st.top())
        {
            st.pop();
        }else 
        {
            st.push(s[i]);
        }
    }

    if(st.empty())
    {
        cout << "EMPTY";
        return;
    }

    stack<char> st2;
    while(!st.empty())
    {
        st2.push(st.top());
        st.pop();
    }

    while(!st2.empty())
    {
        cout << st2.top();
        st2.pop();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin >> s;

    solve(s);

    return 0;
}