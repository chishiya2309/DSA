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

void solve(string s, int k)
{
    stack<pair<char, int>> st;
    for(int i = 0; i < s.size(); i++)
    {
        if(st.size() && s[i] == st.top().first && st.top().second == k - 1)
        {
            st.pop();
        }else 
        {
            if(!st.empty() && s[i] == st.top().first)
            {
                pair<char, int> t = st.top();
                st.pop();
                t.second++;
                st.push(t);
            }else
            {
                st.push({s[i], 1});
            }
        }
    }

    if(st.empty())
    {
        cout << "EMPTY";
        return;
    }

    stack<pair<char, int>> st2;
    while(!st.empty())
    {
        st2.push(st.top());
        st.pop();
    }

    while(!st2.empty())
    {
        char c = st2.top().first;
        int freq = st2.top().second;
        st2.pop();
        for(int i = 0; i < freq; i++)
        {
            cout << c;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin >> s;

    int k;
    cin >> k;

    solve(s, k);

    return 0;
}