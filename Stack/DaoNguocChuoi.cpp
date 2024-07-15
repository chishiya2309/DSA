/*
Viết hàm để đảo ngược một chuỗi ký tự sử dụng cấu trúc dữ liệu stack.
*/

#include<bits/stdc++.h>
using namespace std;
string daoNguoc(string s)
{
    stack<char> res;
    for(char c : s)
    {
        res.push(c);
    }

    string ans = "";
    while(!res.empty())
    {
        ans += res.top();
        res.pop();
    }
    return ans;
}
signed main()
{
    string s;
    getline(cin, s);
    string res = daoNguoc(s);
    cout << res;
}