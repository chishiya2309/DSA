/*
Cho biểu thức chỉ bao gồm dấu '(' và ')', nhiệm vụ của bạn là hãy sinh ra các xâu biểu thức cân bằng, ví dụ về biểu thức cân bằng (), ()()(), ((())), (())((())), ví dụ về biểu thức không cân bằng (()))(, ()()))

Đầu vào
Dòng duy nhất chứa số nguyên dương N là độ dài của biểu thức

Giới hạn
2<=N<=14, N là số chẵn

Đầu ra
In ra các biểu thức cân bằng theo thứ tự từ điển. Nếu không tồn tại biểu thức hợp lệ có độ dài N thì in ra NOT FOUND.

Ví dụ :
Input 01
4
Output 01
(())
()()
*/

#include <bits/stdc++.h>

using namespace std;
int n;
string s;
bool final = false;
void sinh()
{
    
    int i = s.size() - 1;
    while(i >= 0 && s[i] == ')')
    {
        s[i] = '(';
        i--;
    }
    if(i == -1)
    {
        final = true;
    }else {
        s[i] = ')';
    }
}
bool check()
{
    stack<char> st;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '(')
        {
            st.push(s[i]);
        }else {
            if(st.empty())
            {
                return false;
            }else {
                st.pop();
            }
        }
    }
    return st.empty();
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    s = string(n, '(');
    bool checkfinal = false;
    while(!final)
    {
        if(check())
        {
            checkfinal = true;
            cout << s << endl;
        }
        sinh();
    }
    if(!checkfinal)
    {
        cout << "NOT FOUND";
    }
    return 0;
}