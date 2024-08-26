#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin >> s;

    stack<char> st;
    for(char c : s)
    {
        if(c == '(' || c == '{' || c == '[')
        {
            st.push(c);
        }else 
        {
            if(st.empty())
            {
                cout << "NO";
                return 0;
            }

            char top = st.top();
            st.pop();
            if((c == ')' && top != '(') || 
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                    cout << "NO";
                    return 0;
            }   
        }
    }

    if(st.empty())
    {
        cout << "YES";
    }else 
    {
        cout << "NO";
    }

    return 0;
}
