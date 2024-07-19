/*
Nhiệm vụ của bạn là hãy liệt kê các xâu nhị phân thuận nghịch có độ dài n theo thứ tự từ điển.
Đầu vào
Dòng duy nhất chứa số nguyên dương n.

Giới hạn
1<=n<=15

Đầu ra
In ra các xâu thuận nghịch theo thứ tự từ điển

Ví dụ :
Input 01
4
Output 01
0000
0110
1001
1111
*/

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
string s;
bool final = false;

void sinh()
{
    int i = s.size() - 1;
    while(i >= 0 && s[i] == '1')
    {
        s[i] = '0';
        i--;
    }
    if(i == -1)
    {
        final = true;
    }else {
        s[i] = '1';
    }
}

bool check()
{
    string tmp = s;
    reverse(tmp.begin(), tmp.end());
    return tmp == s;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    s = string(n, '0');
    vector<string> v;
    while(!final)
    {
        if(check())
        {
            v.push_back(s);
        }
        sinh();
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
    return 0;
}