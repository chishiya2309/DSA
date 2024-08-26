#include <bits/stdc++.h>

using namespace std;

bool toanTu(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

string solve(string s)
{
    stack<string> stack;

    for(int i = s.size() - 1; i >= 0; i--)
    {
        char c = s[i];

        if(toanTu(c))
        {
            string tmp1 = stack.top();
            stack.pop();
            string tmp2 = stack.top();
            stack.pop();

            string res = "(" + tmp1 + c + tmp2 + ")";
            stack.push(res);
        }else 
        {
            stack.push(string(1, c));
        }

    }
    return stack.top();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin >> s;

    string res = solve(s);
    cout << res;

    return 0;
}