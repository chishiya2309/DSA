/*
Cho xâu kí tự S, nhiệm vụ của bạn là hãy kiểm tra xem có thể sắp đặt lại các kí tự trong xâu sao cho không có 2 ký tự liền kề nào giống nhau được hay không ?

Ví dụ : S = "abaab" có thể sắp đặt lại thành "ababa" và không có 2 ký tự liền kề nào giống nhau.

Đầu vào
Dòng duy nhất chứa xâu S

Giới hạn
1<=len(S)<=10^6

Đầu ra
Nếu có thể sắp đặt lại xâu S theo yêu cầu thì in ra YES, ngược lại in ra NO.

Ví dụ :
Input 01
Copy
abbaa
Output 01
YES
Input 02
aaab
Output 02
Copy
NO
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int n = s.size();
    map<char, int> char_count;
    int maxFreq = INT_MIN;
    for(char c : s)
    {
        char_count[c]++;
        maxFreq = max(maxFreq, char_count[c]);
    }
    if(n % 2 != 0)
    {
        n++;
    }
    if(maxFreq > n /2)
    {
        cout << "NO";
    }else {
        cout << "YES";
    }
    return 0;
}