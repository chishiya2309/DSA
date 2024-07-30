/*
Cho xâu kí tự S gồm N chữ cái khác nhau, hãy liệt kê tổ hợp lặp chập K của N kí tự trên và in ra theo thứ tự từ điển tăng dần.

Đầu vào
• Dòng 1 chứa 2 số nguyên N và K

• Dòng 2 chứa xâu S

Giới hạn
1<=K<=N<=15

Đầu ra
• In ra đáp án của bài toán

Ví dụ :
Input 01
4 2
ABCD
Output 01
AA
AB
AC
AD
BB
BC
BD
CC
CD
DD
*/

#include <bits/stdc++.h>

using namespace std;
int n, k;
string s;
void Try(string x, int pos)
{
    if(x.size() == k)
    {
        cout << x << endl;
        return;
    }
    for(int i = pos; i < n; i++)
    {
        Try(x + s[i], i);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    cin >> s;
    sort(s.begin(), s.end());
    Try("", 0);
    return 0;
}