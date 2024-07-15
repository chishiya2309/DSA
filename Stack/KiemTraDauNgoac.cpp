/*
Viết hàm kiểm tra xem các dấu ngoặc trong một biểu thức có được đóng mở đúng cách không. Các dấu ngoặc cần kiểm tra bao gồm: (), {}, [].
*/


#include<bits/stdc++.h>
using namespace std;
bool isValidExpression(string s)
{
    stack<char> stack;
    map<char, char> brackets = {{'(', ')'}, {'{', '}'}, {'[', ']'}};
    for(char c : s)
    {
        if(brackets.find(c) != brackets.end())
        {
            stack.push(c);
        }else if(!stack.empty() && brackets[stack.top()] == c)
        {
            stack.pop();
        }else if(brackets.find(c) == brackets.end())
        {
            return false;
        }
    }
    return stack.empty();
}
signed main()
{
    string s;
    cin >> s;
    if(isValidExpression(s))
    {
        cout << "YES";
    }else {
        cout << "NO";
    }
    return 0;
}