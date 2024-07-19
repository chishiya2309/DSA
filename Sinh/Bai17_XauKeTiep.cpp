/*
Cho chuỗi S các ký tự số và đưa ra màn hình hoán vị kế tiếp của các ký tự số đó.

Ví dụ : với S = "123" thì xâu kế tiếp là "132", S = "1779" thì xâu kế tiếp là "1797"
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    if(next_permutation(s.begin(), s.end()))
    {
        cout << s;
    }else {
        cout << "NOT EXIST";
    }
    return 0;
}