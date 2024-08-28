#include <bits/stdc++.h>

using namespace std;

int xuly(string s)
{
    stack<int> st;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == '(')
        {
            st.push(i);
        }else if(s[i] == ')')
        {
            int m = st.top();
            st.pop();
            if(s[i - 1] == ')' && s[m + 1] == '(' || i - m == 2)
            {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin >> s;

    if(xuly(s))
    {
        cout << "YES";
    }else
    {
        cout << "NO";
    }

    return 0;
}